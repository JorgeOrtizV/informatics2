/*
Suppose we have an array in which exactly one element does not fulfill the heap property. Write
the function fixHeap(int array[], int length) in C which ensures that the array is
a heap again. Use the algorithms from the previous sub tasks to find the element that causes
difficulties and fix it.
*/

#include <stdio.h>
#include <math.h>

int parent(int x){
    return floor((x-1)/2);
}

int left(int x){
    return 2*x+1; // Because index start in 0
}

int right(int x){
    return (2*x)+2;
}

//Follow a DFS approach
int controlMaxHeap(int A[], int s, int length){

    int leftc = left(s);
    
    // Check all the left substructure
    if(leftc<length){
        if(A[leftc]>A[s]){
            return s;
        }
        int leftc_status = controlMaxHeap(A, leftc, length);
        if(leftc_status != -1)
            return leftc_status;
    }
    
    // Check all the right substructure
    int rightc = right(s);
    if(rightc<length){
        if(A[rightc]>A[s]){
            return s;
        }
        int rightc_status = controlMaxHeap(A, rightc, length);
        if(rightc_status!=-1)
            return rightc;

    }

    return -1;

}

// int controlMaxHeap(int array[], int currentIndex, int length) {
//     int leftIndex = left(currentIndex);
//     if (leftIndex < length) {
//         if (array[currentIndex] < array[leftIndex]) {
//             return currentIndex;
//         }
//         int leftViolation = controlMaxHeap(array, leftIndex, length);
//         if (leftViolation != -1) {
//             return leftViolation;
//         }
//     }
//     int rightIndex = right(currentIndex);
//     if (rightIndex < length) {
//         if (array[currentIndex] < array[rightIndex]) {
//             return currentIndex;
//         }
//         int rightViolation = controlMaxHeap(array, rightIndex, length);
//         if (rightViolation != -1) {
//             return rightViolation;
//         }
//     }
//     return -1;
// }

void heapify(int A[], int root, int length){
    int m = root;
    int l = left(root);
    int r = right(root);

    if (l<length && A[l]>A[m])
        m=l;
    if(r<length && A[r]>A[m])
        m=r;

    if(m!=root){
        int tmp = A[root];
        A[root] = A[m];
        A[m] = tmp;
        heapify(A, m, length);
    }

}

void fixMaxHeap(int A[], int pos, int length){
    int p = parent(pos);
    int leftc = left(pos);
    int rightc = right(pos);
    // Given position is bigger than parent
    if(p>=0 && A[p]<A[pos]){
        int tmp = A[p];
        A[p] = A[pos];
        A[pos] = tmp;
        //fixMaxHeap(A, p, length);
    }
    // Given position has a bigger children
    else if(leftc<length && A[leftc]>A[pos]){
        int tmp = A[leftc];
        A[leftc] = A[pos];
        A[pos] = tmp;
        //fixMaxHeap(A, pos, length);
    }
    else if(rightc<length && A[rightc]>A[pos]){
        int tmp = A[rightc];
        A[rightc] = A[pos];
        A[pos] = tmp;
    }
}

// Alternative to above solution
// void fixMaxHeap(int A[], int pos, int length){
//     while(pos!=-1){
//         heapify(A, pos, length);
//         pos = controlMaxHeap(A, 0, length);
//     }
// }

int main(){
    int A[] = {5, 5, 3, 2, 1, 4};
    int length = sizeof(A)/sizeof(A[0]);
    heapify(A, 0, length);
    int status = controlMaxHeap(A, 0, length);
    for(int i=0; i<length;i++)
        printf("%d ", A[i]);
    printf("\n%d\n", status);   

    while(status!=-1){
        fixMaxHeap(A, status, length);
        status = controlMaxHeap(A, 0, length);
    }
    for(int i=0; i<length;i++)
        printf("%d ", A[i]);

    return 0;
}