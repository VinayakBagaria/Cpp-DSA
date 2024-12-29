// https://codeforces.com/problemset/problem/112/A
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<string>& words, string target, int pos, int ti, vector<vector<int>>& dp) {
    if (ti == target.size()) {
        return 1;
    }

    if (pos == words[0].size()) {
        return 0;
    }

    if (dp[pos][ti] != -1) {
        return dp[pos][ti];
    }

    int count = solve(words, target, pos + 1, ti, dp);
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        if (word[pos] == target[ti]) {
            count += solve(words, target, pos + 1, ti + 1, dp);
        }
    }
    return dp[pos][ti] = count;
}

int numWays(vector<string>& words, string target) {
    int n = words[0].size();
    int m = target.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(words, target, 0, 0, dp);
}

void doWork() {
    string arr[] = {"acca","bbbb","caca"};
    vector<string> words(begin(arr), end(arr));
    cout << numWays(words, "aba") << endl;
}