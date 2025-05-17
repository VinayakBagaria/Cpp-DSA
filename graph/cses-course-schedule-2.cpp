// https://cses.fi/problemset/task/1757/
#include<bits/stdc++.h>

using namespace std;


vector<int> courseSchedule(int n, vector<vector<int>> &adj, vector<int> &indegree) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> result;

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();

        result.push_back(u);

        for (auto &v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                pq.push(v);
            }
        }
    }

    return result;
}


void doWork() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n+1);
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }

    vector<int> result = courseSchedule(n, adj, indegree);
    for (int u : result) {
        cout << u << " ";
    }
    cout << endl;
}