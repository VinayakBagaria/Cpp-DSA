// https://leetcode.com/problems/coin-change/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
        if (amount < 0) return 1e9;
        if (i == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            return 1e9;
        }

        if (dp[i][amount] != -1) return dp[i][amount];

        int take = 1e9;
        if (coins[i] <= amount) {
            take = 1 + solve(coins, amount - coins[i], i, dp);
        }
        int notTake = solve(coins, amount, i-1, dp);
        return dp[i][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int result = solve(coins, amount, coins.size() - 1, dp);
        return result == 1e9 ? -1 : result;
    }

    int bottomUp(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        for (int a = 0; a <= amount; a++) {
            dp[0][a] = (a % coins[0] == 0) ? a / coins[0] : 1e9;
        }
        
        for (int i = 1; i < n; i++) {
            for (int a = 0; a <= amount; a++) {
                int take = 1e9;
                if (coins[i] <= a) {
                    take = 1 + dp[i][a - coins[i]];
                }
                int notTake = dp[i-1][a];
                dp[i][a] = min(take, notTake);
            }
        }

        return dp[n-1][amount] == 1e9 ? -1 : dp[n-1][amount];
    }
};

void doWork() {
    Solution sol;
    vector<int> vec = {1,2,5};
    cout << sol.coinChange(vec, 11) << endl;
    cout << sol.bottomUp(vec, 11) << endl;
    vec = {1, 2};
    cout << sol.coinChange(vec, 2) << endl;
    cout << sol.bottomUp(vec, 2) << endl;
}
