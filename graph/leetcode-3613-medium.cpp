// https://leetcode.com/problems/minimize-maximum-component-cost/
#include <bits/stdc++.h>

using namespace std;

class Dsu {
    vector<int> parent;
    vector<int> size;

    public:
        Dsu(int n) {
            parent.resize(n);
            size.resize(n);
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int u) {
            if (parent[u] == u) return u;
            return parent[u] = find(parent[u]);
        }

        bool unionBySize(int u, int v) {
            int pu = find(u);
            int pv = find(v);

            if (pu == pv) return true;

            if (size[pu] < size[pv]) {
                size[pv] += size[pu];
                parent[pu] = pv;
            } else {
                size[pu] += size[pv];
                parent[pv] = pu;
            }

            return false;
        }
};

bool comp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        if (n <= k) return 0;

        sort(edges.begin(), edges.end(), comp);

        Dsu dsu(n);

        for (vector<int> edg : edges) {
            if (!dsu.unionBySize(edg[0], edg[1])) {
                n--;
            }

            if (n <= k) {
                return edg[2];
            }
        }

        return -1;
    }
};


void doWork() {
    Solution sol;
    vector<vector<int>> edges = {{0,1,4},{1,2,3},{1,3,2},{3,4,6}};
    cout << sol.minCost(5, edges, 2) << endl;
    edges = {{0,1,5},{1,2,5},{2,3,5}};
    cout << sol.minCost(4, edges, 1) << endl;
}
