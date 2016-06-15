/*
Question:
=========
A palindrome is a string that reads the same forwards and backwards. Using only
a fixed number of stacks and queues, write an algorithm to determine if a string
is a palindrome
*/
// Author Lee Sutton
// The stack will be implemented in a header file "stack.h" as a class template.
// The main function in this program will test the stack features and implement
// the stack data structure will then be used to solve the palindrome problem

#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
  // Boolean to return if the word is a palindrome initially assumed to be true
  bool palindrome = true;

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

  // Now input a string and check if it is a palindrome
  // Take input from the user
  string user_input;
  cout << "Input a string: " << endl;
  cin >> user_input;
  cout << "You inputted: "<< user_input << endl;

  // If given more time i could add case sensitivity here use tolower

  // Now we run through the string to check if it is a palindrome
  // Start by creating a stack with a maxSize = the length of the string
  Stack<char> StringStack(user_input.length());

  // Create a for loop to run through the string and push all the characters
  // onto the stack
  for(int i = 0; i < user_input.length(); i++)
  {
    StringStack.push(user_input[i]);
  }

  // Create a for loop to run through and check if the input word is a palindrome
  for(int i = 0; i < user_input.length(); i++)
  {
    // If the letters arent equal, break from the loop and set the palindrome
    // boolean to false
    if(StringStack.pop() != user_input[i])
    {
      palindrome = false;
      break;
    }
  }

  cout << user_input << " is a palindrome? 1 = true, 0 = false" << palindrome << endl;

  return 0;
}
