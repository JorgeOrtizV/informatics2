/*
In the lecture you learned what the criteria for a heap are. Use this knowledge to write the func-
tion controlMaxHeap(int array[], int currentIndex, int length) in C. The
goal of this function is to return -1 if the array fulfills all the criteria that a max heap must
fulfill. Otherwise the index of an element not fulfilling the property should be returned.
Examples:
• [5, 5, 3, 2, 1, 3] should return -1, since no property is violated.
• [5, 5, 3, 2, 1, 4] should return 2, because 4 can’t be a child of 3. Since 2 is the index of the
element with value 3 the number 2 should be returned.
• [5, 5, 3, 2, 1, 6] should return 2, even if there is a conflict between the number 5 at index
0 and the number 6 at index 5, the direct violation of a property is the same as in the
previous example.
*/

#include <stdio.h>
#include <math.h>

int parent(int x){
    return floor(x/2);
}

int left(int x, int length){
    if(2*x < length)
        return 2*x+1; // Because index start in 0
    else
        return NULL;
}

int right(int x, int length){
    if((2*x+1) < length)
        return (2*x)+2; // Because index start in 0
    else
        return NULL;
}

// int maxHeapCondition(int A[], int s, int length){

// }

// Follow a DFS approach
int controlMaxHeap(int A[], int s, int length){

    int leftc = left(s, length);
    int rightc = right(s, length);
    
    // Check all the left substructure
    if(leftc!=NULL){
        if(A[leftc]>A[s]){
            return leftc;
        }
        int leftc_status = controlMaxHeap(A, leftc, length);
        if(leftc_status != -1)
            return leftc_status;
    }
    
    // Check all the right substructure
    if(rightc!=NULL){
        if(A[rightc]>A[s]){
            return rightc;
        }
        int rightc_status = controlMaxHeap(A, rightc, length);
        if(rightc_status!=-1)
            return rightc;

    }

    return -1;

}

int main(){
    int A[] = {5,5,3,2,1,1};
    int length = sizeof(A)/sizeof(A[0]);
    int res = controlMaxHeap(A, 0, length);
    printf("%d", res);
    return 0;
}