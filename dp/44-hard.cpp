#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool solve(string &text, string &pattern, int t, int p, vector<vector<int>> &dp) {
        // text and pattern both over, then happy case
        if (t < 0 && p < 0) {
            return true;
        }

        // pattern got over, but text remains, then sad case
        if (p < 0 && t >= 0) {
            return false;
        }

        // text got over, but pattern remains - check if pattern has only * left
        // for it to be happy case
        if (t < 0 && p >= 0) {
            for (int i = 0; i <= p; i++) {
                if (pattern[i] != '*') {
                    return false;
                }
            }
            return true;
        }

        if (dp[t][p] != -1) {
            return dp[t][p];
        }

        // go back 1 step on both cases
        if (pattern[p] == text[t] || pattern[p] == '?') {
            return dp[t][p] = solve(text, pattern, t-1, p-1, dp);
        }

        if (pattern[p] == '*') {
            return dp[t][p] = solve(text, pattern, t, p-1, dp) || solve(text, pattern, t-1, p, dp);
        }

        return dp[t][p] = false;
    }

    bool isMatch(string s, string p) {
        int sSize = s.size();
        int pSize = p.size();
        vector<vector<int>> dp(sSize, vector<int>(pSize, -1));
        return solve(s, p, sSize-1, pSize-1, dp);
    }
};



void doWork() {
    Solution s;
    cout << s.isMatch("aa", "a") << endl;
    cout << s.isMatch("aa", "*") << endl;
    cout << s.isMatch("cb", "?a") << endl;
    cout << s.isMatch("abdefcd", "ab*cd") << endl;
}