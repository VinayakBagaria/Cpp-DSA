// https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  private:
    int getCost(int exp, const vector<int>& heights, const vector<int>& cost) {
        int sum = 0;
        for (int i = 0; i < heights.size(); i++) {
            sum += abs(heights[i] - exp) * cost[i];
        }
        return sum;
    }

  public:
    int minCost(const vector<int>& heights, const vector<int>& cost) {
        int low = *min_element(heights.begin(), heights.end());
        int high = *max_element(heights.begin(), heights.end());

        int ans = 1e9;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int c1 = getCost(mid - 1, heights, cost);
            int c2 = getCost(mid, heights, cost);
            int c3 = getCost(mid + 1, heights, cost);

            if (c2 <= c1 && c2 <= c3) {
                return c2;
            } else if (c1 >= c2 && c2 >= c3) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
};


void doWork() {
    Solution s;
    cout << s.minCost({1, 2, 3}, {10, 100, 1000}) << endl;
    cout << s.minCost({7, 1, 5}, {1, 1, 1}) << endl;
    cout << s.minCost({4, 6, 5}, {5, 2, 3}) << endl;
}
