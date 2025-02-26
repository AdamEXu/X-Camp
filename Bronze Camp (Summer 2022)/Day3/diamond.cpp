#include <iostream>
using namespace std;

int main(void) {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int diamonds[n];
    for (int i = 0; i < n; i++) {
        cin >> diamonds[i];
    }
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        if (diamonds[i] > maxx) {
            maxx = diamonds[i];
        }
    }
    int most = 0;
    for (int i = 0; i < maxx; i++) {
        int temp = 0;
        for (int j = i; j <= i+k; j++) {
            int tmp = 0;
            for (int k = 0; k < n; k++) {
                if (diamonds[k] >= j && diamonds[k] <= j+k) {
                    tmp++;
                }
            }
            temp = max(temp, tmp);
        }
        most = max(most, temp);
    }
    cout << most << endl;
}