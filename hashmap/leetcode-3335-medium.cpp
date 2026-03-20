// https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        while (t--) {
            vector<int> temp(26, 0);

            for (int i = 0; i < 26; i++) {
                char c = i + 'a';
                int times = freq[i];

                if (c == 'z') {
                    temp['a' - 'a'] = (temp['a' - 'a'] + times) % MOD;
                    temp['b' - 'a'] = (temp['b' - 'a'] + times) % MOD;
                } else {
                    temp[(c + 1) - 'a'] = (temp[(c + 1) - 'a'] + times) % MOD;
                }
            }

            freq = std::move(temp);
        }

        int count = 0;
        for (int times : freq) {
            count = (count + times) % MOD;
        }
        return count;
    }
};

void doWork() {
    Solution sol;
    cout << sol.lengthAfterTransformations("abcyy", 2) << endl;
    cout << sol.lengthAfterTransformations("azbk", 1) << endl;
    cout << sol.lengthAfterTransformations("jqktcurgdvlibczdsvnsg", 7517) << endl;
}
