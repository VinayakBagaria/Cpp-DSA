// https://leetcode.com/problems/satisfiability-of-equality-equations
#include<bits/stdc++.h>

using namespace std;

class Dsu {
    vector<int> parent;
    vector<int> size;
    public:
        Dsu() {
            parent.resize(26);
            size.resize(26, 1);
            for (int i = 0; i < 26; i++) parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x) return x;

            return parent[x] = find(parent[x]);
        }

        void unionBySize(int u, int v) {
            int pu = find(u);
            int pv = find(v);

            if (pu == pv) return;

            if (size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        Dsu dsu;
        for (auto e : equations) {
            if (e[1] == '=') {
                dsu.unionBySize(e[0] - 'a', e[3] - 'a');
            }
        }
        
        for (auto e : equations) {
            if (e[1] == '!') {
                if (dsu.find(e[0] - 'a') == dsu.find(e[3] - 'a')) {
                    return false;
                }
            }
        }

        return true;
    }
};

void doWork() {
    Solution sol;
    vector<string> vec = {"a==b","b!=a"};
    cout << sol.equationsPossible(vec) << endl;
    vec = {"b==a","a==b"};
    cout << sol.equationsPossible(vec) << endl;
}