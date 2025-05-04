// https://cses.fi/problemset/task/1746/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int solve(vector<int> &arr, int n, int ub, int i, int prev, vector<vector<int>> &dp) {
    if (i >= n) {
        return 1;
    }

    if (dp[i][prev] != -1) {
        return dp[i][prev];
    }

    int result = 0;
    if (arr[i] != 0) {
        if ((prev == 0) || abs(arr[i] - prev) <= 1) {
            result = solve(arr, n, ub, i+1, arr[i], dp) % MOD;
        }
    } else {
        for (int k = 1; k <= ub; k++) {
            if ((prev == 0) || abs(k - prev) <= 1) {
                result += solve(arr, n, ub, i+1, k, dp);
                result %= MOD;
            }
        }
    }
    return dp[i][prev] = result;
}

int bottomUp(vector<int> &arr, int n, int ub) {
    vector<int> forward(ub + 1, 1);
    vector<int> curr(ub + 1, 0);

    for (int prev=0; prev <= ub; prev++) {
        forward[prev] = 1;
    }
    
    for (int i=n-1; i >= 0; i--) {
        for (int prev=0; prev <= ub; prev++) {
            int result = 0;
            if (arr[i] != 0) {
                if ((prev == 0) || abs(arr[i] - prev) <= 1) {
                    result = forward[arr[i]] % MOD;
                }
            } else {
                for (int k = 1; k <= ub; k++) {
                    if ((prev == 0) || abs(k - prev) <= 1) {
                        result += forward[k];
                        result %= MOD;
                    }
                }
            }
            curr[prev] = result;
        }
        forward = curr;
    }

    return forward[0];
}

void doWork() {
    int n, ub;
    cin >> n >> ub;
    vector<int> arr(n);
    for(int &x : arr) {
        cin >> x;
    }
    
    vector<vector<int>> dp(n + 1, vector<int>(ub + 1, -1));
    cout << solve(arr, n, ub, 0, 0, dp) << endl;
    cout << bottomUp(arr, n, ub) << endl;
}