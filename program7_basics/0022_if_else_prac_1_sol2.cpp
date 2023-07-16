#include <stdio.h>
#include <math.h>

int main()
{


    int a, b, c, t;
    scanf("%d%d%d", &a, &b, &c);

    if(a > b) {t = a; a = b; b = t;} // after this a < b
    if(a > c) {t = a; a = c; c = t;} // after this a < b and a < c
    if(b > c) {t = b; b = c; c = t;} // after this a < b < c
    printf("%d %d %d\n", a, b, c);

    return 0;
}


/*
1) there is no indentation rule in C/C++, you can merge multiple line of code into 1 line.
*/