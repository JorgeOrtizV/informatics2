#include <stdio.h>

/*
One of the simplest ways to compress a string is the so-called Run-Length-Encoding (RLE). In this
method, consecutive identical characters in a string are replaced by the amount and the character
itself.
An example of this would be ”AAABBAAAA” is transformed by RLE to ”3A2B4A”, where ”3A”
stands for three consecutive ”A”s, ”2B” for two consecutive ”B”s and ”4A” for four consecutive ”A”s.
*/

void rleCompression(char string[], int size){
    int count = 1;
    char buffer = string[0];
    for(int i = 1; i<size;i++){
        if(string[i]!=buffer){
            printf("%d%c",count,buffer);
            count = 0;
            buffer=string[i];
        }
        count++;
    }
    // We need to print the last char and it's count
    printf("%d%c",count,buffer);
}

int main(){
    int size = 9;
    char string[] = "AAABBAAAA";
    rleCompression(string, size);
    return 0;
}