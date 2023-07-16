#include <stdio.h>   
#include <math.h> 
#include <limits.h>

int main()
{

    freopen("0052_input.txt","r",stdin);

    float n, m;

    while(scanf("%f %f", &n, &m) == 2) {

        float result = 0;
        for(float i=n; i <=m; i++) {
            result += 1 / pow(i, 2); 
        }

        printf("%.5f\n", result);
    }

    return 0;
}

/*
Use float type instead of int to avoid value overflow
*/
