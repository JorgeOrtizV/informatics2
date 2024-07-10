/*
The closest number problem involves finding the closest number in an array A[...] with length n
sorted in ascending order to a given number t. One integer a is closer to t than another integer b if
|a − t| < |b − t|. Implement an algorithm with complexity O(log n) that finds the closest number to t
in an array A sorted in ascending order. Use C code for your implementation.
*/

#include <stdio.h>
#include <math.h>
#include <limits.h>

int closestNum(int A[], int length, int target){
    int s = 0;
    int t = length;
    int dist = INT_MAX;
    int idx = -1;
    while(s<=t){
        int m = floor((s+t)/2);
        if(abs(A[m]-target)<dist){
            dist = abs(A[m]-target);
            idx = m;
        }
        if(A[m]>target){
            t=m-1;
        }else
            s=m+1;
    }
    return idx;
}

int main(){
    int A[] = {1,3,4,5,6};
    int length = sizeof(A)/sizeof(A[0]);
    int target = 2;
    int idx = closestNum(A, length, target);
    printf("%d", A[idx]);
    return 0;
}