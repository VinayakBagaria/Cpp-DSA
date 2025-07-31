// https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
#include <bits/stdc++.h>

using namespace std;


class Solution {
  public:
    int solve(int n, vector<int>& dp) {
        if (n == 0 || n == 1) {
            return 1;
        }
        
        if (dp[n] != -1) return dp[n];
        
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    int topDown(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
  
    int countWays(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};


void doWork() {
    Solution sol;
    cout << sol.countWays(2) << endl;
    cout << sol.topDown(2) << endl;
    cout << sol.countWays(4) << endl;
    cout << sol.topDown(4) << endl;
    cout << sol.countWays(18) << endl;
    cout << sol.topDown(18) << endl;
}