#include <bits/stdc++.h>
using namespace std;


int main() {

    int i1[2][3];

    int i2[2][3] = {{0, 1, 2}, {3, 4, 5}};

    int i3[2][3] = {0, 1, 2, 3, 4, 5}; // same as i2

    int i4[3][4];
    memset(i4, 0, sizeof(int) * 12);

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++)
            printf("%d\t", i4[i][j]);
        printf("\n");
    }


    return 0;
}