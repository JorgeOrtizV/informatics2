#include <stdio.h>
#include <cstdbool>

bool palindrome(char A[], int s, int r){
    if(A[s]!=A[r])
        return false;
    else if(s<=r)
        return true;
    return palindrome(A, s+1, r-1);
}

bool palindromeIt(char A[], int s, int r){
    while(s<=r){
        if(A[s]!=A[r]){
            return false;
        }
        s++;
        r--;
    }
    return true;
}

int main(){
    char A[] = "hannah";
    int length = (sizeof(A)/sizeof(A[0]))-1;
    bool result = palindrome(A, 0, length-1);
    printf("%d", result);
}
