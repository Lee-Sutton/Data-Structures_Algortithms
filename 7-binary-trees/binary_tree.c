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


// insert_node function:
//----------------------
//  Inserts the input node in the binary tree by traversing left if the node
//  is less than the current node or right if the node is greater.
//    root: pointer to root of the binary search tre
//    node_to_insert: node to insert in the binary search tree
void insert_node(struct node* root, struct node* node_to_insert){
  // Create a pointer to the store the current node as we traverse the tree
  struct node* current_node = root;

  // Store the previous node after we traverse past it
  struct node* previous_node;

  // Traverse the tree
  while(current_node){
    // If the node to insert is greater than the current node
    // we traverse to the right
    if(node_to_insert->item > current_node->item){
      previous_node = current_node;
      current_node = current_node->right;
    }
    else{
      previous_node = current_node;
      current_node = current_node->left;
    }
  }

  // Once we reach the end of the tree, we insert the node
  // it will be a child of the previous node
  if(node_to_insert->item > previous_node->item){
    previous_node->right = node_to_insert;
  }
  else{
    previous_node->left = node_to_insert;
  }

  return;
  
}


int main(){
  // Let's create a Binary search tree
  struct node* root = new_node(0);

  // Let's test the insert function
  insert_node(root, new_node(1));
  insert_node(root, new_node(2));
  insert_node(root, new_node(-5));
  insert_node(root, new_node(-1));
  insert_node(root, new_node(19));

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
