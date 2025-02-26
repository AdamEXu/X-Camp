#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.push_back(num);
    }
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        b.push_back(num);
    }
    int ai = 0, bi = 0;
    while (ai < n && bi < m) {
        if (a[ai] < b[bi]) {
            cout << a[ai] << " ";
            ai++;
        } else {
            cout << b[bi] << " ";
            bi++;
        }
    }
    while (ai < n) {
        cout << a[ai] << " ";
        ai++;
    }
    while (bi < m) {
        cout << b[bi] << " ";
        bi++;
    }
    cout << endl;
}