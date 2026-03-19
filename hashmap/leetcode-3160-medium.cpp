// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>> queries) {
        unordered_map<int, int> nodeToColor;
        unordered_map<int, int> colorCount;

        vector<int> vec;

        for (auto& query : queries) {
            int node = query[0], color = query[1];

            int prevColor = nodeToColor[node];
            if (prevColor > 0) {
                // node has a previous color
                colorCount[prevColor]--;
                if (colorCount[prevColor] == 0) {
                    colorCount.erase(prevColor);
                }
            }

            nodeToColor[node] = color;
            colorCount[color]++;
            vec.push_back(colorCount.size());
        }

        return vec;
    }
};

void print(vector<int> result) {
    for (auto r : result) cout << r << " ";
    cout << endl;
}

void doWork() {
    Solution sol;
    print(sol.queryResults(4, {{1, 4}, {2, 5}, {1, 3}, {3, 4}}));
    print(sol.queryResults(4, {{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}}));
}
