#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool pairsort(const pair<int, char> &a, const pair<int, char> &b) {
    return a.first < b.first;
}

int main(void) {
    int n;
    cin >> n;
    vector<pair<int, char> > faxx(n);
    for (int i = 0; i < n; i++) {
        cin >> faxx[i].second >> faxx[i].first;
    }
    sort(faxx.begin(), faxx.end(), pairsort);
    int minliars = 2147483647;
    for (int i = 0; i < n; i++) {
        int loc = faxx[i].first;
        int liars = 0;
        for (int j = 0; j < n; j++) {
            if (faxx[j].second == 'L') {
                if (faxx[j].first < loc) ++liars;
            } else {
                if (faxx[j].first > loc) ++liars;
            }
        }
        minliars = min(minliars, liars);
    }
    cout << minliars << '\n';
}