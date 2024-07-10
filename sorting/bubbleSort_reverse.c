#include <stdio.h>

#define n 10

void bubbleSort_reverse(int *nums, int size){
    int count = 0;
    for(int i=size; i>1;i--){
        for(int j=1; j<i;j++){ // Change comparisson here to send the smallest element to the end.
            if(nums[j]>nums[j-1]){
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
    bubbleSort_reverse(array, n);
}