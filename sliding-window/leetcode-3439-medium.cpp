// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(n+1, 0);
        gaps[0] = startTime[0];
        gaps[n] = eventTime - endTime[n-1];

        for (int i = 1; i < n; i++) {
            gaps[i] = startTime[i] - endTime[i-1];
        }

        int sum = 0;
        for (int i = 0; i <= k; i++) sum += gaps[i];

        int maxi = sum;
        for (int i = k + 1; i < gaps.size(); i++) {
            sum -= gaps[i-k-1];
            sum += gaps[i];
            maxi = max(maxi, sum);
        }
        return maxi;
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