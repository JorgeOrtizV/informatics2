#include <stdio.h>

// TODO: I am getting 3 zeros at the beggining of my sorted array

void bubbleSort(int *nums, int size){
    int count = 0;
    for(int i=size; i>1;i--){
        for(int j=1; j<i;j++){ // Since we are sending the biggest element to the end of the array each iteration we save a couple of iterations by going up to i instead of n
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
    int size = 10;
    int array[size] = {15, 23, 0, 23, 7, -4, 1, 97, 16, 80};
    bubbleSort(array, size);
}