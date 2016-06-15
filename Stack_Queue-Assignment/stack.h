// Create a stack class template to use in the palindrome algorithm
// The Stack implementation will use an array
// Author Lee Sutton
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
  };


};
