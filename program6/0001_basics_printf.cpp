#include <stdio.h>

int main()
{

    // printf: it equals to print(f"") in python. f means 'formatted'
    printf("Hello C/C++!\n"); 

    printf("int: %d\n", 10);        // %d   : int placeholder -> int type
    printf("float: %f\n", 0.01);    // %f   ：decimal placeholder -> float type
    printf("float: %.2f\n", 0.01);  // %.2f ：2 s.f.

    printf("char: %c\n", 'A');      // %c   : character placeholder. We use single quote around char type.


    printf("Weird output! Because placeholders and values do not match!!! -----------------\n");
    printf("%f\n", 10); // use %d
    printf("%d\n", 0.5); // use %f
    printf("%d\n", 'A'); // use %c

    return 0;
}


/*
IMPORTANCE!!! -----------------------------------------------
1) C/C++ requires strict match between the placeholder and the value.
   %d -> int     d means decimal int (十进制整数)
   %f -> float   f means decimal (小数)
   %c -> char

2) \n : next line
3) C/C++ code ends with ;
-------------------------------------------------------------
*/