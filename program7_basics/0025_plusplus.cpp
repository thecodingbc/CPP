#include <stdio.h>
#include <math.h>

int main()
{


    int i = 10;

    i++;
    printf("%d\n", i);

    ++i;
    printf("%d\n", i);

    i--;
    printf("%d\n", i);

    --i;
    printf("%d\n", i);

    // They are different when you put them on the right side of =



    // here: i is 10
    int j = i++;   // because i is in the front, so i value (10) is used first (assign to j), then i++
    printf("%d %d\n", i, j); // 11, 10


    // here i is 11
    int k = ++i;   // because ++ is in the front, so i++ (i becomes 12) first, then i value (12) is used (assign to j)
    printf("%d %d\n", i, k); // 12 12


    return 0;
}
