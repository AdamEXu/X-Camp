#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    map<int, int> freq;
    int i = 0, j = 0, count = 0, answer = 0;
    while(i < n) {
        while(j < n && count + (freq[nums[j]] == 0) <= k) {
            ++freq[nums[j]]; 
            count += (freq[nums[j]] == 1);
            ++j;
        }
        answer += j-i;
        count -= (freq[nums[i]] == 1);
        --freq[nums[i]], ++j;
    }
    cout << answer << '\n';
}