// https://leetcode.com/problems/number-of-islands
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

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

    void solveBfs(int i, int j, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        int r = grid.size(), c = grid[0].size();

        while (!q.empty()) {
            int ui = q.front().first, uj = q.front().second;
            q.pop();
            
            for (auto dir : directions) {
                int ni = ui + dir[0], nj = uj + dir[1];
                if (ni < 0 || ni >= r || nj < 0 || nj >= c) continue;
                if (grid[ni][nj] == '0') continue;

                grid[ni][nj] = '0';
                q.push({ni, nj});
            }
        }
    }
    
    int bfs(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    solveBfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        return bfs(grid);
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