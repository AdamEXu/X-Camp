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
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n*2; i++) {
        a.push_back(i+1);
    }
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        b.push_back(x);
        a.erase(find(a.begin(), a.end(), x));
    }
    sort(b.begin(), b.end());
    int aindex = 0, bindex = 0, count = 0;
    for (int i = 0; i < n; i++) {
        int bleast = b[bindex];
        int aleast = a[aindex];
        while (bleast > aleast) {
            ++aindex;
            if (aindex == n) break;
            aleast = a[aindex];
        }
        ++count;
        ++aindex;
        ++bindex;
        if (aindex == n) break;
    }
    cout << count << '\n';
}