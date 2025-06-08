#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int x, int limit, vector<int>& result) {
        if (x > limit) {
            return;
        }

        result.push_back(x);

        for (int i = 0; i <= 9; i++) {
            dfs(x * 10 + i, limit, result);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i <= 9; i++){
            dfs(i, n, result);
        }
        return result;
    }
};

void doWork() {
    Solution sol;
    vector<int> result = sol.lexicalOrder(13);
    for (auto it : result) {
        cout << it << " ";
    }
    cout << endl;
}