// https://leetcode.com/problems/meeting-rooms-iii/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    typedef pair<long long, int> P;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // End-Time + Room where this meeting is happening
        priority_queue<P, vector<P>, greater<P>> usedRooms;
        priority_queue<int, vector<int>, greater<int>> availableRooms;

        // Initially all rooms are available
        for (int i = 0; i < n; i++) availableRooms.push(i);
        vector<int> meetingCount(n, 0);

        for (auto &meet : meetings) {
            int start = meet[0], end = meet[1];
            int duration = end - start;

            // Remove all meetings+room combination
            // which have ended before this meeting can start
            // Denoting, when this meeting comes, those meetings are already over
            // During this process, some rooms might get available
            while (!usedRooms.empty() && usedRooms.top().first <= start) {
                int occupied = usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(occupied);
            }

            // If >= 1 room is available, that means choose the smallest one
            if (!availableRooms.empty()) {
                int smallest = availableRooms.top();
                availableRooms.pop();
                usedRooms.push({end, smallest});
                meetingCount[smallest]++;
            } else {
                // We don't have any room. So pick the one with the smallest end-time.
                // And add duration also. We add duration since we need to wait for 
                // current meeting to end
                long long firstToEnd = usedRooms.top().first;
                int firstRoomToEnd = usedRooms.top().second;
                usedRooms.pop();
                usedRooms.push({firstToEnd + duration, firstRoomToEnd});
                meetingCount[firstRoomToEnd]++;
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > meetingCount[result]) {
                result = i;
            }
        }
        return result;
    }
};



void doWork() {
    Solution sol;
    vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
    cout << sol.mostBooked(2, meetings) << endl;
    meetings = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
    cout << sol.mostBooked(3, meetings) << endl;
}
