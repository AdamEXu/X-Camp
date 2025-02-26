#include <iostream>
using namespace std;

int main(void) {
    long long N, a=0, k=1;
    cin >> N;
    for (long long i = 1; i < N; i++) {
        long long ok = k;
        k = a*3;
        a+=ok;
    }
    cout << a << endl;
    cout << k << endl;
}