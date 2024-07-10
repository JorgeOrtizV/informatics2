#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct month{
    int month_number;
    char *month_name;
    struct month *next;
};

struct month *init_months(struct month *head) {
    int n = 12;
    int init_order[n];
    char *month_strings[] = {"January",   "February", "March",    "April",
                             "May",       "June",     "July",     "August",
                             "September", "Oktober",  "November", "Dezember"};
    struct month *h;
    struct month *p; /* trailing pointer */

    /* create random order with fisher-yates shuffle */
    for (int i = 0; i < n; ++i) {
        init_order[i] = i + 1;
    }
    srand(time(0));
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1); /* generate random index below i */
        /* swap a[i] with a[j] */
        int tmp = init_order[i];
        init_order[i] = init_order[j];
        init_order[j] = tmp;
    }

    /* create month linked list */
    h = malloc(sizeof(struct month)); /* first node, gets returned */
    h->month_number = init_order[0];  /*  */
    h->month_name = month_strings[h->month_number - 1];
    p = h; /* pointer that goes through list */
    for (int i = 1; i < n; ++i) {
        struct month *m = malloc(sizeof(struct month));
        /* printf("create month %d\n", i); */
        m->month_number = init_order[i];
        m->month_name = month_strings[m->month_number - 1];
        p->next = m; /* previous node points now to this */

        p = m; /* increment trailing pointer */
    }
    p->next = NULL;
    return h;
}

void free_months(struct month *head) {
    /* free month linked list */
    struct month *p = head;
    struct month *q = head->next;
    while (q) {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}

void print_months(struct month *head) {
    /* TODO: Implement task 2.(a) */
    struct month* p;
    p = head;
    while(p->next){
        printf("%s : %d\n", p->month_name, p->month_number);
        p = p->next;
    }
}

struct month* getPrevMonth(struct month *head, struct month *m){
    if (head == NULL || m == NULL) {
        return NULL;
    } else if (head->next == m) {
        return head;
    }

    struct month *p;
    p = head;

    while(p->next != m){
        p = p->next;
    }
    return p;
}

struct month* swapMonth(struct month *head, struct month *a, struct month *b){
    if(a == b)
        return head;
    else if(a == head){
        // Case a and b are adjacent
        if(a->next == b){
            a->next = b->next;
            b->next = a;
            head = b;
        }else{
            // Case not adjacent
            struct month* prev_b = getPrevMonth(head, b);
            struct month* next_a = a->next;
            prev_b->next = a;
            a->next = b->next;
            b->next = next_a;
            head = b;
        }
    }else if(a->next=b){
        struct month* prev_a = getPrevMonth(head, a);
        a->next = b->next;
        b->next=a;
        prev_a->next=b;
    }else{
        struct month* prev_a = getPrevMonth(head, a);
        struct month* prev_b = getPrevMonth(head, b);
        struct month* next_a = a->next;
        a->next = b->next;
        b->next = next_a;
        prev_a->next = b;
        prev_b->next = a;
    }
    return head;
}

int length(struct month *head){
    struct month* p;
    p = head;
    int len = 0;
    while(p != NULL){
        len++;
        p = p->next;
    }
    return len;
}

struct month* selection_sort(struct month *head){
    struct month *i;
    struct month *j;
    struct month *min;

    i = head;
    while(i!=NULL){
        min = i;
        j = i->next;
        while(j!=NULL){
            if(j->month_number < min->month_number)
                min = j;
            j = j->next;
        }
        head = swapMonth(head, i, min);
        i = min->next;
    }
    return head;
}




int main(){
    struct month *head;
    head = init_months(head);

    print_months(head);


    return 0;
}