// https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>

using namespace std;

int solve(int i, vector<int>& vec, int k, vector<int>& dp) {
    if (i == 0) {
        return 0;
    }

    if (dp[i] != -1) return dp[i];

    int cost = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (i - j < 0) {
            break;
        }
        
        cost = min(cost, abs(vec[i] - vec[i-j]) + solve(i-j, vec, k, dp));
    }
    return dp[i] = cost;
}


void doWork() {
    int n, k;
    cin >> n >> k;
    
    vector<int> vec(n);
    for (auto &it : vec) {
        cin >> it;
    }

    vector<int> dp(n, -1);
    cout << solve(n-1, vec, k, dp) << endl;

    dp.clear();
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int cost = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                cost = min(cost, abs(vec[i] - vec[i-j]) + dp[i-j]);
            }
        }

        dp[i] = cost;
    }


    cout << dp[n-1] << endl;
}