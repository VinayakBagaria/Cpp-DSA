// https://atcoder.jp/contests/dp/tasks/dp_a
#include <bits/stdc++.h>

using namespace std;


int solve(int i, vector<int>& vec, vector<int>& dp) {
    if (i == 0) {
        return 0;
    }

    if (dp[i] != -1) return dp[i];

    int cost = INT_MAX;

    cost = min(cost, abs(vec[i] - vec[i-1]) + solve(i - 1, vec, dp));
    if (i > 1) {
        cost = min(cost, abs(vec[i] - vec[i-2]) + solve(i - 2, vec, dp));
    }

    return dp[i] = cost;
}


void doWork() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &it : vec) {
        cin >> it;
    }

    vector<int> dp(n, -1);
    cout << solve(n-1, vec, dp) << endl;
}