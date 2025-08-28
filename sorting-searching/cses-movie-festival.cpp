// https://cses.fi/problemset/task/1629/
#include <bits/stdc++.h>

using namespace std;

void doWork() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vec[i] = {x, y};
    }

    // Sort by end time ascending because it ensures you always free up the most time for future movies, 
    // guaranteeing the maximum number of movies can be watched.
    sort(vec.begin(), vec.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; // Sorts in ascending order of the second element
    });
    int lastEnd = -1;
    int count = 0;

    for (int i = 0; i < n; i++) {
        vector<int> it = vec[i];
        if (lastEnd == -1 || it[0] >= lastEnd) {
            lastEnd = it[1];
            count++;
        }
    }

    cout << count << endl;
}
