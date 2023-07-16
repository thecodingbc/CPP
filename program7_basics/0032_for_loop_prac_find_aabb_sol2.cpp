#include <stdio.h>
#include <math.h>

int main()
{


    for(int i = 1 ; ; i++) { // this equals to while True, as the condition in the middle doesn't exist

        int j = i * i;

        if(j < 1000) continue;
        if(j > 9999) break;

        int hi = j / 100; 
        int lo = j % 100;

        if(hi / 10 == hi % 10 && lo / 10 == lo % 10) 
        printf("%d\n", j);

    }




    return 0;
}