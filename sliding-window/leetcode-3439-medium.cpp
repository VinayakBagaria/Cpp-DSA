// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        // Get all free-time b/w each events
        vector<int> freeTime;
        freeTime.push_back(startTime[0]);
        for (int i = 1; i < n; i++) {
            freeTime.push_back(startTime[i] - endTime[i-1]);
        }
        freeTime.push_back(eventTime - endTime[n-1]);

        // Shifting required = k
        // Therefore, we need to combine (k + 1) free-time
        // 1 shift = F1 + F2, F2 + F3 ...
        int l = 0, r = 0, res = 0, curr = 0;
        while (r < freeTime.size()) {
            curr += freeTime[r];

            if (r - l + 1 > k + 1) {
                curr -= freeTime[l];
                l++;
            }

            res = max(res, curr);
            r++;
        }

        return res;
    }
};

void doWork() {
    Solution sol;
    vector<int> start = {1, 3};
    vector<int> end = {2, 5};
    cout << sol.maxFreeTime(5, 1, start, end) << endl;

    start = {18, 20};
    end = {20, 21};
    cout << sol.maxFreeTime(21, 2, start, end) << endl;

    start = {0, 17};
    end = {14, 19};
    cout << sol.maxFreeTime(34, 2, start, end) << endl;
}