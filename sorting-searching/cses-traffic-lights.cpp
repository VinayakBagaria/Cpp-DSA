// https://cses.fi/problemset/task/1163/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> solve(vector<int>& positions, int streetLength) {
        vector<int> result;
        // Sorted position of traffic lights ends
        set<int> lights = {0, streetLength};
        // Track gaps of available spaces between traffic lights
        // Max of multiset at any instance = Result of longest path without traffic light -> last element of multiset
        multiset<int> distances = {streetLength};

        for (int pos : positions) {
            auto higher = lights.upper_bound(pos);
            auto lower = higher;
            --lower;

            // When placing a new position "pos" light,
            // Split [lower, higher] range to [lower, pos] and [pos, higher]
            // i.e.., 2 new empty path distances
            // Push these both distances in the gap multiset
            // Also insert "pos" into our lights set to tell we have a new traffic light
            distances.erase(distances.find(*higher - *lower));
            distances.insert(*higher - pos);
            distances.insert(pos - *lower);
            lights.insert(pos);

            auto ans = distances.end();
            --ans;
            result.push_back(*ans);
        }

        return result;
    }
};

void doWork() {
    int n, lightCount;
    cin >> n >> lightCount;
    vector<int> vec(lightCount);
    for (auto& it : vec) cin >> it;
    Solution sol;
    vector<int> result = sol.solve(vec, n);
    for (int maxLen : result) cout << maxLen << " ";
}
