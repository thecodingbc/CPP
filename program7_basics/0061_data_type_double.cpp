#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>

int main()
{

    /*
    double to float, is same as long long to int
    */

    double a, b;

    scanf("%lf", &a);
    printf("%f\n", a);

    /*
    IMPORTANCE!!! ----------------------
    for double variable:
    use %lf in scanf
    use %f in printf
    ------------------------------------
    */

    printf("DBL_MAX   :  %e\n", DBL_MAX);
    printf("DBL_MIN   :  %e\n", DBL_MIN);

    printf("-DBL_MAX   :  %e\n", -DBL_MAX);
    printf("-DBL_MIN   :  %e\n", -DBL_MIN);

    /*
    Positive double range: [2.2 * 10^-308, 1.8 * 10^308]
    Negative double range: [-1.8 * 10^308, -2.2 * 10^-308]
    s.f. around 15-16
    */

    return 0;
}