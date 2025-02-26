#include <iostream>
#include <vector>
using namespace std;

vector<int> visited;
vector<vector<int> > adjList;

void dfs(int i) {
    if (visited[i]) {
        return;
    }
    visited[i] = 1;
    for (auto it = adjList[i].begin(); it != adjList[i].end(); it++) {
        dfs(*it);
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    visited = vector<int>(n+1, 0);
    adjList = vector<vector<int> >(n+1);

    int components = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i);
        }
    }
    cout << components << endl;
}