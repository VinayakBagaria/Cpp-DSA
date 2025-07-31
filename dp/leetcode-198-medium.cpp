// https://leetcode.com/problems/house-robber/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i < 0) {
            return 0;
        }

        if (dp[i] != -1) return dp[i];

        int maxi = 0;
        for (int j = i - 2; j >= 0; j--) {
            maxi = max(maxi, solve(nums, j, dp));
        }
        return dp[i] = nums[i] + maxi;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return max(solve(nums, n-1, dp), solve(nums, n-2, dp));
    }
};

void doWork() {
    Solution sol;
    vector<int> vec = {1,2,3,1};
    cout << sol.rob(vec) << endl;
    // cout << sol.bottomUp(vec) << endl;
    vec = {2, 1, 4, 9};
    cout << sol.rob(vec) << endl;
    // cout << sol.bottomUp(vec) << endl;
    vec = {2,7,9,3,1};
    cout << sol.rob(vec) << endl;
}
