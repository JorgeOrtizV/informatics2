/*
onsider now an extended parenthesis sequence, which additionally allows square brackets: [].
The rules from a) for a valid sequence still apply here, with the additional constraint that each
opening parenthesis must have a corresponding closing parenthesis of the same type.
Examples of valid extended parenthesis sequences are:
• [()][]()
• [[()[()]]]
Examples of invalid sequences are:
• [[()]
• [(]) (incorrect type of opening and closing parentheses)
Write a function that checks whether an given extended sequence is valid. Can you extend your
approach from a) to also solve b)?

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
    char val;
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

char pop(struct node** S){
    if (is_empty(S)==true)
        return -1;
    
    char top_value = (*S)->val;
    struct node* mock = *S;
    *S = (*S)->next;
    free(mock);
    return top_value; 
}

void push(struct node** S, char x){
    // Case the stack is empty
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->val=x;
    n->next=(*S);
    *S = n;
}

char show(struct node** S){
    if(is_empty(S))
        return '!';
    return (*S)->val;
}

void print_stack_helper(struct node *node) {
    if (node != NULL) {
        print_stack_helper(node->next);
        printf("%d ", node->val);
    }
}

bool validSequence(char seq[], int length){
    int i = 0;
    struct node** s = init();
    while(i<length){
        char c = seq[i];
        //printf("%c\n", c);
        if(c=='(')
            push(s, c);
        else if(c=='[')
            push(s, c);
        else if(c==')'){
            char top_sym = show(s);
            if(top_sym == '('){
                char popped = pop(s);
                //printf("popped: %c\n", popped);
            }
            else
                return false;
        }
        else if(c==']'){
            char top_sym = show(s);
            if(top_sym == '['){
                char popped = pop(s);
                //printf("popped: %c\n", popped);
            }
            else
                return false;
        }
        i++;
    }
    if(is_empty(s))
        return true;
    return false;
}


int main(){
    char seq[] = "[(])";
    int length = (sizeof(seq)/sizeof(seq[0]))-1;
    bool valid = validSequence(seq, length);
    printf("%d", valid);
    return 0;
}