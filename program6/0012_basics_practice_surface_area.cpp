/*
Requirement: 
Read from console radius and height of a cylinder, calculate the surface area of a cylinder.
*/


#include <stdio.h>
#include <math.h>

int main()
{

    double r, h, s1, s2, s; // step 1) declare variables

    const double pi = acos(-1.0); 
    
    scanf("%lf %lf", &r, &h);

    s1 = pi * r * r;
    s2 = 2 * pi * r * h;
    s = s1 * 2 + s2;

    printf("Area = %.3lf\n", s);

    return 0;
}

/*
IMPORTANCE!! -------------------------------------------
1) double means: double precision float type (双精度浮点数)

2）acos is the inverse map for cos
   cos(pi) = -1
   acos(-1) = pi

3) const means: constant. It means, once the variable has some value, you cannot change it anymore.

4) use %lf as placeholder for double type

5) %.3lf means keep 3 numbers after decimal point for the double variable
--------------------------------------------------------
*/