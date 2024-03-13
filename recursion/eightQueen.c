/*
Puzzle of placing N queens in a NxN chessboard so that no two queens
threaten each other.

Solution: We iterate through all the rows of the board. For each board
We place each columns where there is a safe space
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8
 
int count = 0;

int isSafe(int board[N][N], int row, int col){
    // Check column
    for(int i=0; i<row;i++){
        if(board[i][col]==1){
            return -1;
        }
    }
    // No need to check the row because we only insert one queen per row

    // Check diagonal
    for(int i=row, j=col; i>=0 && j>=0;i--, j--){
        if(board[i][j]==1){
            return -1;
        }
    }
    // Check inv diagonal
    for(int i=row, j=col; i>=0 && j<N;i--, j++){
        if(board[i][j]==1){
            return -1;
        }
    }
    return 1;

}

void solveNQueens(int board[N][N], int row){
    if(row==N){
        count++;
        return;
    }
    for(int col=0; col<N;col++){
        if(isSafe(board, row, col)==1){
            board[row][col] = 1;
            // go to next row
            solveNQueens(board, row+1);
            // reverse
            board[row][col] = 0;
        }
    }

}

int main(){
    int board[N][N];
    memset(board,0, sizeof(board));
    solveNQueens(board, 0);
    printf("Total solutions: %d", count);
    return 0;
}