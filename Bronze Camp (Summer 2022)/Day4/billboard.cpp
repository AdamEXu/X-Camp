#include <iostream>
using namespace std;

int main(void) {
    // freopen("billboard.in", "r", stdin);
    // freopen("billboard.out", "w", stdout);
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    int x3 = 0, y3 = 0, x4 = 0, y4 = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    int corner_num = 0;
    if (x3 <= x1 and y4 >= y2) {
        corner_num++;
    }
    if (y4 >= y2 and x4 >= x2) {
        corner_num++;
    }
    if (x4 >= x2 and y3 <= y1) {
        corner_num++;
    }
    if (y3 <= y1 and x3 <= x1) {
        corner_num++;
    }
    cout << corner_num << endl;
    if (corner_num == 0) {
        cout << abs(x2-x1)*abs(y2-y1) << endl;
    } else if (corner_num == 1) {
        cout << abs(x2-x1)*abs(y2-y1) << endl;
    } else if (corner_num == 2) {
        cout << abs(y2-y1)*abs(x2-x4) << endl;
    } else if (corner_num == 3) {
        cout << abs(y2-y1)*abs(x2-x4) << endl;
    } else if (corner_num == 4) {
        cout << abs((x2-x1)*(y3-y1)) << endl;
    } else if (corner_num == 5) {
        cout << abs(x2-x1)*abs(y3-y1) << endl;
    } else if (corner_num == 6) {
        cout << abs(x2-x1)*abs(y3-y1) << endl;
    } else if (corner_num == 7) {
        cout << abs(x2-x1)*abs(y3-y1) << endl;
    }
    return 0;
}