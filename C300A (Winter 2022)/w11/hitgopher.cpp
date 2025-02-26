#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > gophers (n, make_pair(0, 0));
    for (int i = 0; i < n; ++i) {
        cin >> gophers[i].second;
    }
    for (int i = 0; i < n; ++i) {
        cin >> gophers[i].first;
    }
    set<int> time;
    int ans = 0;
    sort(gophers.begin(), gophers.end());
    for (int i = n; i >= 0; --i) {
        for (int j = gophers[i].second; j >= 1; --j) {
            if (time.count(j) == 0) {
                ans += gophers[i].first;
                time.insert(j);
                break;
            }
        }
    }
    cout << ans << endl;
}