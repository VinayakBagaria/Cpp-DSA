// https://leetcode.com/problems/count-nice-pairs-in-an-array/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;

    int doReverse(int x) {
        int res = 0;
        while (x != 0) {
            res = (res * 10) + (x % 10);
            x /= 10;
        }
        return res;
    }

    int countNicePairs(vector<int> nums) {
        vector<int> reversed;
        for (int x : nums) {
            reversed.push_back(doReverse(x));
        }

        unordered_map<int, long long> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i] - reversed[i]]++;
        }

        long long count = 0;
        for (auto &[k, v] : mp) {
            if (v > 1) {
                long long pairs = v * (v - 1) / 2;
                count = (count + pairs) % MOD;
            }
        }
        return count;
    }
};

void doWork() {
    Solution sol;
    cout << sol.countNicePairs({42,11,1,97}) << endl;
    cout << sol.countNicePairs({13,10,35,24,76}) << endl;
}
