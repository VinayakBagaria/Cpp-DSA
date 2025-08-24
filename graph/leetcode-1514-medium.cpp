// https://leetcode.com/problems/path-with-maximum-probability/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // succProb, u
    typedef pair<double, int> PP;

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // u -> {v, prob}
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<PP> pq;
        pq.push({1.0, start});
        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;

        while (!pq.empty()) {
            auto [prob, u] = pq.top();
            pq.pop();

            if (u == end) return prob;

            // Although this line is unnecessary, it just skips "bad pops" early.
            // If we know that current prob is not greater than 1 in the future which is gonna come later,
            // then don't process current node as future prob of this node will be better.
            if (prob < maxProb[u]) continue;

            for (auto& [v, w] : adj[u]) {
                double nextProb = prob * w;
                if (nextProb > maxProb[v]) {
                    maxProb[v] = nextProb;
                    pq.push({nextProb, v});
                }
            }
        }

        return 0.0;
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succ = {0.5, 0.5, 0.2};
    cout << sol.maxProbability(3, edges, succ, 0, 2) << endl;
    succ = {0.5, 0.5, 0.3};
    cout << sol.maxProbability(3, edges, succ, 0, 2) << endl;
}
