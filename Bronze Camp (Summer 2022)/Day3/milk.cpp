#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int minoffest = 1000;
    int m, x, y;
    cin >> x >> y >> m;
    queue <int> notebook;
    notebook.push(0);
    while (!notebook.empty()) {
        int current = notebook.front();
        notebook.pop();
        if (current + x >= m) {
            if (current + x - m < abs(minoffest-m)) {
                minoffest = current + x;
            }
            if (m - current < abs(minoffest-m)) {
                minoffest = current;
            }
        } else {
            notebook.push(current + x);
        }
        if (current + y >= m) {
            if (current + y - m < abs(minoffest - m)) {
                minoffest = current + y;
            }
            if (m - current < abs(minoffest-m)) {
                minoffest = current;
            }
        } else {
            notebook.push(current + y);
        }
    }
    cout << minoffest << endl;
}