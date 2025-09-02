// https://cses.fi/problemset/task/1619/
#include <bits/stdc++.h>

using namespace std;

// Whenever we encounter a starting point, a new customer has come
// Whenever an ending point is seen, a customer has left 
class Solution {
public:
    long long solve(vector<pair<int, int>>& events) {
        long long currCustomers = 0;
        long long maxi = 0;

        sort(events.begin(), events.end());

        for (auto& [val, increment] : events) {
            currCustomers += increment;
            maxi = max(maxi, currCustomers);
        }

        return maxi;
    }
};

void doWork() {
    int n;
    cin >> n;
    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        events.push_back({x, 1});
        events.push_back({y, -1});
    }
    Solution sol;
    cout << sol.solve(events) << endl;
}
