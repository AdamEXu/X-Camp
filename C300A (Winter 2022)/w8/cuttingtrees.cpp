#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool reversesorterhelper(long long a, long long b) {
    return a > b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m;
    cin >> n >> m;
    vector<long long> trees(n);
    long long biggest = 0;
    // putinto vector and find biggest height
    for (int i = 0; i < n; ++i) {
        cin >> trees[i];
        if (trees[i] > biggest) biggest = trees[i];
    }
    //cout << biggest << endl;
    // sort(trees.begin(), trees.end(), reversesorterhelper);
    long long ans = 0, woodsadder = 0;
    int lbound = 0, ubound = biggest, mid;
    while (lbound <= ubound) {
        mid = (lbound+ubound)/2;
        for (int i = 0; i < n; ++i) {
            if (trees[i]>mid) woodsadder += trees[i]-(mid);
        }
        // cout << mid << " " << woodsadder << endl;
        if (woodsadder == m) {
            ans = mid;
            break;
        } else if (woodsadder < m) {
            ubound = mid-1;
        } else {
            ans = mid;
            lbound = mid+1;
        }
        woodsadder = 0;
    }
    cout << ans << endl;
}