// https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void generateSeries(vector<string> &series, string curr, char prev, int m) {
    int size = curr.size();
    if (size == m) {
        series.push_back(curr);
        return;
    }

    for (char c : {'R', 'G', 'B'}) {
        if (prev != c) {
            generateSeries(series, curr + c, c, m);
        }
    }
}

bool matchesStrings(string &prevSeries, string &currSeries) {
    for (int j = 0; j < prevSeries.size(); j++) {
        if (prevSeries[j] == currSeries[j]) {
            return false;
        }
    }

    return true;
}

int solve(int remainCols, int prevIdx, vector<string> &series, vector<vector<int>> &dp) {
    // all columns were filled with valid string series
    if (remainCols == 0) {
        return 1;
    }

    if (dp[prevIdx][remainCols] != -1) {
        return dp[prevIdx][remainCols];
    }

    int ways = 0;
    string prevSeries = series[prevIdx];

    for (int i = 0; i < series.size(); i++) {
        if (i == prevIdx) {
            continue;
        }

        // For every string in the series array,
        // check if its valid given the previous col's string
        string currSeries = series[i];
        bool isValid = matchesStrings(prevSeries, currSeries);

        if (isValid) {
            ways += solve(remainCols - 1, i, series, dp);
            ways %= MOD;
        }
    }

    return dp[prevIdx][remainCols] = ways;
}

int colorTheGrid(int m, int n) {
    vector<string> series;
    // First generate all "m" size-character strings, given the constraints of the string
    generateSeries(series, "", '.', m);
    vector<vector<int>> dp(series.size(), vector<int>(n, -1));

    int result = 0;
    
    // For every string of the series, try placing it on the first column; and recurse down
    for (int i = 0; i < series.size(); i++) {
        result += solve(n-1, i, series, dp);
        result %= MOD;
    }

    return result;
}

void doWork() {
    int m, n;
    cin >> m >> n;
    cout << colorTheGrid(m, n) << endl;
}