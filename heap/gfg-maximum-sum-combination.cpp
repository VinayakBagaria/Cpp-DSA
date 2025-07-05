// https://www.geeksforgeeks.org/problems/maximum-sum-combination/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        // sum, {i, j}
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> visited;
        vector<int> res;

        pq.push({a[0] + b[0], {0, 0}});
        visited.insert({0, 0});

        while (res.size() < k) {
            auto top = pq.top();
            pq.pop();
            int sum = top.first;
            int i = top.second.first, j = top.second.second;
            
            res.push_back(sum);
            
            if (i + 1 < n && visited.find({i + 1, j}) == visited.end()) {
                pq.push({a[i + 1] + b[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }
            
            if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }
        
        return res;
    }
};

void print(vector<int> vec) {
    for (int it : vec) cout << it << " ";
    cout << endl;
}

void doWork() {
    Solution sol;
    vector<int> vec1 = {3, 2}, vec2 = {1, 4};
    print(sol.topKSumPairs(vec1, vec2, 2));

    vec1 = {1, 4, 2, 3}, vec2 = {2, 5, 1, 6};
    print(sol.topKSumPairs(vec1, vec2, 3));
}