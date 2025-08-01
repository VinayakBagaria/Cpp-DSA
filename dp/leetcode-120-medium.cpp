// https://leetcode.com/problems/unique-paths/description/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(int r, int c, int m, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (r < 0 || r >= m || c < 0 || c >= triangle[r].size()) return 1e9;
        if (r == m-1) return triangle[r][c];

        if (dp[r][c] != -1e9) return dp[r][c];

        return dp[r][c] = triangle[r][c] + min(solve(r + 1, c, m, triangle, dp), solve(r + 1, c + 1, m, triangle, dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1e9));
        return solve(0, 0, m, triangle, dp);
    }

    int bottomUp(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1e9));

        for (int r = m-1; r >= 0; r--) {
            int limit = triangle[r].size();
            for (int c = limit-1; c >= 0; c--) {
                if (r == m-1) {
                    dp[r][c] = triangle[r][c];
                } else {
                    int mini = dp[r + 1][c];
                    if (c + 1 < limit + 1) {
                        mini = min(mini, dp[r + 1][c + 1]);
                    }
                    dp[r][c] = triangle[r][c] + mini;
                }
            }
        }

        return dp[0][0];
    }

    int spaceBottomUp(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m-1].size();
        vector<int> prev(n, -1e9), curr(n, -1e9);

        for (int r = m-1; r >= 0; r--) {
            int limit = triangle[r].size();
            for (int c = limit-1; c >= 0; c--) {
                if (r == m-1) {
                    curr[c] = triangle[r][c];
                } else {
                    int mini = prev[c];
                    if (c + 1 < limit + 1) {
                        mini = min(mini, prev[c + 1]);
                    }
                    curr[c] = triangle[r][c] + mini;
                }
            }
            prev = curr;
        }

        return prev[0];
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << sol.minimumTotal(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
    cout << sol.spaceBottomUp(vec) << endl;
    vec = {{-1}, {-2, -3}};
    cout << sol.minimumTotal(vec) << endl;
    cout << sol.bottomUp(vec) << endl;
    cout << sol.spaceBottomUp(vec) << endl;
}