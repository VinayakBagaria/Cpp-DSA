// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int count = 0, day = events[0][0], i = 0;

        while (!pq.empty() || i < n) {
            // Add all events where start_day == current_day
            // as they can be done starting today
            // Mark all these end_days in the pq
            while (i < n && events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }

            // If we have some meetings in the pq whose end_day has not crossed,
            // then we can attend this meeting
            if (!pq.empty()) {
                // This popped meeting is done
                pq.pop();
                count++;
            }

            day++;

            // Remove from the heap all those meeting whose end_day is lesser
            // than current_day + 1. current_day processing is done.
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }

        return count;
    }
};

void doWork() {
    Solution sol;
    vector<vector<int>> vec = {{1, 2}, {2, 3}, {3, 4}};
    cout << sol.maxEvents(vec) << endl;
    vec = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
    cout << sol.maxEvents(vec) << endl;
}