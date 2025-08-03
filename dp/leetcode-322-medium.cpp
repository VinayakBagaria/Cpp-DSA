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
};

void doWork() {
    Solution sol;
    vector<int> vec = {1,2,5};
    cout << sol.coinChange(vec, 11) << endl;
}
