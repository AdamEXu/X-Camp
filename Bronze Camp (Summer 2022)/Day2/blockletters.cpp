#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    // freopen("cowsignal.in", "r", stdin);
    // freopen("cowsignal.out", "w", stdout);
    vector<vector<bool> > original;
    vector<vector<bool> > bigger;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        vector<bool> row;
        for (int j = 0; j < m; j++) {
            char temp;
            cin >> temp;
            if (temp == '.') {
                row.push_back(true);
            } else {
                row.push_back(false);
            }
        }
        original.push_back(row);
    }
    for (int i = 0; i < n*k; i++) {
        vector<bool> row;
        for (int j = 0; j < m*k; j++) {
            row.push_back(false);
        }
        bigger.push_back(row);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = 0; x < k; x++) {
                for (int y = 0; y < k; y++) {
                    bigger[i*k+x][j*k+y] = original[i][j];
                }
            }
        }
    }
    for (int i = 0; i < n*k; i++) {
        for (int j = 0; j < m*k; j++) {
            if (bigger[i][j]) {
                cout << '.';
            } else {
                cout << 'X';
            }
        }
        cout << endl;
    }
}