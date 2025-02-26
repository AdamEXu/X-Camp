#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nums[1000000];
int n, m;

int binary_search(void) {
    int l = 0, r = n-1, mid;
    while (l <= r) {
        mid = (l+r)/2;
        if (nums[mid] == m) {
            while (nums[mid] == m) mid--;
            return mid+1;
        }
        else if (nums[mid] > m) r = mid-1;
        else l = mid+1;
    }
    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << binary_search()+1 << '\n';
}