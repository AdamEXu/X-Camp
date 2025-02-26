#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long lbound = 0, rbound = 0, n, a, b, ans = -9223372036854775806;
    cin >> n >> a >> b;
    vector<long long> prefix (n+1);
    long long tmp;
    for (int i = 0; i < n; ++i) {
        // cout << "i: " << i << endl;
        cin >> tmp;
        prefix[i] = tmp;
        if (i > 0) prefix[i] += prefix[i-1];
    }
    multiset<long long> m;
    m.insert(0);
    bool zero_used = true;
    for (int i = a; i < n; ++i) {
        // cout << "i: " << i << endl;
        if (i-b >= 0 && zero_used) {
            m.erase(m.find(0));
            zero_used = false;
        }
        if (i-a >= 0) {
            m.insert(prefix[i-a]);
        }
        ans = max(ans, prefix[i] - *m.begin());
        if (i-b >= 0) {
            m.erase(m.find(prefix[i-b]));
        }
    }
    ans = max(ans, prefix[a-1]);
    cout << ans << '\n';
}