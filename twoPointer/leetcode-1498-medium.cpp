// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition
#include <bits/stdc++.h>

using namespace std;

class Solution {
    int M = 1e9 + 7;
public:
    vector<int> power(int n) {
        vector<int> exp(n);
        exp[0] = 1;

        for (int i = 1; i < n; i++) {
            exp[i] = (exp[i-1] * 2) % M;
        }

        return exp;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> exp = power(n);
        sort(nums.begin(), nums.end());

        int l = 0, r = n - 1;
        int result = 0;

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                int diff = r - l;
                result = (result + exp[diff]) % M;
                l++;
            } else {
                r--;
            }
        }

        return result;
    }
};

void doWork() {
    Solution sol;
    vector<int> vec = {3,5,6,7};
    cout << sol.numSubseq(vec, 9) << endl;
    vec = {3,3,6,8};
    cout << sol.numSubseq(vec, 10) << endl;
    vec = {2,3,3,4,6,7};
    cout << sol.numSubseq(vec, 12) << endl;
}