#include <stdio.h>
int main(){
    // Prompt the user to input 5 values
    int array[5];
    int *p = &array[0];
    printf("Enter 5 integers:\n");
    scanf("%d%d%d%d%d",p, p+1, p+2, p+3, p+4);
    printf("your numbers are:");
    int i = 0;
    while (i < 5){
        printf("%d\n", array[i]);
        i++;
    }
    printf("The reverse order of your numbers\n");
    i--;
    while(i >= 0){
        printf("%d\n", array[i]);
        i--;


    }
}