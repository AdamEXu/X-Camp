#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<pair<int, int> > cows;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cows.push_back(make_pair(a, b));
    }
}