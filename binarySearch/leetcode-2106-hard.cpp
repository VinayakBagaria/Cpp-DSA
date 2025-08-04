// https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        // Fruits till ith index
        vector<int> fruitPref(n);
        // All fruits[i][0] for lb & ub operations
        vector<int> positions(n);

        for (int i = 0; i < n; i++) {
            fruitPref[i] = fruits[i][1] + (i > 0 ? fruitPref[i-1] : 0);
            positions[i] = fruits[i][0];
        }

        int maxi = 0;

        for (int d = 0; d <= k/2; d++) {
            // case 1: go left first distance 'd' then right
            int remain = k - 2*d;
            int left = startPos - d;
            int right = startPos + remain;

            int lb = lower_bound(positions.begin(), positions.end(), left) - positions.begin();
            int ub = upper_bound(positions.begin(), positions.end(), right) - positions.begin() - 1;

            // Fruits in range [lb, ub]
            if (lb <= ub) {
                int fruitsCount = fruitPref[ub] - (lb > 0 ? fruitPref[lb-1] : 0);
                maxi = max(maxi, fruitsCount);
            }


            // case 2: go right first distance 'd' then left
            right = startPos + d;
            left = startPos - remain;

            lb = lower_bound(positions.begin(), positions.end(), left) - positions.begin();
            ub = upper_bound(positions.begin(), positions.end(), right) - positions.begin() - 1;

            if (lb <= ub) {
                int fruitsCount = fruitPref[ub] - (lb > 0 ? fruitPref[lb-1] : 0);
                maxi = max(maxi, fruitsCount);
            }
        }

        return maxi;
    }
};

void doWork(){
    Solution sol;
    vector<vector<int>> vec = {{2, 8}, {6, 3}, {8, 6}};
    cout << sol.maxTotalFruits(vec, 5, 4) << endl;
    vec = {{0, 9}, {4, 1}, {5, 7}, {6, 2}, {7, 4}, {10, 9}};
    cout << sol.maxTotalFruits(vec, 5, 4) << endl;
    vec = {{0, 3}, {6, 4}, {8, 5}};
    cout << sol.maxTotalFruits(vec, 3, 2) << endl;
}
