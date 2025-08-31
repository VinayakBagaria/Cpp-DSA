// https://cses.fi/problemset/task/1680/
#include <bits/stdc++.h>

using namespace std;

class TLESolution {
public:
    vector<int> solve(vector<vector<int>>& adj, int n) {
        queue<int> q;
        q.push(1);

        vector<int> result;
        vector<int> dst(n + 1, -1), parent(n + 1, -1);
        dst[1] = 1;
        parent[1] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == n) {
                continue;
            }

            int newCount = dst[u] + 1;
            for (auto& v : adj[u]) {
                if (dst[v] < newCount) {
                    dst[v] = newCount;
                    parent[v] = u;
                    q.push({v});
                }
            }
        }

        return dst[n] == -1 ? vector<int>{} : parent;
    }
};

void doWork() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    TLESolution sol;
    vector<int> parent = sol.solve(adj, n);

    if (parent.size() == 0) {
        cout << "IMPOSSIBLE";
        return;
    }

    stack<int> st;
    int x = n;
    while (x != -1) {
        st.push(x);
        x = parent[x];
    }

    cout << st.size() << endl;

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
