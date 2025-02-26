#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static inline int maxof3(int a, int b, int c) {
    return max(a, max(b, c));
}

enum gestures { H, P, S };

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int maxuntil, maxafter, ans = 0;
    char gesture;
    vector<vector<int> > dp(3, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        cin >> gesture;
        dp[H][i] = dp[P][i] + (gesture == 'H');
        dp[P][i] = dp[S][i] + (gesture == 'P');
        dp[S][i] = dp[H][i] + (gesture == 'S');
    }
    for (int i = 0; i < n; ++i) {
        maxuntil = max({dp[H][i], dp[P][i], dp[S][i]});
        maxafter = maxof3(dp[H][n] - dp[H][i], dp[P][n] - dp[P][i], dp[S][n] - dp[S][i]);
        ans = max(ans, maxuntil + maxafter);
    }
    cout << ans << endl;
}