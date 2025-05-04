#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &prices, vector<int> &pages, int i, int sum, vector<vector<int>> &dp) {
    if (i >= prices.size()) {
        return 0;
    }

    if (sum == 0) {
        return 0;
    }

    if (sum < 0) {
        return INT_MIN;
    }

    if (dp[i][sum] != -1) {
        return dp[i][sum];
    }

    int take = 0;
    if (sum - prices[i] >= 0) {
        take = pages[i] + solve(prices, pages, i + 1, sum - prices[i], dp);
    }
    int notTake = solve(prices, pages, i + 1, sum, dp);
    return dp[i][sum] = max(take, notTake);
}

int bottomUp(vector<int> &prices, vector<int> &pages, int sum, int n) {
    vector<int> forward(sum+1, 0), curr(sum+1, 0);

    for (int i = n-1; i >= 0; i--) {
        for (int s = 1; s <= sum; s++) {
            int take = 0;
            if (s - prices[i] >= 0) {
                take = pages[i] + forward[s - prices[i]];
            }
            int notTake = forward[s];
            curr[s] = max(take, notTake);
        }
        forward = curr;
    }

    return forward[sum];
}

void doWork() {
    int n, sum;
    cin >> n >> sum;
    vector<int> prices(n);
    for (int &p : prices) {
        cin >> p;
    }

    vector<int> pages(n);
    for (int &p : pages) {
        cin >> p;
    }

    vector<vector<int>> dp(n, vector<int>(sum+1, -1));

    int ans = solve(prices, pages, 0, sum, dp);
    cout << ans << endl;
    cout << bottomUp(prices, pages, sum, n) << endl;
}