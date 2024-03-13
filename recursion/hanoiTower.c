/*
This code solves the problem of the Hanoi Tower with a recursive implementation

*/

#include <stdio.h>

int moveCount = 0;

void hanoi(int n, char src, char aux, char dst){
    // Base case:
    if(n==0){
        return;
    }
    // Move n-1 disks from source to aux
    hanoi(n-1, src, dst, aux);
    printf("Move disk %d from rod %c to rod %c\n", n, src, dst);
    // Move n-1 disks from aux to destination
    hanoi(n-1, aux, dst, src);
}

int main(){
    int n=3;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}