#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> tempstack(n, 0);
    int a, b;
    for (int i = 0; i < k; ++i) {
        cin >> a >> b;
        ++tempstack[a-1];
        --tempstack[b];
    }
    vector<int> stacks(n, 0);
    stacks[0] = tempstack[0];
    for (int i = 1; i < n; ++i) {
        stacks[i] = stacks[i-1] + tempstack[i];
    }
    sort(stacks.begin(), stacks.end());
    cout << stacks[(n-1)/2] << '\n';
}