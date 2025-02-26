#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int val;
    int id;
    // vector of pointers to children
    vector<node*> children;
    node(int v, int i){val = v; id = i;}
};

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<node> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(node(0, 0));
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        nodes[a-1].children.push_back(&nodes[b-1]);
        nodes[b-1].children.push_back(&nodes[a-1]);
    }
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    vector<int> tops;
    for (int i = 0; i < n; i++) {
        queue<node*> notebook;
        notebook.push(&nodes[0]);
        int count = 0;
        while (!notebook.empty()) {
            count++;
            node* current = notebook.front();
            notebook.pop();
            for (int i = 0; i < current->children.size(); i++) {
                if (!visited[current->children[i]->id]) {
                    notebook.push(current->children[i]);
                    visited[current->children[i]->id] = true;
                }
            }
        }
        tops.push_back(count);
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (tops[i] > max) {
            max = tops[i];
        }
    }
    cout << max << endl;
}