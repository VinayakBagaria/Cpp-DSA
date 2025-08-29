// https://cses.fi/problemset/task/1073/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(vector<int>& vec) {
        vector<int> mt;
        
        for (auto& it : vec) {
            auto ub = upper_bound(mt.begin(), mt.end(), it);
            if (ub == mt.end()) {
                mt.push_back(it);
            } else {
                *ub = it;
            }
        }

        return mt.size();
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
