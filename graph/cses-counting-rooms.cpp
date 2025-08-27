#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(vector<vector<char>> &vec, int i, int j) {
        if (i < 0 || i >= vec.size() || j < 0 || j >= vec[0].size() || vec[i][j] == '#') {
            return;
        }

        vec[i][j] = '#';
        for (auto& it : directions) {
            int ni = i + it[0], nj = j + it[1];
            dfs(vec, ni, nj);
        }
    }

    int countRooms(vector<vector<char>> &vec) {
        int n = vec.size(), m = vec[0].size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vec[i][j] == '.') {
                    count++;
                    dfs(vec, i, j);
                }
            }
        }

        return count;
    }
};

void doWork() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> vec(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }
    Solution sol = Solution();
    cout << sol.countRooms(vec) << endl;
}