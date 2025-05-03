// https://cses.fi/problemset/task/1633/
#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;

int dfs(int target, vector<int> &dp) {
    if (target < 0) {
        return -1;
    }

    if (target == 0) {
        return 1;
    }

    if (dp[target] != -1) {
        return dp[target];
    }

    int count = 0;
    for (int i = 1; i <= 6 && i <= target; i++) {
        count += dfs(target - i, dp);
        count %= MOD;
    }
    return dp[target] = count;
}


void doWork() {
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    cout << dfs(n, dp)<< endl;
}