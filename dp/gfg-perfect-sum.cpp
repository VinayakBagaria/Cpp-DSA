#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int solve(vector<int>& arr, int target, int i, vector<vector<int>>& dp) {
        if (target == 0) return 1;
        if (i == 0) return arr[0] == target ? 1 : 0;

        if (dp[i][target] != -1) return dp[i][target];

        int take = 0;
        if (arr[i] <= target) {
            take = solve(arr, target - arr[i], i - 1, dp);
        }
        int notTake = solve(arr, target, i - 1, dp);
        return dp[i][target] = take + notTake;
    }
  
    int perfectSum(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
        return solve(arr, target, arr.size() - 1, dp);
    }
};

void doWork() {
    Solution sol;
    vector<int> vec = {5, 2, 3, 10, 6, 8};
    cout << sol.perfectSum(vec, 10) << endl;
    vec = {2, 5, 1, 4, 3};
    cout << sol.perfectSum(vec, 10) << endl;
    vec = {28, 4, 3, 27, 0, 24, 26, 24};
    cout << sol.perfectSum(vec, 24) << endl;
}