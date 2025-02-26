#include <iostream>
using namespace std;

int movedist = 0;
int moveamount = 1;

int main(void) {
    // freopen("lostcow.in", "r", stdin);
    // freopen("lostcow.out", "w", stdout);
    int fj, b;
    cin >> fj >> b;
    // lost cow problem from fj to b
    while (true) {
        // cout << "hello" << endl;
        for (int i = 0; i < moveamount; i++) {
            // cout << fj << endl;
            movedist++;
            fj++;
            if (fj == b) {
                cout << movedist << endl;
                return 0;
            }
        }
        movedist += moveamount;
        fj -= moveamount;
        moveamount*=2;
        for (int i = 0; i < moveamount; i++) {
            // cout << fj << endl;
            movedist++;
            fj--;
            if (fj == b) {
                cout << movedist << endl;
                return 0;
            }
        }
        movedist += moveamount;
        fj += moveamount;
        moveamount*=2;
    }
}