#include <bits/stdc++.h>
#define ll long long
using namespace std;


vector<int> sieveOfEratosthenes(int n) {

    // step 1) label ----------------------------------

    vector<bool> isPrime(n + 1, true);

    // check from 2 to n
    for(int i = 2; i * i <= n; i++) {
        // if i is prime
        if(isPrime[i]) {

            // mark all its multiples to non_prime
            // because 5 * 3 has been taken care of by 3, so we can just label from 5 * 5
            for(int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }


    // step 2) collect --------------------------------

    // define a result vector
    vector<int> primes;

    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}


int main() {

    ios_base::sync_with_stdio(false),cin.tie(0);//cin & cout are very slow, this line helps speed them up

    int n = 100;

    cout << "Prime numbers within " << n << " are: " << endl;

    vector<int> primes = sieveOfEratosthenes(n);

    for(int i : primes) {
        cout << i << " ";
    }

    return 0;
}