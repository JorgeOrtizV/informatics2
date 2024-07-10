#include <stdio.h>

int zeroSubarray(int A[], int length){
    int subsums[length];
    int index = 0;
    int sum = 0;
    for(int i=0; i<length; i++){
        if(A[i] == 0)
            return 1;
        sum+=A[i];
        for(int j=0; j<index; j++){
            if(sum == A[j]) //Sum has been seen previously
                return 1;
        }
        subsums[i] = sum;
        index++;
    }
    return 0;
}

int main(){
    int A[] = {-2, 4, -1, 5, 9, -12};
    int length = sizeof(A)/sizeof(A[0]);
    int result = zeroSubarray(A, length);
    printf("%d", result);
    return 0;
}