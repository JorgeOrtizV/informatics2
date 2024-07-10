#include <stdio.h>

#define SIZE 6

int linearSearch(int* array, int size, int target){
    for(int i = 0; i<size; i++){
        if(array[i] == target)
            return i;
    }
    return -1;
}

int main(){
    int array[SIZE] = {1,2,3,4,5,6};
    int target=3;
    int result = linearSearch(array, SIZE, target);
    printf("%d", result);
    return 0;
}