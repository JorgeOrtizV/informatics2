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

a. Implement the operations described above, using queues represented as circular arrays

*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 1000

int Q[MAX_QUEUE_SIZE];
int head;
int tail;

void init(){
    head = 0;
    tail = 0;
}

bool is_empty(){
    return(head==tail);
}

int dequeue(){
    if(is_empty())
        return -1;
    int val = Q[head];
    head = (head+1)%MAX_QUEUE_SIZE;
    return val;
}

bool enqueue(int x){
    // Check for new Quieue
    int next_idx = (tail+1)%MAX_QUEUE_SIZE;
    if(next_idx == tail){
        return false;
    }
    Q[tail] = x;
    tail = (tail+1)%MAX_QUEUE_SIZE;
    return true;
}

void print_queue() {
    if (is_empty()) {
        printf("The queue is empty.\n");
        return;
    }

    printf("The queue is (from head to tail): ");
    int i;
    for (i = head; i != tail; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", Q[i]);
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