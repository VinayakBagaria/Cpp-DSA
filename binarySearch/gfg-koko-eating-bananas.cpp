#include <bits/stdc++.h>

using namespace std;

class Solution {
  private:
    int division(int a, int b) {
        return (a / b) + (a % b == 0 ? 0 : 1);
    }
    
    int getTime(int rate, const vector<int>& arr) {
        int timeTaken = 0;
        for (int qty : arr) {
            timeTaken += division(qty, rate);
        }
        return timeTaken;
    }

  public:
    int kokoEat(const vector<int>& arr, int k) {
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        
        int result = 1e9;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (getTime(mid, arr) <= k) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
};

void doWork() {
    Solution sol;
    cout << sol.kokoEat({5, 10, 3}, 4) << endl;
    cout << sol.kokoEat({5, 10, 15, 20}, 7) << endl;
    cout << sol.kokoEat({3, 4}, 10) << endl;
}