#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

vector<int> countServers(int n, vector<vector<int>> &logs, int x, vector<int> &queries) {
    // sort on basis of ascending time
    sort(logs.begin(), logs.end(), cmp);

    // query -> index
    vector<pair<int, int>> times;
    for (int i = 0; i < queries.size(); i++) {
        times.push_back({queries[i], i});
    }
    sort(times.begin(), times.end());

    // unique server id -> count of occurrence of this server's log
    unordered_map<int, int> mp;
    vector<int> result(queries.size());
    int m = logs.size();

    int l = 0, r = 0;
    // l is start of window, r is end of window
    for (auto &t : times) {
        int endTime = t.first;
        int startTime = max(0, endTime - x);
        int index = t.second;

        // Expand right boundary of window till value of time in logs is less than end
        // Count all such servers as they are coming in the window
        while (r < m && logs[r][1] <= endTime) {
            mp[logs[r][0]]++;
            r++;
        }

        // Move left boundary of window till value of time in logs is less than start
        // Decrease all such servers as they are going out of window
        while (l < m && logs[l][1] < startTime) {
            mp[logs[l][0]]--;
            if (mp[logs[l][0]] == 0) {
                mp.erase(logs[l][0]);
            }
            l++;
        }

        // Remaining count of servers from the total lot are which are ideal b/w l-r window time duration
        result[index] = n - mp.size();
    }

    return result;
}


void doWork() {
    vector<vector<int>> logs = {{1,3},{2,6},{1,5}};
     vector<int>queries = {10, 11};
    vector<int> result = countServers(3, logs, 5, queries);
    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;
}
