// https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>

using namespace std;

int solve(int i, int prev, vector<vector<int>>& points, vector<vector<int>>& dp) {
    if (i == points.size()) {
        return 0;
    }

    if (prev != -1 && dp[i][prev] != -1) return dp[i][prev];

    int cost = 0;
    
    for (int j = 0; j < 3; j++) {
        if (j == prev) {
            continue;
        }

        cost = max(cost, points[i][j] + solve(i + 1, j, points, dp));
    }

    return dp[i][prev] = cost;
}

int bottomUp(vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(3, -1));
    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];


    for (int i = 1; i < n; i++) {
        dp[i][0] = points[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = points[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = points[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }
    
    return max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
}

void doWork() {
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(3));
    for (auto &it: points) {
        cin >> it[0] >> it[1] >> it[2];
    }

    cout << bottomUp(points) << endl;

    vector<vector<int>> dp(n, vector<int>(3, -1));
    cout << solve(0, -1, points, dp) << endl;
}
