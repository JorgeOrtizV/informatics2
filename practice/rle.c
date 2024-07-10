#include <stdio.h>

int rleCompression(char string[], int length, char result[]){
    //char result[length];
    int result_length=0;
    char buffer = string[0];
    int counter = 1;
    for(int i=1; i<length;i++){
        if(string[i]==buffer)
            counter++;
        else{
            // Append current compression
            result[result_length] = counter + '0'; // Convert integer to char
            result_length++;
            result[result_length] = buffer;
            result_length++;
            // Set for next char
            buffer = string[i];
            counter = 1;
        }
    }
    // Last pair of chars
    result[result_length] = counter + '0'; // Convert integer to char
    result_length++;
    result[result_length] = buffer;
    result_length++;

    return result_length;
}

int main(){
    char string[] = "AAABBAAAA";
    int length = (sizeof(string)/sizeof(string[0]))-1;
    char result[length];
    int result_length = rleCompression(string, length, result);
    for(int i=0; i<result_length;i++)
        printf("%c", result[i]);
    return 0;
}