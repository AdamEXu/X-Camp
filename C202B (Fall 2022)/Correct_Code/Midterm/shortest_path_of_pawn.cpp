#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
    int n, sx, sy, ex, ey, dist = 0;
    cin >> n >> sx >> sy >> ex >> ey;
    int x = abs(sx-ex), y = abs(sy-ey);
    if (x % 2 == 0) {
        dist+=x/2;
    } else {
        dist+=x/2+1;
    }
    if (y % 2 == 0) {
        dist+=y/2;
    } else {
        dist+=y/2+1;
    }
    cout << dist << endl;
}