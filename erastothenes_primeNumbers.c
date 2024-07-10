#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void erastothenes(int n){
    int array_size = n+1;
    bool result_array[array_size];
    memset(result_array, true, sizeof(result_array));
    for(int i=2;i*i<=n;i++){
        if(result_array[i] == true){
            for(int j=i*i;j<=n;j+=i){
                result_array[j] = false;
            }
        }
    }
    for(int p=2;p<=n;p++){
        if(result_array[p]){
            printf("%d ", p);
        }
    }
}

int main(){
    int n = 30;
    erastothenes(n);

    return 0;
}