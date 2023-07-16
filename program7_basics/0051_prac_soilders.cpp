/*
Requirement:

相传韩信才智过人， 从不直接清点自己军队的人数， 
只要让士兵先后以三人一排、 五人一排、 七人一排地变换队形， 而他每次只掠一眼队伍的排尾就知道总人数了。 

General Han wants to know how many soldiers there are in his troops. 
He asks them to stand in 3 per row, 5 per row and 7 per row.
He only looks at the the last row.
There are 2, 1 and 6 soldiers respectively. 
Then he knows the answer.

INPUT includes 3 int: a， b， c， 
which represents the total soldiers count of last row (a＜ 3， b＜ 5， c＜7） ， 

OUTPUT tells the min total soldiers count. The answer range is [10, 100]

Sample:

Input:
2 1 6
2 1 3

Output:
41
No answer

*/

#include <stdio.h>
#include <math.h>
#include <limits.h>

int main()
{

    /*
    Because the answer is within range [10, 100], so we can easily try all of them one by one.
    This algo is called: brute force / complete search
    */

    freopen("0051_input.txt", "r", stdin);

    int a, b, c;

    while(scanf("%d%d%d", &a, &b, &c) == 3) {

        bool found = false;

        for(int i = 10; i <= 100; i++) {
            if(i % 3 == a && i % 5 == b && i % 7 == c) {
                printf("%d\n", i);
                found = true;
                break;
            }
        }

        if(!found)
        printf("No Answer!\n");

    }

    return 0;
}
