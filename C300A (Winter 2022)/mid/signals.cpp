#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, b;
    cin >> n >> k >> b;
    vector<bool> signals(n, true);
    int a;
    for (int i = 0; i < b; ++i) {
        cin >> a;
        signals[a-1] = false;
    }
    // find subarray of size k with most true values
    int i = 1, j = 0, count = 0, maxcount = 0;
    for (int i = 0; i <= n-k; ++i) {
        for (int j = i; j < i+k; ++j) {
            if (signals[j]) ++count;
        }
        // cout << count << endl;
        if (count > maxcount) maxcount = count;
        count = 0;
    }
    cout << k-maxcount << '\n';
}