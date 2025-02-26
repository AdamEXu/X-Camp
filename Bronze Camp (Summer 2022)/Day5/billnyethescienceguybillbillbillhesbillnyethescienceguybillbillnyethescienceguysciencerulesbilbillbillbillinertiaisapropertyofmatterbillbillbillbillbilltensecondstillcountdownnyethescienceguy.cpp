#include <iostream>
#include <string>
using namespace std;

int main(void) {
    // freopen("breedflip.in", "r", stdin);
    // freopen("breedflip.out", "w", stdout);
    int n, flips = 0;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            flips++;
        }
        while (a[i] != b[i]) {
            b[i] = a[i];
            i++;
        }
    }
    cout << flips << endl;
}