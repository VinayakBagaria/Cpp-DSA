// https://leetcode.com/problems/distant-barcodes
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> mp;
        for (int bar : barcodes) {
            mp[bar]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto [code, count] : mp) {
            pq.push({count, code});
        }

        vector<int> res(barcodes.size());
        int i = 0;

        while (!pq.empty()) {
            if (pq.size() == 1) {
                res[i++] = pq.top().second;
                pq.pop();
            } else {
                auto f = pq.top();
                pq.pop();
                auto s = pq.top();
                pq.pop();
                res[i++] = f.second;
                res[i++] = s.second;
                if (f.first > 1) pq.push({f.first-1, f.second});
                if (s.first > 1) pq.push({s.first-1, s.second});
            }
        }

        return res;
    }
};

void print(vector<int> result) {
    for (auto row : result) {
        cout << row << " ";
    }
    cout << endl;
}

void doWork() {
    Solution sol;
    vector<int> barcodes = {1,1,1,2,2,2};
    print(sol.rearrangeBarcodes(barcodes));
    barcodes = {1,1,1,1,2,2,3,3};
    print(sol.rearrangeBarcodes(barcodes));
}
