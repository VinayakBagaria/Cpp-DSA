// https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
    return p1.second <= p2.second;
}


class Solution {
  public:  
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int, int>> vec;
        int n = start.size();
        for (int i = 0; i < n; i++) {
            vec.push_back({start[i], finish[i]});
        }

        sort(vec.begin(), vec.end(), cmp);
        
        int lastTask = -1, result = 0;
        for (int i = 0; i < vec.size(); i++) {
            pair<int, int> task = vec[i];
            if (task.first > lastTask) {
                lastTask = task.second;
                result++;
            }
        }
        
        return result;
    }

    int activitySelection2(vector<int> &start, vector<int> &finish) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < start.size(); i++) {
            pq.push({finish[i], start[i]});
        }

        int lastTask = -1, result = 0;
        while (!pq.empty()) {
            pair<int, int> task = pq.top();
            pq.pop();
            if (task.second > lastTask) {
                lastTask = task.first;
                result++;
            }
        }
        return result;
    }
};

void doWork() {
    Solution obj;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    cout << obj.activitySelection(start, finish) << endl;
    cout << obj.activitySelection2(start, finish) << endl;
}