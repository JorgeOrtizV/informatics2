/* 
Recursive implementation of a simple calculator that supports the following operators: +,-,*,/, and ()
*/

#include <stdio.h>

int findOperator(char *expr, int h, int t){
    int count = 0;
    // Check for sum (return first the lowest hierarchy)
    for(int i = h; i<t;i++){
        if(expr[i]==')')
            count++;
        else if(expr[i]=='(')
            count--;
        else if((expr[i]=='+' || expr[i]=='-')&&count==0){
            return i;
        }
    }
    // Check later for * or /
    count=0;
    for(int i = h; i<t;i++){
        if(expr[i]==')')
            count++;
        else if(expr[i]=='(')
            count--;
        if((expr[i]=='*' || expr[i]=='/')&&count==0){
            return i;
        }
    }
        
    return -1;
}

float calculator(char *expr, int h, int t){
    if(expr[h] == '(' && expr[t]==')'){
        // Check that our h and t are the parenthesis that hold the entire operation.
        int flag = 0;
        for(int i=h+1;i<t;i++){
            if(expr[i]==')'){
                flag=1;
                break;
            }
        }
        if(flag==0)
            return calculator(expr, h+1, t-1);
    }
    int opIndex = findOperator(expr, h, t);
    if(opIndex == -1){ // In this case h and t should be the same
        printf("%d\n", expr[h]-'0');
        return expr[h]-'0';
    }
    char op = expr[opIndex];
    switch (op)
    {
    case '*':
        return calculator(expr, h, opIndex-1)*calculator(expr, opIndex+1,t);
        break;
    case '/':
        return calculator(expr, h, opIndex-1)/calculator(expr, opIndex+1,t);
        break;
    case '+':
        return calculator(expr, h, opIndex-1)+calculator(expr, opIndex+1,t);
        break;
    case '-':
        return calculator(expr, h, opIndex-1)-calculator(expr, opIndex+1,t);
        break;   
    default:
        break;
    }
}

int main(){
    char expr[] = "(3+4)*5/6+7*8*(1+2-3)";
    //char expr[] = "(5+3)*8";
    float result = calculator(expr, 0, (sizeof(expr)/sizeof(char))-2); // -2 due to eos
    printf("%f ", result);
}