/*
Your task is to implement the function heapify(int array[], int currentIndex, int
length) in C. The function should restore the heap property for the desired index and propa-
gate downwards if necessary.
Example:
• When calling heapify with the array [4, 10, 3, 5, 1] of length 5 and the index 0, the function
should rearrange the array to [10, 5, 3, 4, 1].
*/

#include <stdio.h>

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

void heapify(int A[], int root, int length){
    int m = root;
    int l = left(root, length);
    int r = right(root, length);

    if (l!=NULL && A[l]>A[m])
        m=l;
    if(r!=NULL && A[r]>A[m])
        m=r;

    if(m!=root){
        int tmp = A[root];
        A[root] = A[m];
        A[m] = tmp;
        heapify(A, m, length);
    }

}

int main(){
    int A[] = {4,10,3,5,1};
    int length = sizeof(A)/sizeof(A[0]);
    heapify(A, 0, length);
    for(int i=0; i<length;i++)
        printf("%d ", A[i]);
}

