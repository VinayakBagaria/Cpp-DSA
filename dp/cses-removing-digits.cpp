// https://cses.fi/problemset/task/1637/
#include <bits/stdc++.h>

using namespace std;

vector<int> calculate(int n) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n%10);
        n /= 10;
    }

    return digits;
}

int solve(int n, vector<int> &dp) {
    if (n == 0) {
        return 0;
    }

    if (n < 0) {
        return INT_MAX;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    vector<int> digits = calculate(n);
    int ways = INT_MAX;
    for (int d : digits) {
        if (n - d < 0 || d == 0) {
            continue;
        }
        ways = min(ways, 1 + solve(n - d, dp));
    }

    return dp[n] = ways;
}

void doWork() {
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    cout << solve(n, dp) << endl;
}