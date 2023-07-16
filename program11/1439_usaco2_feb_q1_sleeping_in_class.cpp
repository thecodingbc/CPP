/*
http://www.usaco.org/index.php?page=viewproblem2&cpid=1203

Q Description:

1st line: T test cases
followed by T pairs of lines

For each test case:
1st line: N - total numbers
2nd line: the N numbers

Requirement: 
merge any adjacent 2 numbers
merge as less as possible, so that they are all equal.


----------------
analysis
----------------
the sum of all numbers should be divided as many groups as possible
so that, we merge as less as possible

It means, we need to find all the factors of the sum.
And we try from the smallest factor first -> brute force

*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;



vector<int> find_all_factors(int n) {

    vector<int> factors;

    for(int i = 1; i < n; i++) {

        if(i * i > n) {
            break;
        }

        if(n % i == 0) {
            factors.push_back(i);
            if(n / i != i) {
                factors.push_back(n / i);
            }
        }
    }

    sort(begin(factors), end(factors));

    return factors;
}

int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    // freopen("1439_usaco2_feb_q1_sleeping_in_class.txt", "r", stdin);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {

        int n;
        cin >> n;

        vector<int> v(n);

        int sum = 0;

        for(int j = 0; j < n; j++) {
            cin >> v[j];
            sum += v[j];
        }

        // find all factors
        vector<int> factors = find_all_factors(sum);
        
        // edge cases as promoted by the test case

        if(sum == 0) {
            cout << 0 << endl;
            continue;
        }

        // edge case: if sum is prime number

        if(factors.size() == 2) {

            bool all_1 = true;

            for(int x : v) {
                if(x != 1) {
                    all_1 = false;
                    break;
                }
            }

            if(!all_1) {
                cout << n -1 << endl;
            }
            else {
                cout << 0 << endl;
            }

            continue;
        }

        /*
        try from the smallest factors
        */
        for(int f : factors) {

            // step 4.1) define answer variable, this is what I am calculating
            int merge_count = 0;

            /*
            next I am going to merge all numbers in v into groups
            so that each group sum equals to f

            when group sum < f -> put next number to the group
            when group sum > f -> we cannot group numbers so that the group sum is f
            when group sum == f -> we calculate how many mergess are needed within the group, and start a new group

            */

            // step 4.2) these 2 var let me know, whether I can merge the numbers into one single number, which is f
            int group_element_count = 0;
            int group_sum = 0;

            // step 4.3) this flag tells me whether the whole grouping process is success or not
            bool merged_successfully = true; 

            // step 4.4) start merging
            for(int i : v) {
                
                // step 4.4.1) add i to the current group
                group_element_count++;
                group_sum += i;


                // case 1
                if(group_sum == f) {
                    // let's see how many merges are needed with this group
                    merge_count += (group_element_count -1);

                    // let's start a new group
                    group_element_count = 0;
                    group_sum = 0;
                }

                // case 2
                else if(group_sum > f) {
                    merged_successfully = false;
                    break;
                }

                // case 3
                // group_sum < f, then we do nothing, continue put next i to the group
            }

            // step 4.5)
            if(merged_successfully) {
                cout << merge_count << endl;
                break;
            }

        }

    }

    return 0;
}