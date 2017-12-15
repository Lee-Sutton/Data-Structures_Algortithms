#include <iostream>
using namespace std;

class Node{
public:
  int item;
  Node* next_node;
  Node();
  Node(int value);
};

Node::Node(){
  item = 0;
  next_node = NULL;
}

Node::Node(int value){
  item = value;
  next_node = NULL;
}


/* Stack class
 * -----------
 * 
 * top: Pointer to the top Node
 * pop(): Function to pop the top item off the stack
 * add_item(): adds the input Node to the top of the stack
 * isEmpty(): returns bool indicating if the stack is empty
 *
*/
class Stack{
private:
  Node* top;

public:
  Node* pop();
  void add_item(Node* node);
  bool isEmpty();
  Stack();

};

Stack :: Stack(){
  // Initialize an empty stack
  top = NULL;
}

bool Stack:: isEmpty(){
  bool isempty;
  if(!top){
    isempty = true;
  }

  else{
    isempty = false;
  }
  return isempty;
}

Node* Stack :: pop(){
  // Temp variable to hold the top node
  Node* top_temp;

  // First check if the stack is empty
  if (isEmpty()){
    return NULL;
  }
  // Remove the top item from the stack
  top_temp = top;
  top = top->next_node;
  return top_temp;
  
}

void Stack :: add_item(Node* node){
  // This node will be placed on top of the current top node
  node->next_node = top;
  top = node;
  return;
}


/* main()
 * ------
 * 
 * Main function to test the stack class
*/
int main(){
  // Create a stack and test it out
  Stack test_stack = Stack();

  // Test the isempty function
  if (test_stack.isEmpty()){
    cout << "The stack is empty" << endl;
  }
  else{
    cout << "The stack is not empty" << endl;
  }

  // Test the add_item function
  Node* node = new Node(0);
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node * node3 = new Node(3);
  Node * node4 = new Node(4);

  // Add these nodes to the stack
  test_stack.add_item(node);
  test_stack.add_item(node1);
  test_stack.add_item(node2);
  test_stack.add_item(node3);
  test_stack.add_item(node4);

  // Test the pop function
  cout << (test_stack.pop())->item << endl;
  cout << (test_stack.pop())->item << endl;
  cout << (test_stack.pop())->item << endl;
  cout << (test_stack.pop())->item << endl;
  cout << test_stack.isEmpty() << endl;
  
  return 0;

}
