#include <stdio.h>

void bubbleSort(int A[], int length){
    for(int i=length; i>1; i--){
        for(int j=1; j<i; j++){
            if(A[j-1]>A[j]){
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
            }
        }
    }
}


int main(){
    int A[] = {1,2,4,7,10,34,1,23,9,13};
    int length = sizeof(A)/sizeof(A[0]);
    //printf("%d", length);
    bubbleSort(A, length);
    for(int i=0; i<length;i++)
        printf("%d ", A[i]);
    return 0;
}