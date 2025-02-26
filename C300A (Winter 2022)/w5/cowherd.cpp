#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums, nums+n);
    // 2 pointers
    int j = 0, answer = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n-1 && nums[j+1] - nums[i] < n-1) ++j;
        if (j-i+1 > answer) {
            answer = j-i+1;
        }
    }
    int maximumssoiejoi = max(nums[n-2]-nums[0], nums[n-1]-nums[1]) - (n-2);
    if (nums[n-2]-nums[0] == n-2 && nums[n-1]-nums[n-2]>2) cout << 2 << '\n';
    else if (nums[n-1]-nums[1] == n-2 && nums[1]-nums[0]>2) cout << 2 << '\n';
    else cout << answer << '\n';
    cout << maximumssoiejoi << '\n';
}