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

#define MAX_STACK_SIZE 1000

int S[MAX_STACK_SIZE];
int t;  // top = index showing the first empty cell in the array

void init() {
    t = 0;
}

bool is_empty(){
    return (t==0);
}

bool push(int x){
    if(t==MAX_STACK_SIZE)
        return false;
    S[t]=x;
    t++;
    return true;
}

int pop(){
    if(is_empty())
        return -1;
    t--;
    return S[t];
}

void print_stack() {
    if (is_empty() == 0) {
        printf("Stack is (from bottom to t): ");
        for (int i = 0; i<t; i++) {
            printf("%d ", S[i]);
        }
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