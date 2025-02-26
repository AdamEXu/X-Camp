#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void) {
    int n, m, p1, p2;
    cin >> n >> m;
    vector<int> type(n+1, 0);
    vector<int> adj[n+1];
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2;
        adj[p1].push_back(p2);
        adj[p2].push_back(p1);
    }

    for (int i = 1; i <= n; i++) {
        set<int> usable_types;
        usable_types.insert(1);
        usable_types.insert(2);
        usable_types.insert(3);
        usable_types.insert(4);
        for (auto x : adj[i]) {
            usable_types.erase(type[x]);
        }
        type[i] = *usable_types.begin();
        cout << type[i];
    }
    cout << endl;
}