// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description
#include <bits/stdc++.h>

using namespace std;

// O(log n * log n)
class Solution {
private:
    int countSteps(int n, long pref1, long pref2) {
        int steps = 0;

        while (pref1 <= n) {
            steps = min((long) (n + 1), pref2) - pref1;
            pref1 *= 10;
            pref2 *= 10;
        }

        return steps;
    }

public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while (k > 0) {
            int steps = countSteps(n, curr, curr+1);
            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};

void doWork() {
    Solution s;
    cout << s.findKthNumber(13, 2) << endl;
    cout << s.findKthNumber(100, 10) << endl;
}