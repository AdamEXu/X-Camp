#include <iostream>
#include <map>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n;
    map<int, int> customers;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        customers[a] = 1;
        customers[b] = -1;
    }
    int maxcustomers = 0, current = 0;
    for (map<int, int>::iterator it = customers.begin(); it != customers.end(); ++it) {
        current += it->second;
        maxcustomers = max(maxcustomers, current);
    }
    cout << maxcustomers << endl;
}