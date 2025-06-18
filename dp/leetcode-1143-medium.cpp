#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int solve(int i, int j, int n, int m, string& t1, string& t2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        int result = 1e9;
        if (t1[i] == t2[j]) {
            result = 1 + solve(i - 1, j - 1, n, m, t1, t2, dp);
        } else {
            result = solve(i - 1, j, n, m, t1, t2, dp);
            result = max(result, solve(i, j - 1, n, m, t1, t2, dp));
        }

        return dp[i][j] = result;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, n, m, text1, text2, dp);
    }
};

void doWork() {
    Solution sol;
    cout << sol.longestCommonSubsequence("abcde", "ace") << endl;
    cout << sol.longestCommonSubsequence("abc", "abc") << endl;
    cout << sol.longestCommonSubsequence("abc", "def") << endl;
}
