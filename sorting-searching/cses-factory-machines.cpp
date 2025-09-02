// https://cses.fi/problemset/task/1620
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<long long>& machines, int t, long long mid) {
        long long sum = 0;
        for (auto& mac : machines) {
            sum += (mid / mac);
            if (sum >= t) return true;
        }
        return false;
    }

    long long solve(vector<long long>& machines, int t) {
        long long low = 1, high = *min_element(machines.begin(), machines.end()) * t;
        long long ans;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (check(machines, t, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

void doWork() {
    int n, t;
    cin >> n >> t;
    vector<long long> vec(n);
    for (auto& it : vec) cin >> it;
    Solution sol;
    cout << sol.solve(vec, t) << endl;
}
