#include <stdio.h>

int main() {
    int myInt;
    myInt = 0xFFFFFFE2;
    myInt = myInt << 2;
    printf("%d\n",myInt);

    return 0;
}
