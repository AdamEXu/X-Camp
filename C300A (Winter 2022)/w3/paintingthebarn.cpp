#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<vector<int> > offsets(1001, vector<int>(1001, 0));
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        offsets[x1][y1]++;
        offsets[x2][y2]++;
        offsets[x1][y2]--;
        offsets[x2][y1]--;
    }
    for (int i = 0; i <= 1000; ++i) {
        for (int j = 0; j <= 1000; ++j) {
            if (i > 0) offsets[i][j] += offsets[i-1][j];
            if (j > 0) offsets[i][j] += offsets[i][j-1];
            if (i > 0 && j > 0) offsets[i][j] -= offsets[i-1][j-1];
            if (offsets[i][j] == k) {
                result++;
            }
        }
    }
    cout << result << '\n'; 
}