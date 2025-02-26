#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> n >> t;
    vector<vector<int> > prefixsums(n+1, vector<int>(n+1, 0));
    char tmp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tmp;
            prefixsums[i][j] = prefixsums[i-1][j] + prefixsums[i][j-1] - prefixsums[i-1][j-1];
            if (tmp == '*') {
                prefixsums[i][j]++;
            }
        }
    }
    int x1, y1, x2, y2, res;
    for (int i = 0; i < t; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        res = prefixsums[x2][y2] - prefixsums[x2][y1-1] - prefixsums[x1-1][y2] + prefixsums[x1-1][y1-1];
        cout << res << "\n";
    }
}