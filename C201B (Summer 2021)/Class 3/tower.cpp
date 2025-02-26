#include <iostream>
using namespace std;

int maoge(int n) {
    if (n == 1) {
        return 1;
    }
    return maoge(n-1)*2 + 1;
}

int main(void) {
    int n;
    cin >> n;
    cout << maoge(n) << endl;
}