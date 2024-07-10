#include <stdio.h>

void selectionSort(int A[], int length){
    for(int i=0; i<length-1; i++){
        int smallest = i;
        for(int j=i+1;j<length;j++){
            if(A[j] < A[smallest])
                smallest=j;
        }
        int temp = A[i];
        A[i] = A[smallest];
        A[smallest] = temp;
    }
}

int main(){
    int A[] = {3,20,42,2,1,0,23,-1};
    int length = sizeof(A)/sizeof(A[0]);
    selectionSort(A, length);
    for(int i=0; i<length;i++)
        printf("%d ", A[i]);

    return 0;
}