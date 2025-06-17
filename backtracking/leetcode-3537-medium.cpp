#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    void solve(vector<vector<int>>& grid, int r, int c, int size, int& val) {
        if (size == 1) {
            grid[r][c] = val;
            val++;
            return;
        }

        int subGrid = size / 2;

        solve(grid, r, c + subGrid, subGrid, val); // TR
        solve(grid, r + subGrid, c + subGrid, subGrid, val);  // BR
        solve(grid, r + subGrid, c, subGrid, val); // TL
        solve(grid, r, c, subGrid, val); // Last corner of square
    }

public:
    vector<vector<int>> specialGrid(int n) {
        // 2^n elements
        int size = 1 << n;

        vector<vector<int>> grid(size, vector<int>(size));
        int val = 0;
        solve(grid, 0, 0, size, val);
        return grid;
    }
};

void doWork() {
    Solution sol;
    auto it = sol.specialGrid(1);
    cout << it[0][0] << endl;

    it = sol.specialGrid(2);
    cout << it[0][0] << endl;
}