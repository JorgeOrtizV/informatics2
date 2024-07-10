#include <stdio.h>
#include <math.h>

int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*i+2;
}

void swap(int A[], int a, int b){
    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

void heapify(int A[], int s, int t){
    int leftc = left(s);
    int rightc = right(s);
    int m = s;
    if(leftc<=t && A[leftc]>A[m])
        m=leftc;
    if(rightc<=t && A[rightc]>A[m])
        m=rightc;
    if(m!=s){
        swap(A, s, m);
        heapify(A, m, t);
    }
}

void BuildHeap(int A[], int length){
    for(int i=(length/2); i>=0; i--)
        heapify(A, i, length-1);
}

void heapSort(int A[], int length){
    BuildHeap(A, length);
    for(int i=length-1; i>0;i--){
        swap(A, 0, i);
        heapify(A, 0, i-1);
    }
}

int main(){
    int A[] = {2,7,0,1,3,8,3,0,1,3,5};
    int length = sizeof(A)/sizeof(A[0]);
    heapSort(A, length);
    for(int i=0; i<length; i++)
        printf("%d ",A[i]);
}