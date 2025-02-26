#include <stdio.h>
#include <vector>
using namespace std;

int main(void) {
    int n, maxed=0;
    scanf("%d", &n);
    vector<bool> restraunt(n);
    vector<pair<int, int> > time;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (b > maxed) {
            maxed = b;
        }
        time.push_back(make_pair(a, b));
    }
    int maxcustomers = 0, currentcustomers = 0;
    for (int i = 0; i < maxed; i++) {
        for (int j = 0; j < n; j++) {
            if (time[j].first == i) {
                restraunt[j] = true;
                ++currentcustomers;
            }
            if (time[j].second == i) {
                restraunt[j] = false;
                --currentcustomers;
            }
        }
        if (currentcustomers > maxcustomers) {
            maxcustomers = currentcustomers;
        }
    }
    printf("%d", maxcustomers);
}