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


class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& adj, int n) {
        vector<int> indegree(n + 1);
        for (int u = 1; u <= n; u++) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int u = 1; u <= n; u++) {
            if (indegree[u] == 0) {
                q.push(u);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return topo;
    }

    vector<int> solve(vector<vector<int>>& adj, int n) {
        vector<int> topo = topoSort(adj, n);
        vector<int> dist(n + 1, -1), parent(n + 1, -1);
        
        dist[1] = 1;
        for (int u : topo) {
            if (dist[u] == -1) continue;

            for (int v : adj[u]) {
                if (dist[v] < dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                }
            }
        }

        return parent;
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

    // Algorithm: Longest Path from u to v in a directed acyclic graph
    // Find topo-sort of the graph.
    // Now, Process each node in the topo sort.
    // Find distance from point 1 to all the points in topo sort.
    // Points accessible from Node 1 will be marked with a distance. Other points in other graphs will have no distance marked.
    // If we don't find distance to a neighbour in topo-sort, it means that node is not accessible from 1.
    // Maximizing step: If we find a distance and that is more than what we have previously seen, 
    // update the max distance for this neighbour node. Also update new parent.
    Solution sol;
    vector<int> parent = sol.solve(adj, n);

    if (parent[n] == -1) {
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
