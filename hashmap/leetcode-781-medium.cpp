// https://leetcode.com/problems/rabbits-in-forest/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int> answers) {
        unordered_map<int, int> mp;
        for (int x : answers) mp[x]++;

        int count = 0;
        for (auto &[color, freq] : mp) {
            int groupSize = color + 1;
            int groupCount = ceil((double) freq / groupSize);

            count += (groupCount * groupSize);
        }

        return count;
    }
};

void doWork() {
    Solution sol;
    cout << sol.numRabbits({1, 1, 2}) << endl;
    cout << sol.numRabbits({1, 0, 1, 0, 0}) << endl;
    cout << sol.numRabbits({10, 10, 10}) << endl;
}