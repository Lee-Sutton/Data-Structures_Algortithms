// Implement an algorithm to  nd the nth to last element of a singly linked list
#include <stdio.h>
#include <stdlib.h>

// define a structure for a linked list
struct node{
  int item;
  struct node* next;
};

// Linked list constructor function
// Takes in a an item
// Uses malloc to create a linked list structure
// Returns a pointer to the address
// Sets the next item to null by default
struct node* LinkedList(int value){
  struct node* Node = malloc(sizeof(struct node));
  Node->item = value;
  Node->next = NULL;
  return Node;
  
}

int main(){
  // Initialize the index to be zero
  int i = 0;
  int list_size;

  // Prompt the user for list size
  printf("How big would you like the list to be: ");
  scanf("%d", &list_size);

  // Let's start by creating a linked list
  struct node* start = LinkedList(0);
  
  // Create a current_node pointer to use in the while loop
  // to create additional links
  struct node* current_node = start;
  
  while(i < list_size){
    current_node->next = LinkedList(i + 1);
    current_node = current_node->next;
    i++;
    
  }

  // prompt the user for the nth item
  int nth_item;
  printf("Please enter a number between 0 and %d: ", list_size);
  scanf("%d", &nth_item);

  // Run through the loop until we reach the nth item
  i = 0;
  current_node = start;
  while(i < nth_item && current_node->next){
    current_node = current_node->next;
    i++;
  }

  printf("The item in the %d node is: %d\n", nth_item, current_node->item);
  
}
