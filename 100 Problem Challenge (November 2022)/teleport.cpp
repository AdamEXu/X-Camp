#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    // cin and cout to file
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int teleport = min(abs(a-x) + abs(b-y), abs(a-y) + abs(b-x));
    // cout << teleport << '\n';
    int walk = abs(a-b);
    // cout << walk << '\n';
    cout << min(teleport, walk) << '\n';
}