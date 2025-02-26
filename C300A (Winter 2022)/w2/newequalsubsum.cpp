#include <iostream>
#include <map>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    long long sum = 0, count = 0;
    map<long long, long long> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        if (sum == x) {
            count++;
        }
        if (m.find(sum - x) != m.end()) {
            count += m[sum - x];
        }
        m[sum]++;
    }
    cout << count << endl;
}