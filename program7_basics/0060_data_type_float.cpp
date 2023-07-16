#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>

int main()
{

    /*
    -------------------
    float
    -------------------
    Q) Why is it called float? 
    A) Because 3.14
              = 0.314 * 10^1  <------
              = 0.0314 * 10^2
              = 31.4 * 10^-1

        The decimal point can float to anywhere we wants it to. 
        This is called scientific notation.
        So float numbers are ALL represented in scientific notation.
        So, float is intended to represent extremely small values as well as extremely large.

        We use 4 bytes(32 bits) to store a float value.
        In the 32 bits:
        1 bit sign      : store sign +/-
        8 bits exponent : store 1 -> the 1 in 10^1
        23 bits fraction: store 0.314

        because: we use only 23 bits to store the faction part
        so: we can only keep 6-7 signifcant figures.
    */

   float a = 123456789;
   printf("a=%f\n", a); // 123456792.000000 -> only the first 7 s.f. are reserved.
   printf("a=%e\n", a); 
   printf("a=%g\n", a); 

   float b = 1.2345678;
   printf("b=%f\n", b);
   printf("b=%e\n", b); 
   printf("b=%g\n", b); 

   /*
    %f  -> float 
    %e  -> scientific notation
    %g  -> choose a short one between %f and %e
   */

   printf("----------------------\n");




   printf("FLT_MAX   :   %e\n", FLT_MAX); 
   printf("FLT_MIN   :   %e\n", FLT_MIN); 

   printf("-FLT_MAX   :   %e\n", -FLT_MAX); 
   printf("-FLT_MIN   :   %e\n", -FLT_MIN); 


    // Positive float range: [1.2 * 10^-38, 3.4 * 10^38]
    // Negative float range: [-3.4 * 10^38, -1.2 * 10^-38]


}