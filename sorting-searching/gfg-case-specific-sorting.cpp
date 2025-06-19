// https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string caseSort(string s) {
        int n = s.size();

        vector<char> lower, upper;
        for (char c : s) {
            if (islower(c)) {
                lower.push_back(c);
            } else {
                upper.push_back(c);
            }
        }

        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());

        string result = s;
        int low = 0, up = 0;
        for (int i = 0; i < n; i++) {
            if (islower(s[i])) {
                result[i] = lower[low];
                low++;
            } else {
                result[i] = upper[up];
                up++;
            }
        }

        return result;
    }
};

void doWork() {
    Solution sol;
    cout << sol.caseSort("GEekS") << endl;
    cout << sol.caseSort("defRTSersUXI") << endl;
}