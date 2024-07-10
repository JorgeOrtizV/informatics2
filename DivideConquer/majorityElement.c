/*
Given an array of n integers, find the majority element with a divide and conquer approach. 
The majority element is the element that has appeared more than ⌊ n/2 ⌋ times. You can assume that the
majority element always exists.

*/


#include <stdio.h>
#include <math.h>

int combinedMajority(int A[], int left, int right, int s, int m, int t){
    if(left==right)
        return left;
    int left_count = 0;
    int right_count = 0;
    for(int i=s; i<=t; i++){
        if(A[i]==left)
            left_count++;
        else if(A[i]==right)
            right_count++;
    }
    if(left_count>right_count)
        return left;
    return right;
}

int majorityElement(int A[], int s, int t){
    if(s==t)
        return A[s];
    
    int m = floor((s+t)/2);
    int left = majorityElement(A, s, m);
    int right = majorityElement(A, m+1, t);
    int combined = combinedMajority(A, left, right, s, m, t);
    return combined;
}

int main(){
    int A[] = {3, 4, 3, 2, 4, 4, 4, 4};
    int length = sizeof(A)/sizeof(A[0]);
    int majority = majorityElement(A, 0, length-1);
    printf("%d", majority);
}