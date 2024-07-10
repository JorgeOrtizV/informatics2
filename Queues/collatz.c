/*
We define a set of numbers C to be a Collatz set if it fulfills the following properties:
• 1 ∈ C
• If x ∈ C, then also 3x + 1 ∈ C and 3x + 2 ∈ C.
A Collatz set has infinitely many numbers. The first few terms of a Collatz set are:
1, 4, 5, 13, 14, 16, 17, 40, ...
We can generate the terms of a Collatz set as follows: start from the number 1, then insert the
elements 4 = 3 · 1 + 1 and 5 = 3 · 1 + 2 into the set, then generate the elements derived from 4 and 5
and so on.
Write a function void generate(int n) that prints the first (smallest) n elements of a Collatz set.
Use a queue to solve this task.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};

struct Queue{
    struct node** head;
    struct node** tail;
};

struct Queue init(){
    struct Queue q;
    q.head = (struct node**)malloc(sizeof(struct node*));
    q.tail = (struct node**)malloc(sizeof(struct node*));
    *(q.head) = NULL;
    *(q.tail) = NULL;
    return q;
}

bool is_empty(struct Queue q){
    if(*(q.head)==NULL && *(q.tail)==NULL)
        return true;
    else
        return false;
}

void enqueue(struct Queue q, int x){
    if(is_empty(q)){
        struct node* n = (struct node*)malloc(sizeof(struct node));
        n->val = x;
        n->next = NULL;
        *(q.tail) = n;
        *(q.head) = n;
    }else{
        struct node* n = (struct node*)malloc(sizeof(struct node));
        n->val = x;
        n->next = NULL;
        (*(q.tail))->next = n;
        *(q.tail) = n;
    }
    
    
}

int dequeue(struct Queue q){
    if(is_empty(q))
        return -1;
    if(*(q.head)==*(q.tail)){
        int val = (*(q.head))->val;
        free(*(q.head));
        *(q.head) = NULL;
        *(q.tail) = NULL;
        return val;
    }else{
        int val = (*(q.head))->val;
        struct node* temp = *(q.head);
        *(q.head) = (*(q.head))->next;
        free(temp);
        return val;
    }
}

void print_queue(struct Queue q, const char *name) {
    if (is_empty(q)) {
        printf("The queue %s is empty.\n", name);
        return;
    }

    printf("The queue %s is (from head to tail): ", name);
    for (struct node *node = *(q.head); node != NULL; node = node->next) {
        printf("%d ", node->val);
    }
    printf("\n");
}

int show_tail(struct Queue q){
    if(is_empty(q))
        return -1;
    return (*(q.tail))->val;
}

void collatz(int n){
    if(n==1){
        printf("%d", 1);
        return;
    }
    struct Queue q = init();
    int count = 1;
    enqueue(q, 1);
    while(1){
        // Obtain last added element and print it
        int popped = dequeue(q);
        printf("%d ", popped);
        int col1 = 3*popped+1;
        enqueue(q, col1);
        count++;
        if(count==n)
            break;
        int col2 = 3*popped+2;
        enqueue(q, col2);
        count++;
        if(count==n)
            break;
    }
    while(!is_empty(q)){
        int popped = dequeue(q);
        printf("%d ", popped);
    }
}

int main(){
    int n = 7;
    collatz(n);
    return 0;
}