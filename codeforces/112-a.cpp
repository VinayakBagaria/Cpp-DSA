// https://codeforces.com/problemset/problem/112/A
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int petyaAndStrings() {
    string s1, s2;
    cin >> s1;
    cin >> s2;

    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);

    int result = s1 > s2 ? 1 : (s1 < s2 ? -1 : 0);
    cout << result << endl;

    return 0;
}