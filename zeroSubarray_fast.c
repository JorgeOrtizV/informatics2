/*
In computer science, a subarray is a contiguous sequence of elements within an array. For example,
for the array [1, 2, 3], the subarrays are [1], [2], [3], [1, 2], [2, 3], and [1, 2, 3].

Write a C function zeroSubarray(int array[], int length) that takes an array of integers
and its length as parameters and returns 1 if it is possible to find a subarray where the sum of all
integers adds up to zero. Otherwise, the function should return 0.
*/

#include <stdio.h>
#include <cstdbool>

// Ideally I would have to implement a hash table, however since we are managing small arrays I use 
// another array to store the known sums and iterate through it each time a new element is discovered
// The runing time of the algorithm would be O(nlogn) in case a subzero array exists
// but would have a worst case runing time of O(n2) if there is no zero sum sub array.

bool zeroSubarray(int *array, int size){
    int subsums = 0;
    int sums_array [20]; // Increase this buffer if needed
    int sum = 0;
    for(int i=0; i<size;i++){
        if(array[i]==0)
            return true;
        sum+=array[i];
        // Check if sum already exists
        for(int j=0;j<subsums;j++){
            if(sums_array[j]==sum){
                return true;
            }
        }
        // If we didn't find the sum we append it to the sums array
        sums_array[subsums] = sum;
        subsums++;
    }
    return false;
}

int main(){
    int size = 6;
    int array [] = {-1,4,-1,5,9,-12};
    bool result = zeroSubarray(array, size);
    printf("%d", result); // Prints 1 if zero subsum found
}



