#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> field (1000000, 0);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        field[b]+=a;
    }
    vector<int> prefix (1000000, 0);
    prefix[0] = field[0];
    for (int i = 1; i < 1000000; i++) {
        prefix[i] = prefix[i-1] + field[i];
    }
    int max = 0;
    for (int i = k; i < 1000000 - k; i++) {
        if (prefix[i+k] - prefix[i-k] > max) {
            max = prefix[i+k+1] - prefix[i-k];
            // cout << i << " - l - " << max << '\n';
        }
    }
    cout << max << '\n';
}