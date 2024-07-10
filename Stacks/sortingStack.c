/*
Write a C function sort_stack(S) that receives a stack of integers S as argument, sorts the values in
S such that the lowest value is at the top, and returns the sorted stack. You are only allowed to use
stacks to sort the input stack (do not use arrays, queues etc.). You can assume that the stacks you
are allowed to use support the following operations:
• new() creates a new (empty) stack and returns it.
• is_empty(S) takes as argument a stack S and returns True is the stack is empty.
• pop(S) takes as argument a stack S, pops the topmost element of the stack and returns it. If
there is no element on the stack, return -1.
• push(S, x) takes as arguments a stack S and an integer x, and pushes x on top of the stack
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
    int val;
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

int pop(struct node** S){
    if (is_empty(S)==true)
        return -1;
    
    int top_value = (*S)->val;
    struct node* mock = *S;
    *S = (*S)->next;
    free(mock);
    return top_value; 
}

void push(struct node** S, int x){
    // Case the stack is empty
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->val=x;
    n->next=(*S);
    *S = n;
}

void print_stack_helper(struct node *node) {
    if (node != NULL) {
        print_stack_helper(node->next);
        printf("%d ", node->val);
    }
}

int show(struct node** S){
    if(is_empty(S))
        return -1;
    return (*S)->val;
}

struct node** sortStack(struct node **s){
    struct node** aux = init();
    while(true){
        if(is_empty(s))
            break;
        int top_s = pop(s);
        //printf("%d ", top_s);
        if(is_empty(aux))
            push(aux, top_s);
        else{
            int top_a = show(aux);
            if(top_s >= top_a)
                push(aux, top_s);
            else{
                while(show(aux)>top_s){
                    int top_a = pop(aux);
                    push(s, top_a);
                }
                push(aux, top_s);
            }
            
        }
    }
    return aux;
}

int main(){
    struct node** s = init();
    push(s, 34);
    push(s,3);
    push(s, 31);
    push(s, 98);
    push(s, 92);
    push(s, 23);
    struct node** sorted = sortStack(s);
    while(!is_empty(sorted)){
        printf("%d ", pop(sorted));
    }
}