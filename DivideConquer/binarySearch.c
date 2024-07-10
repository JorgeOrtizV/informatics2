#include <stdio.h>
#include <math.h>

int binarySearch(int A[], int target, int length){
    int s = 0;
    int t = length;
    while(s<=t){
        int m = floor((s+t)/2);
        if(A[m]==target)
            return m;
        else if(A[m]>target){
            t=m-1;
        }else
            s=m+1;
    }
    return -1;
}

int main(){
    int A[] = {1,2,3,4,5,6,7,8};
    int length = sizeof(A)/sizeof(A[0]);
    int res = binarySearch(A, 23, length);
    printf("%d", res);
}