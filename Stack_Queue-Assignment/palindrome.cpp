/*
Question:
=========
A palindrome is a string that reads the same forwards and backwards. Using only
a fixed number of stacks and queues, write an algorithm to determine if a string
is a palindrome
*/
// Author Lee Sutton

#include <iostream>
#include "stack.h"

using namespace std;

int main()
{

  // Testing the Constructor
  Stack<int> TestStack(10);

  // Testing Push
  TestStack.push(1);
  TestStack.push(2);

  // Testing pop
  cout << TestStack.pop() << endl;

  // Testing Constructor with characters
  Stack<char> charStack(10);

  // Testing Push
  charStack.push('a');
  charStack.push('b');

  // Testing pop
  cout << charStack.pop() << endl;

  return 0;
}
