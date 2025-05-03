#include <bits/stdc++.h>

using namespace std;

int MAXER = 1e8;

int solve(vector<int> &coins, int sum, vector<int> &dp) {
    if (sum == 0) {
        return 0;
    }

    if (sum < 0) {
        return MAXER;
    }

    if (dp[sum] != -1) {
        return dp[sum];
    }

    int ways = MAXER;
    for (int i = 0; i < coins.size(); i++) {
        ways = min(ways, 1 + solve(coins, sum - coins[i], dp));
    }
    return dp[sum] = ways;
}

void doWork() {
    int count, sum;
    cin >> count;
    cin >> sum;

    vector<int> coins(count);
    for (int i = 0; i < count; i++) {
        cin >> coins[i];
    }

    vector<int> dp(sum + 1, -1);
    int ans = solve(coins, sum, dp);
    cout << (ans >= MAXER ? -1 : ans) << endl;
}