 /*
The goal of this task is to implement queues in C, using arrays and linked lists.
Assume for now that we use a single, global queue. The implementation should support the following
operations:
• new() initializes the global queue.
• is_empty() returns True if the queue is empty.
• dequeue() removes the front element of the queue and returns it. If there is no element in the
queue, return -1.
• enqueue(x) takes as argument a positive integer x, and inserts x at the back of the queue.
These operations should have a runtime complexity of O(1) in your implementation.

mplement the operations described above, using queues represented as singly linked lists.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};

struct node* head;
struct node* tail;

void init(){
    head = NULL;
    tail = NULL;
}

bool is_empty(){
    return (head==NULL && tail==NULL);
}

int dequeue(){
    if(is_empty()){
        return -1;
    }
    // Case single element
    if(head==tail){
        int next_val = head->val;
        free(head);
        head = NULL;
        tail = NULL;
        return next_val;
    }else{
        // We have at least two elements
        int next_val = head->val;
        struct node* tmp = head;
        head = head->next;
        free(tmp);
        return next_val;
    }
    

}

void enqueue(int x){
    // Case the Queue is empty
    if(is_empty()){
        struct node* n = (struct node*)malloc(sizeof(struct node));
        n->val = x;
        n->next = NULL;
        tail = n;
        head = n;
    }else{
        struct node* n = (struct node*)malloc(sizeof(struct node));
        n->val = x;
        n->next = NULL;
        tail->next = n;
        tail=n;
    }
}

void print_queue() {
    if (is_empty()) {
        printf("The queue is empty.\n");
        return;
    }

    printf("The queue is (from head to tail): ");
    for (struct node *node = head; node != NULL; node = node->next) {
        printf("%d ", node->val);
    }
    printf("\n");
}

int main() {
    init();
    printf("The initial queue is empty: %d\n", is_empty());
    printf("I now enqueue the values 3, 4 and 2\n");
    enqueue(3);
    enqueue(4);
    enqueue(2);
    print_queue();
    printf("I now dequeue (remove from the head)\n");
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Enqueued value: 10\n");
    enqueue(10);
    print_queue();
    printf("Enqueued value: 20\n");
    enqueue(20);
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    print_queue();
    printf("Dequeued value: %d\n", dequeue());
    return 0;
}