#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
    int id;
    vector<node*> children;
    node(int i){id = i;}
};

vector<node> nodes;
int n, m;

bool nodesorthelper(node *a, node *b) {
    return &a->id < &b->id;
}

void dfs(int id, int count, vector<int> path, bool visited[n]) {
    if (count == n) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }
    count++;
    node current = nodes[id];
    vector<node*> children = current.children;
    sort(children.begin(), children.end(), nodesorthelper);
    for (int i = 0; i < children.size(); i++) {
        if (!visited[children[i]->id]) {
            path.push_back(children[i]->id);
            visited[children[i]->id] = true;
            dfs(children[i]->id, count, path, visited);
            path.pop_back();
            visited[children[i]->id] = false;
        }
    }
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        nodes.push_back(node(i));
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        nodes[a-1].children.push_back(&nodes[b-1]);
        nodes[b-1].children.push_back(&nodes[a-1]);
    }
    vector<int> path;
    bool visited[n];
    dfs(0, 0, path, visited);
}