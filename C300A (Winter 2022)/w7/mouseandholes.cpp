#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    multiset<int> mice, holes;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        mice.insert(tmp);
    }
    for (int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        holes.insert(tmp);
    }
    int ans = 0;
    for (auto it = mice.begin(); it != mice.end(); ++it) {
        auto hole = holes.lower_bound(*it);
        if (hole == holes.end()) {
            hole = holes.begin();
        }
        ans = max(ans, abs(*it - *hole));
        holes.erase(hole);
    }
    cout << ans << endl;
}