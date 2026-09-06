// https://leetcode.com/problems/k-closest-points-to-origin
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef pair<long long, int> PP;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<PP, vector<PP>> pq;
        for (int i = 0; i < points.size(); i++) {
            auto p = points[i];
            long long dist = (p[0] * p[0]) + (p[1] * p[1]);
            pq.push({dist, i});

            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }

        return res;
    }
};

void print(vector<vector<int>> result) {
    for (auto row : result) {
        for (auto e : row) {
            cout << e << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void doWork() {
    Solution sol;
    vector<vector<int>> points = {{1,3},{-2,2}};
    print(sol.kClosest(points, 1));
    points = {{3,3},{5,-1},{-2,4}};
    print(sol.kClosest(points, 2));
}
