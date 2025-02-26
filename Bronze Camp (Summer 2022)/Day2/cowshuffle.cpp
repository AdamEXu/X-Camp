#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    // freopen("shuffle.in", "r", stdin);
    // freopen("shuffle.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> keys;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        keys.push_back(temp);
    }
    vector<int> cows;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cows.push_back(temp);
    }
    for (int i = 0; i < 3; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(cows[j]);
        }
        for (int j = 0; j < n; j++) {
            cows[j] = temp[keys[j]-1];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << cows[i] << endl;
    }
}