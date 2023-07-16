#include <stdio.h>
#include <math.h>

int main()
{

    int grade, average, total = 0, counter = 0;

    while(counter <= 4) {
        printf("%s", "enter grade: ");
        scanf("%d", &grade);
        total += grade;
        counter++;
    }

    average = total / counter;
    printf("Class average is %d\n", average);

    return 0;
}
