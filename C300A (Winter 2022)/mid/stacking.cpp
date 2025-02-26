#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> stacks(n, 0);
    int a, b;
    while (--k) {
        cin >> a >> b;
        for (int j = a-1; j < b; ++j) {
            ++stacks[j];
        }
    }
    sort(stacks.begin(), stacks.end());
    cout << stacks[n/2] << '\n';
}