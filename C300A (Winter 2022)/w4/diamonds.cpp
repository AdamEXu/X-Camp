#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
    int n, k, tmp;
    cin >> n >> k;
    vector<int> diamonds;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        diamonds.push_back(tmp);
    }
    sort(diamonds.begin(), diamonds.end());
    int maxnum = 0, count = 0;
    vector<int> prefix (n);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (diamonds[j] - diamonds[i] <= k) {
                count++;
            } else {
                break;
            }
        }
        if (count > maxnum) maxnum = count;
        count = 0;
    }
    cout << maxnum << endl;
    return 0;
}
//     // for (int i = 0; i < n; ++i) {
//     //     cout << prefix[i] << " ";
//     // }
//     // cout << endl;
//     vector<int> suffix (n);
//     for (int i = n-1; i >= 0; --i) {
//         if (i != n-1) suffix[i]=max(prefix[i],suffix[i+1]);
//         else suffix[i] = prefix[i];
//     }
//     int result = 0;
//     for (int i = 0; i < n; ++i) {
//         int tmp = prefix[i]+suffix[i+prefix[i]];
//         if (tmp > result) result = tmp;
//     }
//     cout << result << endl;
// }