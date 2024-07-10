#include <stdio.h>
#include <limits.h>
#define n 10

int secondLargest(int A[], int length){
    int largest = INT_MIN;
    int secondL = NULL;
    if(length < 2)
        return -1;
    for(int i = 0; i<length; i++){
        if(A[i] > largest){
            secondL = largest;
            largest = A[i];
        }
    }
    return secondL;
     
}

int main(){
    int A[n] = {1,2,3,4,5,6,7,8,9,10};
    int length = sizeof(A)/sizeof(A[0]);
    int result = secondLargest(A, length);
    printf("%d", result);

    return 0;
}