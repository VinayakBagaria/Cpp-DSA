// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int solve(int arrLen, string target, int pos, int ti, vector<vector<int>>& dp, vector<vector<int>>& freq) {
    if (ti == target.size()) {
        return 1;
    }

    if (pos == arrLen) {
        return 0;
    }

    if (dp[pos][ti] != -1) {
        return dp[pos][ti];
    }

    int count = solve(arrLen, target, pos + 1, ti, dp, freq);
    int charCount = freq[target[ti] - 'a'][pos];
    count += charCount * solve(arrLen, target, pos + 1, ti + 1, dp, freq);
    return dp[pos][ti] = count;
}

int numWays(vector<string>& words, string target) {
    int n = words[0].size();
    int m = target.size();

    vector<vector<int>> freq(26, vector<int>(n, 0));
    for (string word : words) {
        for (int i = 0; i < n; i++) {
            char ch = word[i];
            freq[ch - 'a'][i]++;
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(words[0].size(), target, 0, 0, dp, freq);
}

void doWork() {
    string arr[] = {"acca","bbbb","caca"};
    vector<string> words(begin(arr), end(arr));
    cout << numWays(words, "aba") << endl;
}