// https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    long long recurse(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return 0;

        long long sum = grid[i][j];
        grid[i][j] = 0;

        for (auto d : dirs) {
            int new_i = i + d[0];
            int new_j = j + d[1];
            sum += recurse(new_i, new_j, grid);
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                long long sum = recurse(i, j, grid);
                if (sum > 0 && sum % k == 0) count++;
            }
        }

        return count;
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{0,2,1,0,0},{0,5,0,0,5},{0,0,1,0,0},{0,1,4,7,0},{0,2,0,0,8}};
    cout << sol.countIslands(vec, 5) << endl;
    vec = {{3,0,3,0}, {0,3,0,3}, {3,0,3,0}};
    cout << sol.countIslands(vec, 3) << endl;
}