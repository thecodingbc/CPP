#include <bits/stdc++.h>
using namespace std;



int main()
{

    int a[] = {1, 10, 6, 9, 8, 7, 0, 5, 3, 2};

    sort(a, a+10);
    // sort(a, a+10, less<int>());

    // sort(a+2, a+6);

    for(int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;


    int k = 7;

    if(binary_search(a, a+10, k))
        cout << k << " is in the array" << endl;
    else
        cout << k << " is NOT in the array" << endl;


    // sort in descending order ----------------------

    sort(a, a+10, greater<int>()); // template class instance for integer
    
    for(int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << endl;


    return 0;
}