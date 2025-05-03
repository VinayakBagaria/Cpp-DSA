#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int solve(vector<int> &coins, int sum, vector<int> &dp) {
    if (sum == 0) {
        return 1;
    }

    if (sum < 0) {
        return 0;
    }

    if (dp[sum] != -1) {
        return dp[sum];
    }

    int ways = 0;
    for (int i = 0; i < coins.size(); i++) {
        ways += solve(coins, sum - coins[i], dp);
    }
    return dp[sum] = ways;
}

void doWork() {
    int count, sum;
    cin >> count >> sum;

    vector<int> coins(count);
    for (auto &x : coins) {
        cin >> x;
    }

    vector<int> dp(sum + 1);
    dp[0] = 1;
    for (int s = 1; s <= sum; s++) {
        for (int c : coins) {
            int diff = s - c;
            if (diff >= 0) {
                dp[s] += dp[diff];
                dp[s] %= MOD;
            }
        }
    }

    cout << dp[sum] << endl;
}