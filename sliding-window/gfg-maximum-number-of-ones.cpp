// https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int>& arr, int k) {
        int l = 0, res = 0;
        int ones = 0;
        
        for (int r = 0; r < arr.size(); r++) {
            if (arr[r] == 1) ones++;
            
            while ((r - l + 1) - ones > k) {
                if (arr[l] == 1) ones--;
                l++;
            }
            
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};


void doWork() {
    Solution sol;
    vector<int> vec = {1, 0, 1};
    cout << sol.maxOnes(vec, 1) << endl;
    vec = {1, 0, 0, 1, 0, 1, 0, 1};
    cout << sol.maxOnes(vec, 2) << endl;
}