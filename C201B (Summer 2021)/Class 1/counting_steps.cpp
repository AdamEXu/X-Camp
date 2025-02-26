#include <iostream>
using namespace std;

int climb_stairs(int n) {
    if (n <= 2) {
        return n;
    }
    int x = 1, y = 2;
    for (int i = 3; i < n; ++i) {
        int temp = y;
        y+=x;
        x = temp;
    }
    return x+y;
}

int main(void) {
    cout << climb_stairs(10) << endl;
}