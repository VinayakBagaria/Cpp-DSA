// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> win;
        unordered_map<int, int> loss;
        for (auto &match : matches) {
            win[match[0]]++;
            loss[match[1]]++;
        }

        vector<int> a0, a1;
        for (auto &[person, count] : win) {
            if (loss.find(person) == loss.end()) {
                a0.push_back(person);
            }
        }

        for (auto &[person, count] : loss) {
            if (count == 1) {
                a1.push_back(person);
            }
        }

        sort(a0.begin(), a0.end());
        sort(a1.begin(), a1.end());
        return {a0, a1};
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
    vector<vector<int>> matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    print(sol.findWinners(matches));
}
