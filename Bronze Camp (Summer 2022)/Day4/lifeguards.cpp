#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int> > cowtimes;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cowtimes.push_back(make_pair(a, b));
    }
    vector<int> times;


    for (int i = 0; i < n; i++) {
        pair<int, int> temp[n];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                temp[j] = cowtimes[j];
            }
        }
        int timeline[1000] = {0};
        for (int j = 0; j < n-1; j++) {
            for (int k = temp[j].first; k <= temp[j].second; k++) {
                timeline[k] = 1;
            }
        }
        int count = 0;
        for (int j = 0; j < 1000; j++) {
            if (timeline[j] == 1) {
                count++;
            }
        }
        times.push_back(count);
    }
    int maxcount = 0;
    for (int i = 0; i < n; i++) {
        if (times[i] > maxcount) {
            maxcount = times[i];
        }
    }
    cout << maxcount << endl;
}