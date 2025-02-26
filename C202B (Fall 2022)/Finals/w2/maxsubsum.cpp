#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, maxsum = -2147483648, num;
    vector<int> prefixsums (n+1, 0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        prefixsums[i] = prefixsums[i-1]+num;
        for (int j = 0; j < i; ++j) {
            if (prefixsums[i] - prefixsums[j] > maxsum) {
                maxsum = prefixsums[i] - prefixsums[j];
            }
        }
    }
    cout << maxsum << endl;
}