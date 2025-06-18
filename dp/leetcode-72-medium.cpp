// https://leetcode.com/problems/edit-distance/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        if (j == word2.size()) {
            return word1.size() - i;
        }

        if (i == word1.size()) {
            return word2.size() - j;
        }

        if (dp[i][j] != -1) return dp[i][j];

        int result = 1e9;
        // Replace word1[i] with word2[j]
        if (word1[i] == word2[j]) {
            result = min(result, solve(i + 1, j + 1, word1, word2, dp));
        } else {
            result = min(result, 1 + solve(i + 1, j + 1, word1, word2, dp));
        }

        // Remove word1[i]
        result = min(result, 1 + solve(i + 1, j, word1, word2, dp));

        // Insert word1[i]
        result = min(result, 1 + solve(i, j + 1, word1, word2, dp));

        return dp[i][j] = result;
    }

public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return solve(0, 0, word1, word2, dp);
    }
};


void doWork() {
    Solution sol;
    cout << sol.minDistance("horse", "ros") << endl;
    cout << sol.minDistance("intention", "execution") << endl;
    cout << sol.minDistance("", "a") << endl;
}
