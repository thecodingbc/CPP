#include <stdio.h>
#include <math.h>

int main()
{


    printf("example 1 ---------------------------\n");

    for(int i = 1; i <= 5; i++) {
        printf("%d\n", i);
    }

    /*
    IMPORTANCE!!! ---------------------------------------------
    for(init; condition; increment) {
        //for loop body
    }
    
    step 1) run init code
    step 2) check condition, if it is false -> for loop finishes.
    step 3) run for loop body
    step 4) run increment, go to step 2) 
    */

    printf("example 2 ---------------------------\n");

    int total = 0;

    for(int i = 100; i > 0; --i)
        total += i;

    printf("%d\n", total);


    printf("example 3: missing increment ---------------------------\n");
    for(int j = 0; j < 3;) {
        printf("No increment in for loop\n");
        j++;
    }


    printf("example 4: multiple statements ---------------------------\n");
    for(int a = 0, b = 1, c = 2; a < 3; a++, b++, c++)
        printf("%d + %d + %d = %d\n", a, b, c, a + b + c);



    printf("example 5: omit all 3 parts - dead loop!~ ---------------------------\n");

    int l = 0;
    for(;;) {
        l++;
        if (l == 3)
            continue;
        if(l > 5)
            break;

        printf("%d\n", l);
    }


    return 0;
}
