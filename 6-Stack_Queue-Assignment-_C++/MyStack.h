#ifndef MY_STACK_HEADER
#define MY_STACK_HEADER

#include <memory>

class MyStack
{
public:
      //Default constructor
      //PRE:
      //POST: created empty stack of size 10
      MyStack() = default;
 
      //Constructor(int)
      //PRE:
      //PARAM: n - size of stack to be created
      //POST: created empty stack of size n
      MyStack(int n);
 
      //Insert
      //PRE: stack is not full
      //PARAM: x - value to be inserted
      //POST: x pushed on the stack top
      void push(int x);
 
      //Remove
      //PRE: stack is not empty
      //POST: value at the stack top removed and returned
      int pop();
 
private:
      int size {10};
      int top {0};
      std::unique_ptr<int[]> arr {std::make_unique<int[]>(size)};
};
#endif
