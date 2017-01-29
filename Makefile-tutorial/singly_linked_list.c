#include <stdio.h>
// Create a data structure for the linked list
struct node{
  int item;
  struct node* next;
};

struct linked_list{
  struct node* head;
};

int main(){
  // Create a linked list
  struct node first_item = {1, NULL};
  struct node second = {2, NULL};
  struct node third = {3, NULL};
  struct node fourth = {4, NULL};
  struct linked_list list = {&first_item};
  first.next = &second;
  second.next = &third;
  third.next = &fourth;

  // create a node to run through the linked list
  int size = 0;
  struct node* current_node = list.head;
  while(current_node){
    printf("The current node item %d\n",current_node->item);
    current_node = current_node->next;
  }
  return 0;
}
