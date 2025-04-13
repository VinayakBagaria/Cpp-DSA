#include <iostream>
#include <vector>
#include <string>

using namespace std;

string smallestPalindrome(string s) {
    string result = s;
    int n = s.size();
    vector<int> count(26, 0);
    for (char c : s) {
        count[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] % 2 == 1) {
            result[n/2] = char('a' + i);
        }
        count[i] /= 2;
    }

    int j = 0;
    for (int i = 0; i < 26; i++) {
        while (count[i]--) {
            result[j] = result[n-j-1] = char('a' + i);
            j++;
        }
    }

    return result;
}

void doWork() {
    cout << smallestPalindrome("z") << endl;
    cout << smallestPalindrome("babab") << endl;
    cout << smallestPalindrome("daccad") << endl;
    cout << smallestPalindrome("yey") << endl;
}