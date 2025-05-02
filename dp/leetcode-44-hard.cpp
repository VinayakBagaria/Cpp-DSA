// https://leetcode.com/problems/wildcard-matching/
// https://www.youtube.com/watch?v=ZmlQ3vgAOMo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=35
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool solve(string &text, string &pattern, int p, int t, vector<vector<int>> &dp) {
        // text and pattern both over, then happy case
        if (p == 0 && t == 0) {
            return true;
        }

        // pattern got over, but text remains, then sad case
        if (p == 0 && t > 0) {
            return false;
        }

        // text got over, but pattern remains - check if pattern has only * left
        // for it to be happy case
        if (t == 0 && p > 0) {
            for (int i = 1; i <= p; i++) {
                if (pattern[i-1] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (dp[p][t] != -1) {
            return dp[p][t];
        }

        // go back 1 step on both cases
        if (pattern[p-1] == text[t-1] || pattern[p-1] == '?') {
            return dp[p][t] = solve(text, pattern, p-1, t-1, dp);
        }

        if (pattern[p-1] == '*') {
            return dp[p][t] = solve(text, pattern, p, t-1, dp) || solve(text, pattern, p-1, t, dp);
        }

        return dp[p][t] = false;
    }

    bool isMatchRecursion(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s, p, n, m, dp);
    }

    bool isMatchTabulation(string text, string pattern) {
        int m = text.size(), n = pattern.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for (int t = 1; t <= m; t++) {
            dp[0][t] = false;
        }

        for (int p=1; p <= n; p++) {
            bool flag = true;
            for (int i = 1; i <= p; i++) {
                if (pattern[i-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[p][0] = flag;
        }

        for (int p = 1; p <= n; p++) {
            for (int t = 1; t <= m; t++) {
                if (pattern[p-1] == text[t-1] || pattern[p-1] == '?') {
                    dp[p][t] = dp[p-1][t-1];
                } else if (pattern[p-1] == '*') {
                    dp[p][t] = dp[p][t-1] || dp[p-1][t];
                } else {
                    dp[p][t] = false;
                }
            }
        }

        return dp[n][m];
    }
};



void doWork() {
    Solution s;
    cout << s.isMatchRecursion("aa", "a") << endl;
    cout << s.isMatchTabulation("aa", "a") << endl;
    cout << s.isMatchRecursion("aa", "*") << endl;
    cout << s.isMatchTabulation("aa", "*") << endl;
    cout << s.isMatchRecursion("cb", "?a") << endl;
    cout << s.isMatchTabulation("cb", "?a") << endl;
    cout << s.isMatchRecursion("abdefcd", "ab*cd") << endl;
    cout << s.isMatchTabulation("abdefcd", "ab*cd") << endl;
}