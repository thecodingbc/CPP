/*

https://dmoj.ca/problem/coci17c1p1

*/

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <string.h>


int main()
{

    // Step 0) Prepare IO ----------------
    freopen("0077_input.txt", "r", stdin); 

    // Step 1) Prepare the data -------------------------

    // I need to know how many cards each value has, so that I can tell, whether the good card is more or less than the bad card.

    // Because the 52 cards can possibly be in 9 value：2 - 11
    // I define an int aray to remember: how many cards each value has
    // to make my life easier, I define an array of size 12, and I keep the fisst 2 values unused.
    int values[12];

    values[0] = 0;
    values[1] = 0;

    // each value contains at least 4 cards
    for(int i=2; i < 12; i++)
        values[i] = 4;
    
    values[10] = 16;

    // Step 2) mimic the whole process -------------------

    int drawn;
    scanf("%d", &drawn);

    int total = 0;

    int x = 0;

    for(int i= 0; i < drawn; i++) {
        scanf("%d", &x);
        values[x] -= 1;
        total += x;
    }

    int diffTo21 = 21 - total;

    int p = 0, q = 0;
    // p - bad cards ; q - good cards

    for(int i =0; i < 13; i++) {
        if(i <= diffTo21)
            q += values[i];
        else
            p += values[i];
    }

    if(p >= q)
        printf("DOSTA");
    else
        printf("VUCI");

    return 0;
}

/*
IMPORTANCE!!! -------------------------------
1) You can declare a bigger array, use only part of it. 
   So that you can make both the array's index and value meaningful to the question.
   here array index -> cards value
        array value -> total count of the cards of the cards value


2) mimic the whole process. This algo is called 'mimic algo'.
*/