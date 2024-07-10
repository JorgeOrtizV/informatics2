#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int editDist(char A[], char B[], int l1, int l2){
    // setup
    int M[l1+1][l2+1];

    for(int i=0; i<l1+1; i++)
        M[i][0] = i;

    for(int i=0; i<l2+1; i++)
        M[0][i] = i;


    for(int i=1; i<=l1; i++){
        for(int j=0; j<=l2; j++){
            if(A[i-1]==B[j-1]){
                M[i][j] = M[i-1][j-1];
            }else{
                M[i][j] = MIN(M[i-1][j-1],MIN(M[i-1][j], M[i][j-1]))+1;
            }
        }
    }

    return M[l1][l2];

}

int main(){
    char A[] = "SGM";
    char B[] = "AGCM";
    int l1 = (sizeof(A)/sizeof(A[0]))-1;
    int l2 = (sizeof(B)/sizeof(B[0]))-1;

    int res = editDist(A, B, l1, l2);
    printf("%d", res);

}