#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findOperator(char *expr, int h, int t){
    int count = 0;
    for(int i=h; i<=t;i++){
        // Make sure we are not in the middle of a parenthesis
        if(expr[i]=='(')
            count++;
        else if(expr[i]==')')
            count--;
        else if((expr[i]=='+'||expr[i]=='-')&&count==0)
            return i;
    }
    count=0;
    for(int i=h; i<=t;i++){
        if(expr[i]=='(')
            count++;
        else if(expr[i]==')')
            count--;
        else if((expr[i]=='*'||expr[i]=='/')&&count==0)
            return i;
    }
    return -1;
}

float calculator(char *expr, int h, int t){
    // Check if our parenthesis scope the whole operation
    if(expr[h]=='(' && expr[t]==')'){
        int flag = 0;
        int count = 0;
        for(int i=h+1; i<t;i++){
            if(expr[i] == '(')
                count++;
            else if(expr[i]==')' && count==0){ // Found a closing parenthesis before
                flag=1;
                break;
            }else if(expr[i]==')'){
                count--;
            }
        }
        if(flag==0)
            h++;
            t--;
    }
    // Single element remaining
    
    int m = findOperator(expr, h, t);
    //printf("%d\n", m);
    if(m==-1 || (h==m && expr[h]=='-')){
        char num[20]; // buffer
        int numIndex = 0;
        for(int i=h;i<=t; ++i){
            num[numIndex++] = expr[i];
        }
        num[numIndex] = '\0';
        return(float)(atoi(num));
    }
    
    if(expr[m] == '*')
        return calculator(expr, h, m-1)*calculator(expr, m+1, t);
    else if(expr[m] == '/')
        return calculator(expr, h, m-1)/calculator(expr, m+1, t);
    else if(expr[m] == '+')
        return calculator(expr, h, m-1)+calculator(expr, m+1, t);
    else
        return calculator(expr, h, m-1)-calculator(expr, m+1, t);

}

int main(){
    char expr[] = "(3+4)*5/6+7*8";
    int length = (sizeof(expr)/sizeof(expr[0]))-1;
    float result = calculator(expr, 0, length-1);
    printf("%f", result);
}