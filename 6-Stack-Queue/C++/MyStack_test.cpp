#include <iostream>

#include "MyStack.h"

using std::cout;
using std::endl;
 
void stackTest();
 
int main()
{
      stackTest();
}
 
void stackTest()
{
      MyStack st{};
 
      st.push(3);
      st.push(2);
      st.push(1);
 
      cout << st.pop() << " -- ";
      cout << st.pop() << " -- ";
      cout << st.pop() << endl << endl;
}
