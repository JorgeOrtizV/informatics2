#include <stdio.h>
#include <math.h>
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

float naiveMean(int A[], int length){
    QuickSort(A, 0, length-1);
    if(length%2==0){
        int a = floor(length/2);
        return (float)((A[a]+A[a+1])/2);
    }else{
        int a=ceil(length/2);
        return A[a];
    }
}

int medianRecursive(int A[], int s, int t, int pos){
    if(s>=t)
        return A[s];
    int m = hoarePartition(A, s, t);
    if(pos >= m)
        return medianRecursive(A, m, t, pos);
    else   
        return medianRecursive(A, s, m-1, pos);
}

float quickMean(int A[], int s, int length){
    if(length==0)
        return 0;
    if(length%2 == 0){
        int smallerMedianElement = medianRecursive(A, 0, length-1, (length-1)/2);
        int biggerMedianElement = A[length/2];
        for(int i=(length-1)/2; i<length;i++){
            if(biggerMedianElement > A[i])
                biggerMedianElement=A[i];
        }
        return (float)((smallerMedianElement+biggerMedianElement)/2);
    }else
        return medianRecursive(A, 0, length-1, length/2);
    
}

int main(){
    int A[] = {10,1,67,20,56,8,43,90,54,34,0};
    int length = sizeof(A)/sizeof(A[0]);
    float res = naiveMean(A, length);
    printf("%f\n", res);
    res = quickMean(A, 0, length);
    printf("%f\n", res);
}