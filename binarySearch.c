#include <stdio.h>

int binarySearch(int *array, int size, int target){
    int left = 0;
    int right = size-1;
    while(left<=right){
        int mid = left+((right-left)/2); // No need of math.floor since we are storing integers
        if(array[mid] == target){
            return mid;
        }
        if(array[mid]<target){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return -1;
}

int main(){
    int array[] = {1,2,3,4,5,6};
    int size = 6;
    int target=3;
    int result = binarySearch(array, size, target);
    printf("%d", result);
}