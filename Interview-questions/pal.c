#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char word[]){
  // Contains 1 if the input string is a palindrome
  // Start by assuming the word is a palindrome
  int palindrome = 1;

  // Index through each character in the word
  // The i index starts at the beginning of the word
  // The j index starts at the end of the word and works back
  int length = strlen(word);
  int i = 0;
  int j = length - 1;

  while(i < (length - 1) && palindrome){
    // Check if the letters are the same
    if(tolower(word[i]) != tolower(word[j])){
      palindrome = 0;
    }
    // i moves forward through the word
    // j moves backwards
    i++;
    j--;
  }

  return palindrome;

}

int main(){
  char word1[] = "Lee";
  char word2[] = "racecar";

  if(isPalindrome(word1)){
    printf("%s is a palindrome", word1);
  }

  if(isPalindrome(word2)){
    printf("%s is a palindrome\n", word2);
  }

  char* space1 = "abc";
  char* space2 = "abc";
  printf("The strcmp returns %d on two spaces\n", strcmp(space1, space2));

}
