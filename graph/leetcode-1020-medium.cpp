// https://leetcode.com/problems/number-of-enclaves/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int dfs(int i, int j, vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        if (i < 0 || i >= r || j < 0 || j >= c) return 1e9;
        if (grid[i][j] == 0) return 0;

        grid[i][j] = 0;
        int sum = 1;
        bool isFalsy = false;

        for (auto& d : directions) {
            int child = dfs(i + d[0], j + d[1], grid);
            if (child == 1e9) isFalsy = true;
            else sum += child;
        }

        return isFalsy ? 1e9 : sum;
    }

    int numEnclavesDfs(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int result = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    int count = dfs(i, j, grid);
                    if (count != 1e9) {
                        result += count;
                    }
                }
            }
        }
        return result;
    }

    // Multi-source BFS
    // Start from boundary cells with 1
    // Traverse from all these points
    // The rest remaining would be unreachable from boundary
    // Basically: Just reverse the question ideology
    int numEnclavesBfs(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if ((i == 0 || i == r - 1 || j == 0 || j == c - 1) && grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            int i = q.front().first, j = q.front().second;
            q.pop();

            for (auto& d : directions) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && ni < r - 1 && nj >= 0 && nj < c - 1 && grid[ni][nj] == 1) {
                    q.push({ni, nj});
                    grid[ni][nj] = 0;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) count++; 
            }
        }
        return count;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        return numEnclavesBfs(grid);
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> grid = {{0,0,0,1,1,1,0,1,0,0},{1,1,0,0,0,1,0,1,1,1},{0,0,0,1,1,1,0,1,0,0},{0,1,1,0,0,0,1,0,1,0},{0,1,1,1,1,1,0,0,1,0},{0,0,1,0,1,1,1,1,0,1},{0,1,1,0,0,0,1,1,1,1},{0,0,1,0,0,1,0,1,0,1},{1,0,1,0,1,1,0,0,0,0},{0,0,0,0,1,1,0,0,0,1}};
    cout << sol.numEnclaves(grid) << endl;
    grid = {{0,0,0,0}, {1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout << sol.numEnclaves(grid) << endl;
}
