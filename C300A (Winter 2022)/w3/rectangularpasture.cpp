#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, maxx, maxy;
    cin >> n;
    vector<pair<int, int> > pts;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (a-1 > maxx) maxx=a-1;
        if (b-1 > maxy) maxy=b-1;
        pts.push_back(make_pair(a-1, b-1));
    }
}