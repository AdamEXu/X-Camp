#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, temp;
    vector<int> mices;
    multiset<int> holes;
    cin >> a >> b;
    for (int i = 0; i < a; ++i) {
        cin >> temp;
        mices.push_back(temp);
    }
    for (int i = 0; i < b; ++i) {
        cin >> temp;
        holes.insert(temp);
    }

    long long ans = 0;
    while (a--) {
        auto it = --(holes.lower_bound(mices[a]));
        ans += mices[a] - *it;
        holes.erase(it);
    }
    cout << ans << endl;
}