// https://leetcode.com/problems/sum-of-k-mirror-numbers/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    string toBaseK(long long num, int k) {
         if(num == 0) {
            return "0";
        }

        string baseK = "";

        while (num > 0) {
            baseK += to_string(num % k);
            num /= k;
        }

        return baseK;
    }

    bool isPalin(string s) {
        int i = 0, j = s.size() - 1;

        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        // create "palinLength" length palindromes
        int palinLength = 1;

        while(n > 0) {
            int halfLength = (palinLength + 1) / 2;
            long long minNum = pow(10, halfLength - 1);
            long long maxNum = pow(10, halfLength) - 1;

            for (int i = minNum; i <= maxNum; i++) {
                string firstHalf = to_string(i);
                string secondHalf = firstHalf;
                reverse(secondHalf.begin(), secondHalf.end());

                string palin = "";


                if (palinLength % 2 == 0) {
                    palin = firstHalf + secondHalf;
                } else {
                    palin = firstHalf + secondHalf.substr(1);
                }
            
                long long num = stoll(palin);

                string baseK = toBaseK(num, k);

                if (isPalin(baseK)) {
                    n--;
                    sum += num;

                    if (n == 0) {
                        break;
                    }
                }
            }

            palinLength++;
        }

        return sum;
    }
};

void doWork() {
    Solution sol;
    cout << sol.kMirror(3, 7) << endl;
}