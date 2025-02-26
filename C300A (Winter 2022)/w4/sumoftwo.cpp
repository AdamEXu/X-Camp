#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, tmp;
    cin >> n >> x;
    vector<pair<int, int> > nums;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        nums.push_back(make_pair(tmp, i));
    }
    sort(nums.begin(), nums.end());
    int i = 0, j = n - 1, count = 0;
    while (i < j) {
        if (nums[i].first + nums[j].first > x) {
            j--;
        } else if (nums[i].first + nums[j].first < x) {
            i++;
        } else {
            cout << nums[i].second+1 << " " << nums[j].second+1 << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}