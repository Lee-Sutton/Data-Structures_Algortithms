#include "MyStack.h"

#include <stdexcept>
 
MyStack::MyStack(int n) : size{n}, arr{std::make_unique<int[]>(size)} {}
 
void MyStack::push(int x)
{
      if (top == size) {
            throw std::runtime_error("stack is full");
      }
      arr[top++] = x;
}
 
int MyStack::pop()
{
      if (top == 0) {
            throw std::runtime_error("stack is empty");
      }
      return arr[--top];
}
