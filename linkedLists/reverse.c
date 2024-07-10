/*
Let the same struct as in Task 3(a) define a node in a doubly linked list. Implement a function
reverse() which takes a pointer to a node and returns the pointer to the head of the reversed list. The
reverse() function should only change pointers. It should not create new nodes.
There are two ways to implement this. The easier way is to implement an iterative algorithm. A
harder, but more elegant solution is to implement an recursive function.
*/

#include <stdio.h>

struct node{
    int val;
    struct node* next;
    struct node* prev;
};

// struct node* reverse(struct node *h){
//     if(h==NULL || h->next == NULL){
//         return h;
//     }
//     // We need to know the last element in our list
//     struct node *tail = h;
//     while(tail->next != NULL){
//         tail = tail->next;
//     }
//     // Linearly swap 
//     struct node *p = h;
//     struct node *t;
//     while(p!=tail){
//         t = tail;
//         if(p==h){ // In this case tail will always point to the last element.
//             struct node *t_prev = t->prev;
//             t->prev=NULL;
//             t->next = p->next;
//             p->next = NULL;
//             p->prev = t_prev;
//             tail = tail->next;
//             p = t->next;
//         }else{
//             struct node *t_prev = t->prev;
//             struct node *t_next = t->next;
//             t->prev = p->prev;
//             t->next = p->next;
//             p->next = t_next;
//             p->prev = t_prev;
//             tail = tail->next;
//             p = t->next;
//         }
//         // Finish swapping
//         if(p->next==tail)
//             break;
//     }
// }

struct node* reverse(struct node *h){
    if(h==NULL || h->next == NULL){
        return h;
    }
    struct node *temp = NULL;
    struct node *current = h;

    while(current != NULL){
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->prev;
    }

    return temp->prev;
}