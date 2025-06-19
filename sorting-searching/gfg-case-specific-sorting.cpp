// https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    string caseSortOptimized(string s) {
        vector<int> low(26, 0), high(26, 0);
        for (char c : s) {
            if (islower(c)) {
                low[c - 'a']++;
            } else {
                high[c - 'A']++;
            }
        }
        
        string result = s;
        int l = 0, h = 0;
        for (int i = 0; i < s.size(); i++) {
            if (islower(s[i])) {
                while (low[l] == 0) {
                    l++;
                }
                
                result[i] = l + 'a';
                low[l]--;
            } else {
                while (high[h] == 0) {
                    h++;
                }
                
                result[i] = h + 'A';
                high[h]--;
            }
        }
        
        return result;
    }

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
    cout << sol.caseSortOptimized("GEekS") << endl;
    cout << sol.caseSort("defRTSersUXI") << endl;
    cout << sol.caseSortOptimized("defRTSersUXI") << endl;
}