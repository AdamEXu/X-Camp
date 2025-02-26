#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, maxsum = -2147483648, num;
    vector<int> prefixsums (n+1);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        prefixsums[i] = prefixsums[i-1]+num;
        for (int j = i-b; j <= i-a; ++j) {
            if (j >= 0) {
                if (prefixsums[i]-prefixsums[j] > maxsum) {
                    maxsum = prefixsums[i]-prefixsums[j];
                }
            }
        }
    }
    cout << maxsum << '\n';
}