// https://leetcode.com/problems/equal-row-and-column-pairs/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>> grid) {
        int n = grid.size();
        map<vector<int>, int> mp;

        for (int r = 0; r < n; r++) {
            mp[grid[r]]++;
        }
        
        int count = 0;
        for (int c = 0; c < n; c++) {
            vector<int> temp;
            for (int r = 0; r < n; r++) {
                temp.push_back(grid[r][c]);
            }
            count += mp[temp];
        }

        return count;
    }
};

void doWork() {
    Solution sol;
    cout << sol.equalPairs({{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}}) << endl;
}
