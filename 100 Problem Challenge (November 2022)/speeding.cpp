#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<int> limits(100), speeds(100);
    int ind = 0, dist, speed;
    for (int i = 0; i < n; i++) {
        cin >> dist >> speed;
        for (int j = 0; j < dist; j++) {
            speeds[j+ind] = speed;
        }
        ind += dist;
    }
    ind = 0;
    for (int i = 0; i < m; i++) {
        cin >> dist >> speed;
        for (int j = 0; j < dist; j++) {
            limits[j+ind] = speed;
        }
        ind += dist;
    }
    int max = 0;
    for (int i = 0; i < 100; i++) {
        if (speeds[i] - limits[i] > max) {
            max = speeds[i] - limits[i];
        }
    }
    cout << max << '\n';
}