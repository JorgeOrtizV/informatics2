#include <stdio.h>
#include <cstdbool>
#include <stdlib.h>
#include <string.h>

#define N 8

int count = 0;

bool isSafe(int board[N][N], int row, int col){
    // Check col - Only check previus insertions
    for(int i = 0; i<row; i++){
        if(board[i][col]==1)
            return false;
    }
    // Check left diag
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(board[i][j]==1)
            return false;
    }
    // check right diag
    for(int i=row, j=col; i>=0 && j<N; i--, j++){
        if(board[i][j]==1)
            return false;
    }

    return true;

}

void NQueens(int board[N][N], int row){
    if(row==N){
        count++;
        return;
    }
    for(int col = 0; col<N; col++){
        //printf("%d\n", isSafe(board, i, j));
        if(isSafe(board, row, col)==true){
            board[row][col] = 1;
            NQueens(board, row+1);
            board[row][col] = 0;
        }
    }
}


int main(){
    int board[N][N];
    memset(board, 0, sizeof(board));
    NQueens(board, 0);
    printf("Num of solutions: %d", count);
    return 0;

}