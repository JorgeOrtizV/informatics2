#include <stdio.h>

void selectionSort(int *array, int size){
    for(int i=0; i<size-1;i++){
        int smallest=i;
        for(int j=i+1;j<size;j++){
            if(array[j]<array[smallest]){
                smallest = j;
            }
        }
        if(smallest != i){
            int buffer = array[smallest];
            array[smallest]=array[i];
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