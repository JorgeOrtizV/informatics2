#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
  struct TreeNode* parent;
};

struct TreeNode* insert(struct TreeNode *root, struct TreeNode *parent, int val) {
  struct TreeNode* newTreeNode = NULL;
  if (root == NULL) {
    newTreeNode = malloc(sizeof(struct TreeNode));
    newTreeNode ->val = val;
    newTreeNode ->left = NULL;
    newTreeNode ->right = NULL;
    newTreeNode ->parent = parent;
    return newTreeNode;
  }
  if (val > root->val) {
    root->right = insert(root->right, root, val);
  } else {
    root->left = insert(root->left, root, val);
  }
  return root;
}

struct TreeNode* search(struct TreeNode* root, int val) {
  struct TreeNode* current = root;
  while (current != NULL && current->val != val) {
    if (val < current->val) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return current;
}


struct TreeNode* leftRotate(struct TreeNode* root, int key) {
    struct TreeNode* s = search(root, key);
    // Node not exists
    if(s == NULL)
        return root;
    struct TreeNode* parent = s->parent;
    struct TreeNode* t = s->right;

    // Check left children indeed exists, otherwise we can't rotate
    if(t==NULL){
        return root;
    }

    s->right = t->left;
    if(t->left != NULL)
        t->left->parent = s;

    t->parent = s->parent;
    if(parent == NULL){
        // We are dealing with root
        root = t;
    }else{
        if(parent->right == s)
            parent->right = t;
        else{
            parent->left = t;
        }
    }

    t->left = s;
    s->parent = t;

    return root;

}

struct TreeNode* rightRotate(struct TreeNode* root, int key) {
    struct TreeNode* t = search(root, key);
    // Node not exists
    if(t == NULL)
        return root;
    struct TreeNode* parent = t->parent;
    struct TreeNode* s = t->left;
    // Check left children indeed exists, otherwise we can't rotate
    if(s==NULL){
        return root;
    }
    t->left = s->right;
    if(s->right != NULL)
        s->right->parent = t;
    // Case node is the root

    if(parent == NULL){
        root=s;
    }else{
        s->parent = t->parent;
        if(t == parent->right)
            parent->right = s;
        else
            parent->left = s;
    }
    s->right = t;
    t->parent = s;

    return root;
}

void printTreeRecursive(struct TreeNode *root) {
  if (root == NULL)
    return;
  if (root->left != NULL) {
    printf("  %d -- %d\n", root->val, root->left->val);
    printTreeRecursive(root->left);
  }
  if (root->right != NULL) {
    printf("  %d -- %d\n", root->val, root->right->val);
    printTreeRecursive(root->right);
  }
}

void printTree(struct TreeNode* root) {
  printf("graph g {\n");
  printTreeRecursive(root);
  printf("}\n");
}

int main() {
  struct TreeNode* root = NULL;
  printf("Inserting: 4, 2, 3, 8, 6, 7, 9, 12, 1\n");
  root = insert(root, root,  4);
  root = insert(root, root, 2);
  root = insert(root, root, 3);
  root = insert(root, root, 8);
  root = insert(root, root, 6);
  root = insert(root, root, 7);
  root = insert(root, root, 9);
  root = insert(root, root, 12);
  root = insert(root, root, 1);
  printTree(root);
  root = leftRotate(root,8);
  printTree(root);
  root = rightRotate(root,4);
  printTree(root);
  return 0;
}