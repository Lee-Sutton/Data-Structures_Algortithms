#include <stdio.h>
#include <stdlib.h>

struct node{
  int item;
  struct node* left;
  struct node* right;

};

// Create a constructor function for a new node
// Inputs:
// int value - item to be held at the node
// sets both the left and right child to NULL
// Returns a pointer to the newly created node
struct node* new_node(int value){
  struct node* Node = malloc(sizeof(struct node));
  Node->item = value;
  Node->left = NULL;
  Node->right = NULL;
  return Node;
}

// Inorder traversal
void inOrder(struct node* root){
  // Check if we have reached the end of the tree
  if(!(root)){
    return;
  }
  
  // Traverse to the left
  inOrder(root->left);
  printf("%d\n", root->item);

  // Traverse Right
  inOrder(root->right);
  return;

}


int main(){
  // Let's create a Binary search tree
  struct node* root = new_node(0);
  root->left = new_node(1);
  root->right = new_node(2);

  // Traverse the tree and print the value
  struct node* current_node = root;

  while(current_node){
    printf("%d\n", current_node->item);
    current_node = current_node->left;

  }

  // Let's try an inorder traversal
  // Traverse left node, current node, then the right node
  printf("Trying In order traversal\n");
  inOrder(root);
}
