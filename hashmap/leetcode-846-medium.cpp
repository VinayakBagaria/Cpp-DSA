// https://leetcode.com/problems/hand-of-straights/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int> hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> mp;

        for (int x : hand) {
            mp[x]++;
        }
        
        while (!mp.empty()) {
            int smallest = mp.begin()->first;
            bool success = true;

            for (int i = 0; i < groupSize; i++) {
                int nextElement = smallest + i;
                if (mp.find(nextElement) == mp.end()) {
                    success = false;
                    break;
                }

                mp[nextElement]--;
                if (mp[nextElement] == 0) {
                    mp.erase(nextElement);
                }
            }

            if (!success) {
                return false;
            }
        }

        return true;
    }
};

void doWork() {
    Solution sol;
    cout << sol.isNStraightHand({1,2,3,6,2,3,4,7,8}, 3) << endl;
    cout << sol.isNStraightHand({1,2,3}, 4) << endl;
}
