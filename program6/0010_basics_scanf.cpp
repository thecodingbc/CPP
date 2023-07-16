#include <stdio.h>
#include <math.h>

int main()
{

    int a, b; // Declare 2 int variables

    /*
    scanf   means      read value from console, equals to input() of python
    %d %d   means      read 2 int value from console
    &a, &b  means      variable a's address and b's, that's where c/c++ will save the 2 int  values.
    */
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);

    return 0;
}

/*
IMPORTANCE!!---------------------------------------
1) a vs &a
   variable a is a pointer, which points to a box, which contains some value
   a  represents the value inside the box.
   &a represents the address of the box.
---------------------------------------------------
*/