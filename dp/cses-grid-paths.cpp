// https://cses.fi/problemset/task/1638/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int solve(vector<vector<int>> &matrix, int r, int c, int n, vector<vector<int>> &dp) {
    if (r >= n || c >= n) {
        return 0;
    }

    if (matrix[r][c] == 1) {
        return 0;
    }

    if (r == n-1 && c == n-1) {
        return 1;
    }

    if (dp[r][c] != -1) {
        return dp[r][c];
    }

    return dp[r][c] = (solve(matrix, r+1, c, n, dp) + solve(matrix, r, c+1, n, dp)) % MOD;
}


void doWork() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < n; j++) {
            matrix[i][j] = input[j] == '*' ? 1 : 0;
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << solve(matrix, 0, 0, n, dp) << endl;
}