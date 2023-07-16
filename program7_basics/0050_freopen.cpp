#include <stdio.h>
#include <math.h>
#include <limits.h>

int main()
{

    freopen("0050_input.txt", "r", stdin); // read input from file instead of console
    freopen("0050_output.txt", "w", stdout); // write output to file instead of console
    // So that we don't need to type input manually each time when we run the program, make us programer's life easier

    int x, n = 0, min = INT_MAX, max = INT_MIN, s = 0;

   while(scanf("%d", &x) == 1) {
       s += x;
       if(x < min) min = x;
       if(x > max) max = x;
       n++;
   }

   printf("%d %d %.3f\n", min, max, (double)s/n); 

    return 0;
}
