// https://leetcode.com/problems/binary-trees-with-factors/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int numFactoredBinaryTrees(vector<int> arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        unordered_map<int, long long> mp;

        for (int i = 0; i < n; i++) {
            int root = arr[i];
            mp[root] = 1;

            for (int j = 0; j < i; j++) {
                int leftChild = arr[j];
                int divisor = root / leftChild;

                if (root % leftChild == 0 && mp.find(divisor) != mp.end()) {
                    mp[root] += (mp[leftChild] * mp[divisor]);
                }
            }
        }

        long c = 0;
        for (auto &[k, v] : mp) {
            c = (c + v) % MOD;
        }

        return c;
    }
};

void doWork() {
    Solution sol;
    cout << sol.numFactoredBinaryTrees({2, 4}) << endl;
    cout << sol.numFactoredBinaryTrees({2, 4, 5, 10}) << endl;
    cout << sol.numFactoredBinaryTrees({2, 4, 8}) << endl;
}
