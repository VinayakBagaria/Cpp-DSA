// https://leetcode.com/problems/house-robber/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if (i < 0) {
            return 0;
        }

        int take = nums[i];
        if (i > 1) take += solve(nums, i-2, dp);
            
        int notTake = solve(nums, i-1, dp);
        return dp[i] = max(take, notTake);
    }

    int bottomUp(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if (i > 1) take += dp[i-2];
            
            int notTake = dp[i-1];
            dp[i] = max(take, notTake);
        }

        return dp[n-1];
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
    cout << sol.bottomUp(vec) << endl;
    vec = {2, 1, 4, 9};
    cout << sol.rob(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
    vec = {2,7,9,3,1};
    cout << sol.bottomUp(vec) << endl;
    cout << sol.rob(vec) << endl;
}
