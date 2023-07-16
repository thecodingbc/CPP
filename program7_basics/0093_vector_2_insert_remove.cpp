#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v;

    cout << "vector size: " << v.size() << endl;

    printf("Vector size: %d\n", v.size());

    /*
    <<      stream insertion operator
    endl    equals to \n

    */

   // add at the back - O(1）------------------------
   v.push_back(5);
   v.push_back(7);
   v.push_back(9); // v is now [5, 7, 9]

   // access / modify - O(1) ------------------------
   cout << v[0] << '\t'    // \t means tab / table -> 制表符
        << v[1] << '\t'    
        << v[2] << '\t'    
        << endl; // 5 7 9  

   v[0] = 1;
   v[1] = 2; // v is now [1, 2, 9]

   cout << v[0] << '\t'    // \t means tab / table -> 制表符
        << v[1] << '\t'    
        << v[2] << '\t'    
        << endl; // 1 2 9  


   // remove the last - O(1) ------------------------------
   v.pop_back();  

   cout << v[0] << '\t'; // 1
   cout << v[1] << endl; // 2



   // insert at the 1st place - O(n) very slow -------------
   v.insert(v.begin(), 25);
   cout << v[0] << '\t'; // 25
   cout << v[1] << '\t'; // 1
   cout << v[2] << endl; // 2

   // delete element at the 1st place - O(n) very slow -------------
   v.erase(v.begin());
   cout << v[0] << '\t'; // 1
   cout << v[1] << endl; // 2


}

/*

API -------------------------------------

v.size()

v.push_back(1)      add 1 to the end
v.pop_back()        remove the last element


THERE IS NO
v.push_front()
v.pop_front()

v.insert(v.begin(), 4)  insert 4 at the 1st place           (very slow, all values behind need to move one by one)
v.erase(v.begin())      remove element at the 1st place     (very slow, all values behind need to move one by one)

*/