/*
This exercise implements a recursive algorithm to check whether a given string
is palindrome or not
*/
#include <stdio.h>

int isPalindrome(char X[], int i, int j){
    if(j<=i){
        return 1;
    }
    if(X[i]!=X[j]){
        return -1;
    }
    return isPalindrome(X, i+1, j-1);
}

int main(){
    char X[]="1a_b3cD45t54Dc3b_a1";
    //char X[]="1a_b3c";
    int size = (sizeof(X)/sizeof(char))-1; // -1 due to end of string char
    int result = isPalindrome(X, 0, size-1);
    printf("%d ", result);
    return 0;
}