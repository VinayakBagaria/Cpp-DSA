// https://cses.fi/problemset/task/1193/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<tuple<int, int, char>> directions = {{0, 1, 'R'}, {0, -1, 'L'}, {1, 0, 'D'}, {-1, 0, 'U'}};

    string getPath(vector<vector<char>> &vec) {
        int n = vec.size(), m = vec[0].size();
        queue<tuple<int, int, string>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vec[i][j] == 'A') {
                    q.push({i, j, ""});
                    break;
                }
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(m));

        while (!q.empty()) {
            auto [i, j, path] = q.front();
            q.pop();


            if (vec[i][j] == 'B') {
                return path;
            }

            if (visited[i][j]) continue;

            visited[i][j] = true;

            for (auto& [dx, dy, dir] : directions) {
                int ni = i + dx, nj = j + dy;
                if (ni < 0 || ni >= vec.size() || nj < 0 || nj >= vec[0].size() || vec[ni][nj] == '#' || vec[ni][nj] == 'A' || visited[ni][nj]) {
                    continue;
                }

                q.push({ni, nj, path + dir});
            }
        }

        return {};
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
    string path = sol.getPath(vec);
    if (path.size() == 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;
}
