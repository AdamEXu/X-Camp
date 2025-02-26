#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> nxt(n);
    for (int i = 0; i < n; i++) {
        cin >> nxt[i];
    }
    set<int> loopy;
    for (int i = 0; i < n; i++) {
        if (loopy.count(i) > 0) {
            continue;
        }
        set<int> current;
        current.insert(i);
        int j = nxt[i];
        while (nxt[j] != 0) {
            if (current.count(j) > 0 || loopy.count(j) > 0) {
                for (auto it = current.begin(); it != current.end(); it++) {
                    loopy.insert(*it);
                }
                break;
            }
            current.insert(j);
        }
    }
    cout << n-loopy.size() << '\n';
}