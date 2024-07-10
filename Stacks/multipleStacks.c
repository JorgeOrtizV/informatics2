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

Adapt the implementation of stacks from b) to allow support for multiple instances of stacks.
More precisely, your implementation should now support the operations:
• new() creates a new (empty) stack and returns it.
• is_empty(S) takes as argument a stack S and returns True is the stack is empty.
pop(S) takes as argument a stack S, pops the topmost element of the stack and returns it.
* If there is no element on the stack, return -1.
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

void print_stack(struct node **S, char *name) {
    if (is_empty(S) == 0) {
        printf("Stack %s is (from bottom to top): ", name);
        print_stack_helper(*S);
        printf("\n");
    }
    else {
        printf("The stack %s is empty.\n", name);
    }
}

int main() {
    struct node **S1 = init();
    printf("The initial stack S1 is empty: %d\n", is_empty(S1));
    push(S1, 3);
    push(S1, 2);
    push(S1, 1);
    print_stack(S1, "S1");
    printf("Popped item: %d\n", pop(S1));
    print_stack(S1, "S1");
    push(S1, 4);
    print_stack(S1, "S1");
    printf("Popped item: %d\n", pop(S1));
    printf("Popped item: %d\n", pop(S1));
    printf("Popped item: %d\n", pop(S1));
    print_stack(S1, "S1");
    printf("Now I tried popping an empty stack: %d\n", pop(S1));

    struct node **S2 = init();
    push(S2, 2);
    push(S2, 3);
    push(S2, 4);
    print_stack(S2, "Stack 2");
    printf("Now I can pop an element from S2 and push that element in S1.\n");
    push(S1, pop(S2));
    print_stack(S2, "Stack 2");
    print_stack(S1, "Stack 1");
    return 0;
}