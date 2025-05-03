// https://cses.fi/problemset/task/1636/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int solve(vector<int> &coins, int i, int sum, vector<vector<int>> &dp) {
    if (i >= coins.size()) {
        return 0;
    }

    if (sum == 0) {
        return 1;
    }

    if (sum < 0) {
        return 0;
    }

    if (dp[i][sum] != -1) {
        return dp[i][sum];
    }

    int stay = solve(coins, i, sum - coins[i], dp);
    int move = solve(coins, i+1, sum, dp);
    return dp[i][sum] = (stay + move) % MOD;
}

int bottomUp(vector<int> &coins, int sum) {
    int n = coins.size();

    vector<int> forward(sum+1, 0), curr(sum+1, 0);

    for (int i = 0; i < n; i++) {
        curr[0] = 1;
    }

    for (int i = n-1; i >= 0; i--) {
        for (int s = 1; s <= sum; s++) {
            int stay = 0;
            if (s - coins[i] >= 0) {
                stay = curr[s - coins[i]];
            }
            int move = forward[s];
            curr[s] = (stay + move) % MOD;
        }
        forward = curr;
    }

    return forward[sum];
}

void doWork() {
    int n, sum;
    cin >> n >> sum;

    vector<int> coins(n);
    for (auto &n : coins) {
        cin >> n;
    }

    vector<vector<int>> dp(n+1, vector<int>(sum + 1, -1));

    cout << solve(coins, 0, sum, dp) << endl;
    cout << bottomUp(coins, sum) << endl;
}