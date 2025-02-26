#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    string number;
    int remainder;
};

int main(void) {
    int n, m;
    queue<node> q;
    cin >> n >> m;
    int digits[m];
    for (int i = 0; i < m; i++) {
        cin >> digits[i];
    }
    sort(digits,digits+m);
}