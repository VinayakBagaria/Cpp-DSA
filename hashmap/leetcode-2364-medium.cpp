// https://leetcode.com/problems/count-number-of-bad-pairs/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long nc2(long n) {
        return n * (n - 1) / 2;
    }

    long long countBadPairs(vector<int> nums) {
        int n = nums.size();
        long long allPairs = nc2(n);

        unordered_map<int, long long> mp;
        long long good = 0;
        for (int i = 0; i < n; i++) {
            int key = i - nums[i];
            // “How many indices before me can form a good pair with me?”
            // For current index i, count how many j < i already satisfy the good pair condition.
            good += mp[key];
            mp[key]++;
        }

        return allPairs - good;
    }
};

void doWork() {
    Solution sol;
    cout << sol.countBadPairs({4,1,3,3}) << endl;
    cout << sol.countBadPairs({1,2,3,4,5}) << endl;
}
