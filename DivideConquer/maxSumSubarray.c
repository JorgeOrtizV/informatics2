/*
The maximum subarray problem involves finding the contiguous subarray in an unordered array that
has the largest sum. For example for array A = [−1, 2, −4, 1, 9, −6, 7, −3, 5] the maximum subarray
is [1, 9, −6, 7, −3, 5] with a sum of 13. Use a divide and conquer approach to solve this problem by
breaking it into subproblems and solving them recursively.
a) Draw a tree to illustrate the process of determining the maximum subarray in array A =
[−2, −3, 4, −1, −2, 1, 5, −3].
b) Implement a divide and conquer algorithm that finds the maximum subarray in an array A and
returns its sum. Use C code for your implementation.
c) Determine the recurrence relation of your algorithm and its asymptotic tight bound.
*/

#include <stdio.h>
#include <limits.h>
#include <math.h>

int max(int a, int b, int c){
    if(a>b && a>c)
        return a;
    else if(b>a && b>c)
        return b;
    return c;
}

int maxCrossingSum(int A[], int s, int m, int t){
    // left sum
    int left_sum = INT_MIN;
    int sum = 0;
    for(int i=m; i>=s; i--){
        sum = sum + A[i];
        if(sum > left_sum)
            left_sum = sum;
    }

    // right sum
    int right_sum = INT_MIN;
    sum=0;
    for(int i=m+1; i<=t;i++){
        sum = sum + A[i];
        if(sum > right_sum)
            right_sum = sum;
    }

    return left_sum+right_sum;
}

int maxSumSubarray(int A[], int s, int t){
    if(s==t)
        return A[s];
   
    int m = floor((s+t)/2);
    int left = maxSumSubarray(A, s, m);
    int right = maxSumSubarray(A, m+1,t);
    int maxCrossing = maxCrossingSum(A, s, m, t);

    return(max(left, right, maxCrossing));
}

int main(){
    int A[] = {2, 3, 4, 5, 7};
    int length = sizeof(A)/sizeof(A[0]);
    int max_sum = maxSumSubarray(A, 0, length-1);
    printf("%d", max_sum);
}
