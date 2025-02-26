#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    // Input
    int n;
    cin >> n;
    vector<int> groups;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        groups.push_back(t);
    }
    int l, r;
    cin >> l >> r;
    int result = 0;

    // too big -> too small
    for (int i = 0; i < n; i++) {
        if (groups[i] > r) {
            for (int j = 0; j < n; j++) {
                if (groups[j] < l) {
                    while (groups[j]<r && groups[i]>r) {
                        groups[i]--;
                        groups[j]++;
                        result++;
                        // for (int a = 0; a < n; a++) {
                        //     cout << groups[a] << " ";
                        // }
                        // cout << endl;
                    }
                }
            }
        }
    }

    // too big -> normal
    for (int i = 0; i < n; i++) {
        if (groups[i] > r) {
            for (int j = 0; j < n; j++) {
                if (groups[j] < r) {
                    while (groups[j]<r && groups[i]>r) {
                        groups[i]--;
                        groups[j]++;
                        result++;
                        // for (int a = 0; a < n; a++) {
                        //     cout << groups[a] << " ";
                        // }
                        // cout << endl;
                    }
                }
            }
        }
    }

    // too small <- too big
    for (int i = 0; i < n; i++) {
        if (groups[i] < l) {
            for (int j = 0; j < n; j++) {
                if (groups[j] > r) {
                    while (groups[j]>l && groups[i]<l) {
                        groups[i]++;
                        groups[j]--;
                        result++;
                        // for (int a = 0; a < n; a++) {
                        //     cout << groups[a] << " ";
                        // }
                        // cout << endl;
                    }
                }
            }
        }
    }

    // too small <- normal
    for (int i = 0; i < n; i++) {
        if (groups[i] < l) {
            for (int j = 0; j < n; j++) {
                if (groups[j] > l) {
                    while (groups[j]>l && groups[i]<l) {
                        groups[i]++;
                        groups[j]--;
                        result++;
                        // for (int a = 0; a < n; a++) {
                        //     cout << groups[a] << " ";
                        // }
                        // cout << endl;
                    }
                }
            }
        }
    }

    // for (int a = 0; a < n; a++) {
    //     cout << groups[a] << " ";
    // }
    // cout << endl;

    // -1 if failed
    for (int i = 0; i < n; i++) {
        if (groups[i] > r || groups[i] < l) {
            cout << -1 << endl;
            return 0;
        }
    }

    // result
    cout << result << endl;
    return 0;
}