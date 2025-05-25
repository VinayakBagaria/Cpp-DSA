// https://leetcode.com/problems/sum-of-largest-prime-substrings/description/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPrime(ll num) {
    if (num < 2) {
        return false;
    }

    for (ll i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

long long sumOfLargestPrimes(string s) {
    unordered_set<ll> primes;
    for (int i = 0; i < s.size(); i++) {
        ll num = 0;
        for (int j = i; j < s.size(); j++) {
            num = (num * 10) + (s[j] - '0');
            if (isPrime(num)) {
                primes.insert(num);
            }
        }
    }

    vector<ll> ps(primes.begin(), primes.end());
    sort(ps.rbegin(), ps.rend());

    if (ps.size() < 3) {
        return accumulate(ps.begin(), ps.end(), 0ll);
    }
    return ps[0] + ps[1] + ps[2];
}


void doWork() {
    // cout << sumOfLargestPrimes("111") << endl;
    cout << sumOfLargestPrimes("6357501617") << endl;
}