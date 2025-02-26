#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> nums (n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int lowerbound = 0, upperbound = n-1, mid;
    while (lowerbound <= upperbound) {
        mid = (lowerbound+upperbound)/2;
        if (nums[mid] == m) {
            cout << mid+1 << endl;
            return 0;
        } else if (nums[mid] > m) {
            upperbound = mid-1;
        } else if (nums[mid] < m) {
            lowerbound = mid+1;
        }
    }
    cout << -1 << endl;
}