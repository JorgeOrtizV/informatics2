/*
Consider two sorted doubly linked lists. Implement a function merge(), which merges those two lists
into a single doubly linked list. The resulting, merged, list should be sorted and containing all elements
from the input linked lists. The merge() function should not copy values of the input linked lists. Use
the following struct for a node.
*/

#include <stdio.h>

struct node{
    int val;
    struct node* next;
    struct node* prev;
};

struct node* merge(struct node* h1, struct node* h2){
    if(h1==NULL)
        return h2;
    else if(h2==NULL)
        return h1;

    // Always merge in the array with the lowest starting value so we don't have to append in the beginning of the array
    struct node* i;
    struct node* j;
    if(h1->val <= h2->val){
        i = h1;
        j = h2;
    }else{
        i = h2;
        j = h1;
    }

    // The merging list is a 1-element list
    if(i->next == NULL){
        i->next = j;
        j->prev = i;
        return i;
    }

    
    struct node* head = i;
    // Merging j into i
    while(i!=NULL && j!=NULL){
        // Case: Both have the same val or it is greater than i but smaller equal than the next element.
        if(j->val >= i->val && j->val<=i->next->val){
            struct node* next_i = i->next;
            struct node* next_j = j->next;
            i->next = j;
            j->prev = i;
            j->next = next_i;
            j->next->prev = j;
            // We can fearless move i
            i = i->next;
            j = next_j;
        }else{
            // We can not merge anymore without moving i forward
            if(i->next == NULL)
                break;
            i = i->next;
        }
    }
    // We haven't finish entering j in i
    if(j!=NULL){
        i->next = j;
        j->prev = i;
    }

    return head;
        
}