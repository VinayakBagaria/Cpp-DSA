#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // {departure, room given} - figure out which room gets vacant the earliest
    typedef pair<int, int> PP;

    pair<int, vector<int>> solve(vector<pair<int, int>>& vec) {
        int n = vec.size();

        // {start, end, index}
        vector<tuple<int, int, int>> times(n);
        for (int i = 0; i < n; i++) {
            times[i] = {vec[i].first, vec[i].second, i};
        }
        sort(times.begin(), times.end());

        priority_queue<PP, vector<PP>, greater<PP>> occupiedRooms;
        int newRoom = 0;
        vector<int> res(n);

        // For every sorted room as per start time, allocate it:
        // 1. new room if we can
        // 2. existing room if something got unoccupied
        for (int i = 0; i < n; i++) {
            auto [arrival, dep, index] = times[i];

            // If departure time of already occupied rooms > Current room starting
            // Meaning an older room has not been emptied yet
            // So, we need a new room allocated
            if (occupiedRooms.empty() || occupiedRooms.top().first >= arrival) {
                newRoom++;
                occupiedRooms.push({dep, newRoom});
                res[index] = newRoom;
            } else {
                // Whatever was the first emptied room as per heap's departure time,
                // occupy that room
                int vacantRoom = occupiedRooms.top().second;
                occupiedRooms.pop();
                occupiedRooms.push({dep, vacantRoom});
                res[index] = vacantRoom;
            }
        }

        return {newRoom, res};
    }
};

void doWork() {
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec[i] = {a, b};
    }

    Solution sol;
    auto [totalRoomsUsed, res] = sol.solve(vec);
    cout << totalRoomsUsed << endl;
    for (auto& it : res) cout << it << " ";
}
