// https://cses.fi/problemset/task/1141/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(vector<int>& vec) {
        int l = 0, r = 0, maxi = 0;
        // unordered_map can be used too. map to satisfy TLE constraint with O(n) sometimes with unordered_map vs O(log n)
        map<int, int> mp;

        while (r < vec.size()) {
            mp[vec[r]]++;

            while (mp[vec[r]] > 1) {
                mp[vec[l]]--;
                l++;
            }

            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};

void doWork() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto& it : vec) {
        cin >> it;
    }

    Solution sol;
    cout << sol.solve(vec) << endl;
}
