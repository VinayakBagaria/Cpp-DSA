// https://cses.fi/problemset/task/1202/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef pair<long long, int> PP;

    tuple<long long, int, int, int> solve(vector<vector<pair<int, int>>>& adj, int n) {
        vector<long long> dist(n + 1, LLONG_MAX);
        vector<int> minPath(n + 1, INT_MAX), 
                    maxPath(n + 1, -1), 
                    count(n + 1, 0);

        priority_queue<PP, vector<PP>, greater<PP>> pq;
        dist[1] = 0;
        count[1] = 1;
        minPath[1] = 0;
        maxPath[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u]) continue;

            for (auto [v, wt] : adj[u]) {
                long long newDist = dist[u] + wt;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    count[v] = count[u];
                    minPath[v] = minPath[u] + 1;
                    maxPath[v] = maxPath[u] + 1;
                    pq.push({newDist, v});
                } else if (dist[v] == newDist) {
                    count[v] += count[u];
                    count[v] %= MOD;
                    minPath[v] = min(minPath[v], minPath[u] + 1);
                    maxPath[v] = max(maxPath[v], maxPath[u] + 1);
                }
            }
        }

        return {dist[n], count[n], minPath[n], maxPath[n]};
    }
};

void doWork() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    Solution sol;
    auto [a, b, c, d] = sol.solve(adj, n);
    cout << a << " " << b << " " << c << " " << d;
}
