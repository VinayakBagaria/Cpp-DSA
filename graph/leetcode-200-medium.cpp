#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solveDfs(int i, int j, vector<vector<char>>& grid) {
        int r = grid.size(), c = grid[0].size();
        if (i < 0 || i >= r || j < 0 || j >= c) return;
        if (grid[i][j] == '0') return;

        grid[i][j] = '0';
        solveDfs(i + 1, j, grid);
        solveDfs(i - 1, j, grid);
        solveDfs(i, j + 1, grid);
        solveDfs(i, j - 1, grid);
    }

    int dfs(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    solveDfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }

    int numIslands(vector<vector<char>>& grid) {
        return dfs(grid);
    }
};


void doWork() {
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    cout << sol.numIslands(grid) << endl;
    grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };
    cout << sol.numIslands(grid) << endl;
}