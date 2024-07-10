#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int hoarePartition(int A[], int s, int r){
    // Quasi random pivot to reduce worst-case partition risk
    int m = rand() % (r+1-s)+s; // Generate a random number between s and r
    int tmp = A[r];
    A[r]  = A[m];
    A[m] = tmp;

    // Selecting pivot
    int p = A[r];
    //printf("pivot: %d\n", p);
    int r_idx = r+1;
    int l_idx = s-1;
    while(true){
        do{
            r_idx--;
        }while(A[r_idx] > p);
        do{
            l_idx++;
        }while(A[l_idx] < p);
        //printf("right: %d\n", r_idx);
        //printf("left: %d\n", l_idx);
            
        if(l_idx < r_idx){
            int tmp = A[l_idx];
            A[l_idx] = A[r_idx];
            A[r_idx] = tmp;
        }else{
            return l_idx;
        }

    }

}

void QuickSort(int A[], int s, int t){
    if(s<t){
        int m = hoarePartition(A, s, t);
        //printf("%d\n", m);
        //return;
        QuickSort(A, s, m-1);
        QuickSort(A, m, t);
    }
}

int main(){
    int A[] = {1, 9, 0, 6, 3, 8, 7, 2, 4, 5};
    int length = sizeof(A)/sizeof(A[0]);
    QuickSort(A, 0, length-1);
    for(int i=0;i<length;i++)
        printf("%d ", A[i]);

}