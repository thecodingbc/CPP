/*
https://dmoj.ca/problem/coci18c2p1
*/

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <string.h>


int main()
{


    // Step 0) Prepare IO ------------------------
    freopen("0080_input.txt", "r", stdin); // REMOVE THIS LINE WHEN YOU ACTUALLY SUBMIT ONLINE

    // Step 1) Prepare the data -----------------

    // Step 1.1) design data structure

    // because there are 2 teams, max there are 2880 seconds.
    // I can create 2 arrays both size 3000, and I put init value 0 into them
    int a_score_list[3000] = {0}, b_score_list[3000] = {0}; 
    // when team a gets a score at second 5, I set a_score_list[5]=1
    // when team b gets a score at second 10, I set b_score_list[10]=1

    // Step 1.2) load data from input to my data structure

    int a_score_total = 0, a_score_second = 0;
    scanf("%d", &a_score_total);

    for(int i = 0; i < a_score_total; i++) {
        scanf("%d", &a_score_second);
        a_score_list[a_score_second] = 1;
    }

    int b_score_total = 0, b_score_second = 0;
    scanf("%d", &b_score_total);

    for(int i = 0; i < b_score_total; i++) {
        scanf("%d", &b_score_second);
        b_score_list[b_score_second] = 1;
    }


    // Step 2) Find Result ------------------------

    int total_score_first_half = 0, turnaround = 0;

    int a_score = 0, b_score = 0;

    char lead_previously = 0, lead_now = 0;

    bool it_scores = false;

    for(int i = 0; i < 3000; i++) {

        it_scores = false; // no team scores for the second

        if(a_score_list[i] == 1) { // team a scores
            it_scores = true;
            a_score++;
        }
        else if(b_score_list[i] == 1) { // team b scores
            it_scores = true;
            b_score++;
        }

        if(it_scores) { // some team scores
            if(i <= 1440)
                total_score_first_half++;

            if(a_score > b_score)
                lead_now = 'a';
            else if(a_score < b_score)
                lead_now = 'b';

            if(lead_previously=='a' && lead_now == 'b')
                turnaround++;
            else if(lead_previously=='b' && lead_now == 'a')
                turnaround++;

            lead_previously = lead_now;
        }
    }

    printf("%d\n", total_score_first_half);
    printf("%d\n", turnaround);

    return 0;
}