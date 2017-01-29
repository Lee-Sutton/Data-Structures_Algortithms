#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
  const char* string1 = "Foo";
  char string2[] = "bar";

  // print the strings before modifying them
  printf("The first string is: %s\n", string1);
  printf("The second string is %s\n", string2);

  // Make a copy of the first string
  char string1_copy[strlen(string1)];
  strcpy(string1_copy, string1);

  // Now change the last character to uppercase
  int length1 = strlen(string1);
  int length2 = strlen(string2);
  string1_copy[length1 - 1] = toupper(string1_copy[length1 - 1]);
  string2[length2 - 1] = toupper(string2[length2 - 1]);
  printf("String 1 is now: %s\n", string1_copy);
  printf("String 2 is now %s\n", string2);

}
