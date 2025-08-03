// https://leetcode.com/problems/target-sum/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int i, int target, vector<unordered_map<int, int>>& dp) {
        if (i == 0) {
            if (target == 0 && nums[0] == 0) return 2;
            return abs(nums[i]) == abs(target) ? 1 : 0;
        }

        if (dp[i].find(target) != dp[i].end()) return dp[i][target];

        int add = solve(nums, i-1, target - nums[i], dp);
        int sub = solve(nums, i-1, target + nums[i], dp);
        return dp[i][target] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int, int>> dp(nums.size());
        return solve(nums, nums.size() - 1, target, dp);
    }
};

void doWork() {
    Solution sol;
    vector<int> vec = {1,1,1,1,1};
    cout << sol.findTargetSumWays(vec, 3) << endl;
    vec = {0};
    cout << sol.findTargetSumWays(vec, 0) << endl;
}
