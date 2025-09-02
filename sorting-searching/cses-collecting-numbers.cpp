// https://cses.fi/problemset/task/2216/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(vector<int>& vec) {
        int n = vec.size();
        // number with its index
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) mp[vec[i]] = i;

        // If index of (X + 1) < X, it means we cannot collect this X and (X + 1) in 1 round.
        // If index is fine, we can collect both numbers in 1 round only.

        // Default round is 1, as we need atleast 1 round to collect all numbers from 1..N
        long long result = 1;
        for (int i = 1; i < n; i++) {
            if (mp[i + 1] < mp[i]) result++;
        }

        return result;
    }
};

void doWork() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto& it : vec) cin >> it;
    Solution sol;
    cout << sol.solve(vec) << endl;
}
