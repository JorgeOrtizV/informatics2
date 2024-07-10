#include <stdio.h>

void insertionSort(int A[], int length){
    for(int i=1; i<length; i++){
        int j=i-1;
        int k = A[i];
        while(j>=0 && A[j]>k){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = k;
    }
}

int main(){
    int A[] = {3,20,42,2,1,0,23,-1};
    int length = sizeof(A)/sizeof(A[0]);
    insertionSort(A, length);
    for(int i=0; i<length;i++)
        printf("%d ", A[i]);

    return 0;
}