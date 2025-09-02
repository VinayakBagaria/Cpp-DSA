// https://cses.fi/problemset/result/14399589/
#include <bits/stdc++.h>

using namespace std;

// Let's first solve the problem for two tasks and then we can extend it to all the tasks. Assume we have two tasks T1 and T2:
// If we perform T1 before T2, reward = (deadline(T1) - duration(T1)) + (deadline(T2) - duration(T1) - duration(T2)). 
// So, reward1 = deadline(T1) + deadline(T2) - 2 * duration(T1) - duration(T2)
// If we perform T2 before T1, reward = (deadline(T2) - duration(T2)) + (deadline(T1) - duration(T2) - duration(T1)). 
// So, reward2 = deadline(T1) + deadline(T2) - 2 * duration(T2) - duration(T1)
// From the above two formulas, we can say that the rewards will only differ according to the values of duration(T1) and duration(T2) 
// and are independent of whether deadline(T1) is greater or deadline(T2). 
// Since the duration of the task performed earlier is subtracted more times (twice) as compared to the duration of task performed later,
// we can conclude that the tasks with smaller duration should be performed first.
class Solution {
public:
    long long solve(vector<pair<int, int>>& vec) {
        sort(vec.begin(), vec.end());

        long long r = 0;
        long long time = 0;

        for (int i = 0; i < vec.size(); i++) {
            auto [duration, deadLine] = vec[i];
            time += duration;
            r += (deadLine - time);
        }

        return r;
    }
};

void doWork() {
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
        int dur, dead;
        cin >> dur >> dead;
        vec[i] = {dur, dead};
    }
    Solution sol;
    cout << sol.solve(vec) << endl;
}
