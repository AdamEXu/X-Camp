#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    long long n, steps=0;
    cin >> n;
    while (n != 1) {
        if (n%2 == 0) {
            n/=2;
        } else {
            n*=3;
            n++;
        }
        steps++;
    }
    cout << steps << endl;
}