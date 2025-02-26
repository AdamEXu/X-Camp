#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
// #include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string s;
    cin >> s;
    while (N--) {
        string temp = s;
        s[0] = 'D';
        s[s.length()-1] = 'D';
        for (int i = 1; i < s.length()-1; ++i) {
            if (temp[i-1] == temp[i+1]) {
                s[i] = 'S';
            } else {
                s[i] = 'D';
            }
        }
    }
    cout << s << '\n';
}