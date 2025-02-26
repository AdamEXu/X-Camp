#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    // freopen("shell.in", "r", stdin);
    // freopen("shell.out", "w", stdout);
    vector<int> points;
    vector<int> pebbles;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {pebbles.push_back(i);points.push_back(0);}
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int temp = pebbles[a];
        pebbles[a] = pebbles[b];
        pebbles[b] = temp;
        int guess;
        cin >> guess;
        points[pebbles[guess]]++;
    }
    int maxscore = 0;
    for (int i = 0; i < n; i++) {
        if (points[i] > maxscore) {
            maxscore = points[i];
        }
    }
    cout << maxscore << endl;
}