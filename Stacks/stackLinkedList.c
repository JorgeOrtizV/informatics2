/*
The goal of this task is to implement stacks in C, using arrays and linked lists.
Assume that we use a single, global stack S. The implementation should support the following opera-
tions:
• init() initializes the stack S.
• is_empty() returns True if the stack is empty.
• pop() pops the topmost element of the stack and returns it. If there is no element on the stack,
return -1.
• push(x) takes as argument a positive integer x, and pushes x on top of the stack.
These operations should have a runtime complexity of O(1) in your implementation.

a. Implement the operations described above, using stacks represented as arrays.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};

struct node* t;

void init(){
    t=NULL;
}

bool is_empty(){
    return (t == NULL);
}

int pop(){
    if (is_empty()==true)
        return -1;
    // Case only one element in stack
    if(t->next == NULL){
        int top_val = t->val;
        t = NULL;
        return top_val;
    }else{
        // We have at least two elements
        int top_val = t->val;
        struct node* top = t;
        t = top->next;
        free(top);
        return top_val;
    }
    
}

void push(int x){
    // Case the stack is empty
    if(t==NULL){
        t = (struct node*)malloc(sizeof(struct node));
        t->val=x;
        t->next=NULL;
    }else{
        // There is at least other element
        struct node* n = (struct node*)malloc(sizeof(struct node));
        n->val=x;
        n->next=t;
        t=n;
    }
    
}

void print_stack_helper(struct node *node) {
    if (node != NULL) {
        print_stack_helper(node->next);
        printf("%d ", node->val);
    }
}

void print_stack() {
    if (is_empty() == 0) {
        printf("Stack is (from bottom to top): ");
        print_stack_helper(t);
        printf("\n");
    }
    else {
        printf("The stack is empty.\n");
    }
}

int main() {
    init();
    printf("The initial stack is empty: %d\n", is_empty());
    push(3);
    push(2);
    push(1);
    print_stack();
    printf("Popped item: %d\n", pop());
    print_stack();
    push(4);
    print_stack();
    printf("Popped item: %d\n", pop());
    printf("Popped item: %d\n", pop());
    printf("Popped item: %d\n", pop());
    print_stack();
    printf("Now I tried popping an empty stack: %d\n", pop());
    return 0;
}