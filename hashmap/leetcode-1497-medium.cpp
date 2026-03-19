// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int> arr, int k) {
        unordered_map<int, int> mp;
        for (int x : arr) mp[(x % k + k) % k]++;

        if (mp[0] % 2 != 0) return false;

        // Actual logic is checking from remainders 1 to k-1
        // But after k/2, we would be checking the reverse counterpart - duplicates
        // so just loop from 1 to k/2.
        for (int remainder = 1; remainder <= k/2; remainder++) {
            int counterpart = k - remainder;
            if (mp[remainder] != mp[counterpart]) {
                return false;
            };
        }
        
        return true;
    }
};

void doWork() {
    Solution sol;
    cout << -3 % 5 << endl;
    // cout << sol.canArrange({1,2,3,4,5,10,6,7,8,9}, 5) << endl;
    // cout << sol.canArrange({1,2,3,4,5,6}, 7) << endl;
    // cout << sol.canArrange({1,2,3,4,5,6}, 10) << endl;
    cout << sol.canArrange({-1,1,-2,2,-3,3,-4,4}, 3) << endl;
}