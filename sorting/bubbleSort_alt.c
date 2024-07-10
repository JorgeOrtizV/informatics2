// Modification of bubble sort so that the smallest element is in the leftmost part instead the greatest in the rightmost part each iteration

#include <stdio.h>

#define n 10

void bubbleSort(int *nums, int size){
    int count = 0;
    for(int i=0; i<size-1; i++){
        for(int j=size-1; j>i;j--){ // Since we are sending the biggest element to the end of the array each iteration we save a couple of iterations by going up to i instead of n
            if(nums[j]<nums[j-1]){
                int buffer = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = buffer;
            }
            count++;
        }
    }
    for(int p=0; p<size;p++)
        printf("%d ", nums[p]);
    // print the number of iterations of the innermost loop
    printf("\n%d", count);
}

int main(){
    int array[n] = {15, 23, 0, 23, 7, -4, 1, 97, 16, 80};
    bubbleSort(array, n);
}