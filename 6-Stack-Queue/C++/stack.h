// Create a stack class template to use in the palindrome algorithm
// The Stack implementation will use an array
// Author Lee Sutton
#include <assert.h>
template <typename E> class Stack
{
private:
  int top;
  int maxSize;
  E *listarray;

public:
  // Constructor
  Stack(int size)
  {
    maxSize = size;
    top = 0;
    listarray = new E[size];
  }

  // Destructor
  ~Stack()
  {
    delete[] listarray;
  }

  // Reinitialize with clear
  void clear()
  {
    // Reset the top to 0
    top = 0;
  }

  // Push function to add values to the array
  void push(const E& item)
  {
    // Check to make sure the stack is not full
    assert(top!=maxSize);
    // Add the item to the top of the list
    listarray[top] = item;
    top++;
  }

  // Pop the E element from the top
  E pop()
  {
    // Make sure the stack is not empty
    assert(top!=0);

    // Store the value at the top of the stack
    int topVal = listarray[top - 1] ;
    // Subtract one from the top value
    top = top - 1;
    return topVal;
  }

};
