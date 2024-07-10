#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct TreeNode** init();
bool is_empty(struct TreeNode** t);
struct TreeNode** insert(struct TreeNode** root, int x);
struct TreeNode** del(struct TreeNode** root, int x);
void printTreeRecursive(struct TreeNode* root, int level);
void printTree(struct TreeNode* root);
void inorder_traverseTree(struct TreeNode* root);
void preorder_traverseTree(struct TreeNode* root);
void postorder_traverseTree(struct TreeNode* root);
void traverseTree(struct TreeNode* root);

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode** init(){
    struct TreeNode** root = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    *root=NULL;
    return root;
}

bool is_empty(struct TreeNode** t){
    return (*(t)==NULL);
}

struct TreeNode** insert(struct TreeNode** root, int x){

    struct TreeNode* parent = NULL;
    struct TreeNode* r = *root;

    while(r!=NULL){
        parent = r;
        if(r->val > x){
            r = r->left;
        }else{
            r = r->right;
        }
    }
    if(parent==NULL){
        // Empty tree
        *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*root)->val = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }else{
        struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        n->val = x;
        n->left = NULL;
        n->right = NULL;
        if(parent->val > x)
            parent->left = n;
        else
            parent->right = n;
    }

    return root;
}

struct TreeNode** del(struct TreeNode** root, int x){
    struct TreeNode* parent = NULL;
    struct TreeNode* r = *root;

    // Case: Tree is already empty
    if((*root) == NULL)
        return root;

    while(r != NULL && r->val != x){
        parent = r;
        if(r->val > x)
            r = r->left;
        else    
            r = r->right;
    }

    // If we didn't found the node
    if(r==NULL)
        return root;

    // Case 1: No children
    if(r->right==NULL && r->left==NULL){
        // Case 1.1 -> We are dealing with the root:
        if(parent == NULL){
            *root = NULL;
        }else{
            if(parent->right == r){
                parent->right = NULL;
            }else{
                parent->left = NULL;
            }
            free(r);
        }
    }else if(r->right == NULL){
        // Case we have left children, but not right children
        // Subcase: dealing with root.
        if(parent == NULL){
            *root = r->left;
        }else{
            if(parent->right == r){
                parent->right = r->left;
            }else{
                parent->left = r->left;
            }
        }
        free(r);
    }else if(r->left == NULL){
        // Case we have right children, but not left children
        // Subcase: dealing with root.
        if(parent == NULL){
            *root = r->right;
        }else{
            if(parent->right == r){
                parent->right = r->right;
            }else{
                parent->left = r->right;
            }
        }
        free(r);
    }else{
        // we have two children (A bit tricker)
        // Step 1: find max element in left sub tree
        struct TreeNode* p = r->left;
        struct TreeNode* q = r; // tracking p predecessor
        while(p->right !=NULL ){
            q=p;
            p = p->right;
        }

        if(parent == NULL){
            *root = p;
        }else if(parent->right = r){
            parent->right = p;
        }else
            parent->left = p;

        p->right = r->right;
        if(p!=q){
            q->right = p->left;
            q->left = r->left;
        }
        free(r);
    }
    return root;
}

void printTreeRecursive(struct TreeNode* root, int level){
    if(root == NULL){
        return;
    }else{
        if(root->left != NULL){
            printf("%d -- %d : %d\n", root->val, root->left->val, level);
        }
        if(root->right != NULL){
            printf("%d -- %d : %d\n", root->val, root->right->val, level);
        }
    }
    printTreeRecursive(root->left, level+1);
    printTreeRecursive(root->right, level+1);
}

void printTree(struct TreeNode* root){
    printf("graph g { \n");
    printTreeRecursive(root, 1);
    printf("}\n"); 
}

void inorder_traverseTree(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    inorder_traverseTree(root->left);
    printf("%d\n", root->val);
    inorder_traverseTree(root->right);
}

void preorder_traverseTree(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    printf("%d\n", root->val);
    preorder_traverseTree(root->left);
    preorder_traverseTree(root->right);
}

void postorder_traverseTree(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    postorder_traverseTree(root->left);
    postorder_traverseTree(root->right);
    printf("%d\n", root->val);
}

void traverseTree(struct TreeNode* root) {
    printf("Preorder traversal:\n");
    preorder_traverseTree(root);
    printf("\n");

    printf("Inorder traversal:\n");
    inorder_traverseTree(root);
    printf("\n");

    printf("Postorder traversal:\n");
    postorder_traverseTree(root);
    printf("\n");
}

void mirror(struct TreeNode* root){
    if(root==NULL)
        return;
    
    struct TreeNode* r = root;
    // Case no left and right children
    if(r->left==NULL && r->right==NULL)
        return;
    // Case only one children
    else if(r->left==NULL || r->right==NULL){
        if(r->left==NULL){
            r->left = r->right;
            r->right=NULL;
            mirror(r->left);
        }else{
            r->right = r->left;
            r->left =  NULL;
            mirror(r->right);
        }
    }
    // Case two children (we need a buffer node to swap)
    else{
        struct TreeNode* buffer = r->left;
        r->left = r->right;
        r->right = buffer;
        mirror(r->left);
        mirror(r->right);
    }
}

int main() {
   struct TreeNode** root = init();
   printf("Inserting: 9, 3, 10, 6, 12, 1, 8 sequentially\n");
   insert(root, 8);
   insert(root, 5);
   insert(root, 9);
   insert(root, 3);
   insert(root, 7);
   insert(root, 11);
   insert(root, 4);
   printTree(*root);
   printf("traverse: \n");
   traverseTree(*root);

   // Mirror the tree
   mirror(*root);
   printTree(*root);
   printf("traverse: \n");
   traverseTree(*root);
   return 0;
}

