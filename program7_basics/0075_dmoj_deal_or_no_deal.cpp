/*
https://dmoj.ca/problem/ccc07j3
*/


#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <string.h>


int main()
{

    freopen("0075_input.txt", "r", stdin); // REMOVE THIS LINE WHEN YOU SUBMIT ONLINE


    // 10 dollar amount in 10 briefcases
    float money[] = {100.0, 500.0, 1000.0, 5000.0, 10000.0, 25000.0, 50000.0, 100000.0, 500000.0, 1000000.0};

    // find total sum of all 
    float sum = 0.0;
    for(int i = 0; i < 10; i++) {
        sum += money[i];
    }

    int total;
    scanf("%d", &total);

    float amount = 0.0;
    for(int i = 0; i < total; i++) {
        int index;
        scanf("%d", &index);
        amount += money[index-1];
    }

    float average = (sum - amount) / (10 - total);

    int offered;
    scanf("%d", &offered);

    if(offered > average)
        printf("deal");
    else
        printf("no deal");

    return 0;
}
