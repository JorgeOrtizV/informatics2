// Implementation of merge sort algorithm

#include <stdio.h>
#include <math.h>

// merge(array, start idx, mid point, end idx)
void merge(int *array, int p, int q, int r){
    int len_l = q-p+1;
    int len_r = r-q;
    int left[len_l];
    int right[len_r];
    for(int i=0;i<len_l;i++){
        left[i] = array[p+i];
    }
    for(int i=0; i<len_r; i++){
        right[i] = array[q+i+1];
    }
    int i = 0; //index of smallest element in left
    int j = 0; //index of smallest element in right
    int k = p; //Indexes in the location in A to fill
    while(i<len_l && j<len_r){
        if(left[i]<=right[j]){
            array[k]=left[i];
            i++;
        }else{
            array[k] = right[j];
            j++;
        }
        k++;
    }
    // Add all the remaining elements
    while(i<len_l){
        array[k]=left[i];
        i++;
        k++;
    }
    while(j<len_r){
        array[k]=right[j];
        j++;
        k++;
    }
}

void mergeSort(int *array, int p, int r){
    if(p>=r){
        return;
    }
    int q=floor((p+r)/2);
    mergeSort(array, p, q);
    mergeSort(array, q+1, r);
    merge(array, p, q, r);
}

int main(){
    int array[7]= {2,5,1,9,0,1,3};
    int p = 0;
    int r = (sizeof(array)/sizeof(int))-1;
    mergeSort(array, p, r);
    for(int i=0;i<r+1;i++){
        printf("%d ", array[i]);
    }
    return 0;
}

