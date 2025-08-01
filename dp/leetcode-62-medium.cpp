// https://leetcode.com/problems/unique-paths/description/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(int r, int c, int m, int n, vector<vector<int>>& dp) {
        if (r == m-1 && c == n-1) return 1;
        if (r < 0 || r >= m || c < 0 || c >= n) return 0;

        if (dp[r][c] != -1) return dp[r][c];

        return dp[r][c] = solve(r + 1, c, m, n, dp) + solve(r, c + 1, m, n, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }
};

void doWork() {
    Solution sol;
    cout << sol.uniquePaths(3, 7) << endl;
    cout << sol.uniquePaths(3, 2) << endl;
}