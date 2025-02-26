#include <iostream>
#include <string>
#include <vector>
#include <vector>
#include <vector>
#include <vector>
#include <vector>
#include <vector>
#include <set>
using namespace std;

int main(void) {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<string> settysetset;
    for (int i = 1; i <= n; i++) {
        bool chickennuggets = true;
        for (int j = 0; j <= n-i; j++) {
            if (settysetset.find(s.substr(j, i)) != settysetset.end()) {
                chickennuggets = false;
                break;
            } else {
                settysetset.insert(s.substr(j, i));
            }
        }
        if (chickennuggets) {
            cout << i << endl;
            return 0;
        }
    }
}