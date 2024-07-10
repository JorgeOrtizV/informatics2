/*
You are given a string containing open and closing parentheses. The goal of this task is to determine
whether the given sequence of parentheses is valid.
A sequence of parentheses is valid if every opening parenthesis has a corresponding closing parenthesis,
and matching parentheses are in the right order: first an open parenthesis, then a closed parenthesis.
Examples of valid sequences are:
• (())
• ()()()
• (())((()))
Examples of invalid sequences are:
• (() (the first open parenthesis does not have a corresponding closing parenthesis)
• (()))() (one closing parenthesis has no corresponding opening parenthesis)
• )( (wrong order of parentheses)
a. Write a function bool validate_parentheses(char *s) which takes a string s, representing
the parentheses sequence, and returns True if the sequence is valid. Use a stack in your solution.
Hint: Go through the input from left-to-right, and try to track the parentheses using a stack.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
    char val;
    struct node* next;
};

struct node** init(){ // Returns a pointer to a pointer
    struct node** S = (struct node**)malloc(sizeof(struct node*));
    *S = NULL;
    return S;
}

bool is_empty(struct node** S){
    return (*S == NULL);
}

char pop(struct node** S){
    if (is_empty(S)==true)
        return -1;
    
    char top_value = (*S)->val;
    struct node* mock = *S;
    *S = (*S)->next;
    free(mock);
    return top_value; 
}

void push(struct node** S, char x){
    // Case the stack is empty
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->val=x;
    n->next=(*S);
    *S = n;
}

char show(struct node** S){
    if(is_empty(S))
        return '!';
    return (*S)->val;
}

void print_stack_helper(struct node *node) {
    if (node != NULL) {
        print_stack_helper(node->next);
        printf("%d ", node->val);
    }
}

bool validSequence(char seq[], int length){
    int i = 0;
    struct node** s = init();
    while(i<length){
        char c = seq[i];
        if(c=='(')
            push(s, c);
        else if(c==')'){
            char top_sym = show(s);
            if(top_sym == '(')
                pop(s);
            else
                return false;
        }
        i++;
    }
    if(is_empty(s))
        return true;
    return false;
}


int main(){
    char seq[] = ")(";
    int length = (sizeof(seq)/sizeof(seq[0]))-1;
    bool valid = validSequence(seq, length);
    printf("%d", valid);
    return 0;
}