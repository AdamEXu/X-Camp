#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <climits>
#include <iomanip>
// #include <bits/stdc++.h>
using namespace std;

// TOO SLOW
// int main(void) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nULL);
//     long long n;
//     cin >> n;
//     vector<long long> cows;
//     long long a, b, m = 0;
//     for (long long i = 0; i < n; ++i) {
//         cin >> a >> b;
//         m+=a;
//         for (long long j = 0; j < a; j++) cows.push_back(b);
//     }
//     sort(cows.begin(), cows.end());
//     long long ans = 0;
//     for (long long i = 0; i < m/2; ++i) {
//         ans = max(ans, cows[i]+cows[m-i-1]);
//     }
//     cout << ans << '\n';
// }


int main(void)
{
    int n;
    cin >> n;
    int x, y;
    vector<pair<int, int> > cows;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        cows.push_back(make_pair(y, x));
    }
    sort(cows.begin(), cows.end());
    int m = 0, i = 0, j = n-1;
    while (i <= j) {
        // cout << i << " " << j << "\n";
        if (cows[i].second > cows[j].second) x = cows[j].second; else x = cows[i].second;
        if (i == j) x /= 2;
        if (cows[i].first + cows[j].first > m) m = cows[i].first + cows[j].first;
        cows[i].second-=x; cows[j].second-=x;
        if (!cows[i].second) ++i;
        if (!cows[j].second) --j;
    }
    cout << m << "\n";
    return 0;
}