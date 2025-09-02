// https://cses.fi/problemset/task/1074/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long equalSteps(vector<int>& vec, int mid) {
        long long count = 0;
        for (int x : vec) count += abs(x - mid);
        return count;
    }

    long long solve(vector<int>& vec) {
        sort(vec.begin(), vec.end());
        int n = vec.size();

        vector<int> positions = {n/2};
        if (n % 2 == 0) {
            positions.push_back((n/2) + 1);
        }

        long long result = LLONG_MAX;
        for (int i : positions) {
            int median = vec[i];
            result = min(result, equalSteps(vec, median));
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
