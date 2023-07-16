#include <bits/stdc++.h>
using namespace std;

// perform select sort
void selectSort(int array[], int size) {

  for(int i = 0; i < size-1; i++) {

    int min_index = i;

    for(int j = i + 1; j < size; j++) {
      if(array[j] < array[min_index]) {
        min_index = j;
      }
    }

    swap(array[i], array[min_index]);
  }
  
}


// print array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}


int main() {
  int data[] = {1, 3, 5, 4, 2};
  
  // find array's length
  int size = sizeof(data) / sizeof(data[0]);
  
  selectSort(data, size);
  
  cout << "Sorted Array in Ascending Order:\n";  
  printArray(data, size);
}
