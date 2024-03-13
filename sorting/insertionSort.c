#include <stdio.h>

void insertionSort(int *array, int size){
    int count=0;
    for(int i=1; i<size; i++){
        int key = array[i]; // Element to sort
        int j = i-1;
        while(j>=0 && array[j]>key){
            // If previous element is a valid index and is greater than j, we swap it to the right
            array[j+1] = array[j];
            j--;
            count++;
        }
        array[j+1] = key;
    }

    for(int p=0; p<size;p++){
        printf("%d ", array[p]);
    }
    // print the number of iterations of the innermost loop
    printf("\n%d", count);
}

int main(){
    int size = 10;
    int array[size] = {15, 23, 0, 23, 7, -4, 1, 97, 16, 80};
    insertionSort(array, size);
    return 0;
}