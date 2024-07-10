// Modification of Selection sort so that the biggest element is found and sorted at the end of the array

#include <stdio.h>

void selectionSort(int *array, int size){
    for(int i=size-1; i>0;i--){
        int biggest=i;
        for(int j=0;j<i;j++){
            if(array[j]>array[biggest]){
                biggest = j;
            }
        }
        if(biggest != i){
            int buffer = array[biggest];
            array[biggest]=array[i];
            array[i]=buffer;
        }
    }
    for(int p=0; p<size;p++)
        printf("%d ",array[p]);

}

int main(){
    int size = 10;
    int array[] = {9,8,7,6,5,4,3,2,1,0};
    selectionSort(array, size);
    return 0;
}