// https://leetcode.com/problems/unique-number-of-occurrences/description/
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool uniqueOccurrences(vector<int> arr) {
        unordered_map<int, int> counts;
        for (int x : arr) counts[x]++;

        unordered_set<int> seen;

        for (auto &[key, count] : counts) {
            if (seen.count(count)) {
                return false;
            }
            seen.insert(count);
        }

        return true;
    }
};

void doWork() {
    Solution sol;
    cout << sol.uniqueOccurrences({1,2,2,1,1,3}) << endl;
    cout << sol.uniqueOccurrences({1,2}) << endl;
}
