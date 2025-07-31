// https://www.geeksforgeeks.org/problems/geek-jump/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int solve(vector<int>& height, int i, vector<int>& dp) {
        int n = height.size();
        if (i == 0) {
            return 0;
        }
        
        if (dp[i] != 1e9) return dp[i];
        
        int mini = abs(height[i] - height[i - 1]) + solve(height, i - 1, dp);
        if (i >= 2) {
            mini = min(mini, abs(height[i] - height[i - 2]) + solve(height, i - 2, dp));
        }
        return dp[i] = mini;
    }

    int bottomUp(vector<int>& height) {
        int n = height.size();
        if (n == 1) return 0;

        vector<int> dp(n);
        dp[1] = abs(height[1] - height[0]);

        for (int i = 2; i < n; i++) {
            dp[i] = min(
                abs(height[i] - height[i - 1]) + dp[i - 1],
                abs(height[i] - height[i - 2]) + dp[i - 2]
            );
        }

        return dp[n-1];
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, 1e9);
        return solve(height, n-1, dp);
    }
};

void doWork() {
    Solution sol;
    vector<int> vec = {20, 30, 40, 20};
    cout << sol.minCost(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
    vec = {30, 20, 50, 10, 40};
    cout << sol.minCost(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
}