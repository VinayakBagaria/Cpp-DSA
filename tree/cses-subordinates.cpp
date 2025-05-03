// https://cses.fi/problemset/task/1674
#include <bits/stdc++.h>

using namespace std;

int dfs(int i, vector<int> &result, unordered_map<int, vector<int>> &adj) {
    int count = 0;
    for (int sub : adj[i]) {
        count += 1 + dfs(sub, result, adj);
    }
    result[i-1] = count;
    return count;
}

vector<int> calculateSubordinates(int n, unordered_map<int, vector<int>> &adj) {
    vector<int> result(n);
    dfs(1, result, adj);
    return result;
}

void doWork() {
    int n;
    cin >> n;

    unordered_map<int, vector<int>> adj;
    for (int i = 2; i <= n; i++) {
        int manager;
        cin >> manager;
        adj[manager].push_back(i);
    }

    vector<int> subs = calculateSubordinates(n, adj);
    for (int sub : subs) {
        cout << sub << " ";
    }
}