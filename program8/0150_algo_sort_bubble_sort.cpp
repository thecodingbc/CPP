#include <bits/stdc++.h>
using namespace std;


void bubbleSort(int array[], int size) {


    // step 1) if we have 5 numbers, we loop 4 times to find the 4 biggest numbers
    for(int i = 0; i < size - 1; i++) {

        //to find the 0th biggest number, we need to 4(5-1-0) times
        //to find the 1st biggest number, we need to 3(5-1-1) times
        //to find the 2nd biggest number, we need to 2(5-1-2) times

        for(int j = 0; j < size - 1 - i; j++) {

            if(array[j] > array[j+1]) {


                // solution 1)
                // int tmp = array[j];
                // array[j] = array[j+1];
                // array[j+1] = tmp;

                // solution 2)
                swap(array[j], array[j+1]);


            }


        }


    }

}



// print array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << " " << array[i];
    }
    cout << "\n";
}


int main() {

    int data[] = {5, 8, 6, 3, 9, 2, 1, 7};

    int size = sizeof(data) / sizeof(data[0]);

    bubbleSort(data, size);

    cout << "Sorted array in ascending order: " << endl;
    printArray(data, size);


    return 0;
}

/*
IMPORTANCE!!! ----------------------------------------
bubble sort core logic:
each loop, find the biggest number in the remaining numbers, move to the end.

1) outer loop: loop i size-1 times.     because, the one left is the smallest in the front.
2) inner loop: loop j size-1-i times.
------------------------------------------------------
*/