#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>

int main()
{

    int i1[5]; // declare only, must specify size, unless you init it.

    int i2[] = {1, 2, 3, 4, 5}; // declare and init, size is 5

    float f1[5] = {1.1, 1.2, 1.3}; // declare a float array, size is 5, and only assign the first 3 values, c fills in the rest 2 with 0.0

    float f2[5] = {0.0}; 

    printf("--------------array f1 is: \n");
    for(int i = 0; i < 5; i++)
        printf("%.1f\n", f1[i]);

    printf("--------------array f2 is: \n");
    for(int i = 0; i < 5; i++)
        printf("%.1f\n", f2[i]);

    scanf("%d", &i2[2]);
    scanf("%d", &i2[3]);

    printf("--------------array i1 is: \n");
    for(int i = 0; i < 5; i++)
        printf("%d\n", i2[i]);


    return 0;
}