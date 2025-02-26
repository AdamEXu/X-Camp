#include <stdio.h>
#include <vector>
using namespace std;

int main(void) {
    int n, customers = 0, maxcust = 0, maxtime = 0;
    scanf("%d", &n);
    vector<pair<int, int> > times;
    int a, b;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        times.push_back(make_pair(a, b));
        if (b > maxtime) {
            maxtime = b;
        }
    }
    for (int i = 0; i < maxtime; ++i) {
        for (int j = 0; j < n; ++j) {
            if (times[j].first == i) {
                ++customers;
            }
            if (times[j].second == i) {
                --customers;
            }
        }
        if (customers > maxcust) {
            maxcust = customers;
        }
    }
    printf("%d\n", maxcust);
}