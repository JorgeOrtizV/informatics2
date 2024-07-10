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

Adapt the implementation of queues from b) to allow support for multiple instances of queues.
More precisely, your implementation should now support the operations:
• new() creates a new (empty) queue and returns it.
• is_empty(Q) takes as argument a queue Q and returns True if it is empty.
• dequeue(Q) takes as argument the node pointing to queue Q. The function removes the
front element and returns it. If there is no element in the queue, return -1.
• enqueue(Q, x) takes as arguments the queue Q and an integer x, and inserts x at the back
of the queue
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

int main() {
    struct Queue q1 = init();
    printf("The queue q1 is empty: %d\n", is_empty(q1));
    printf("I now enqueue the values 3, 4 and 2\n");
    enqueue(q1, 3);
    enqueue(q1, 4);
    enqueue(q1, 2);
    print_queue(q1, "q1");
    printf("I now dequeue (remove from the head)\n");
    printf("Dequeued value: %d\n", dequeue(q1));
    print_queue(q1, "q1");
    printf("Dequeued value: %d\n", dequeue(q1));
    print_queue(q1, "q1");
    printf("Enqueued value: 10\n");
    enqueue(q1, 10);
    print_queue(q1, "q1");
    printf("Enqueued value: 20\n");
    enqueue(q1, 20);
    print_queue(q1, "q1");
    printf("Dequeued value: %d\n", dequeue(q1));
    print_queue(q1, "q1");
    printf("Dequeued value: %d\n", dequeue(q1));
    print_queue(q1, "q1");
    printf("Dequeued value: %d\n", dequeue(q1));
    print_queue(q1, "q1");
    printf("Dequeued value: %d\n", dequeue(q1));

    printf("\nNow I create another queue\n");
    struct Queue q2 = init();
    enqueue(q2, 12);
    enqueue(q2, 7);
    enqueue(q2, 9);
    print_queue(q2, "q2");

    printf("\nNow I transfer one element from q2 to q1:\n");
    enqueue(q1, dequeue(q2));
    print_queue(q1, "q1");
    print_queue(q2, "q2");
    return 0;
}