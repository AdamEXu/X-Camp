#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    vector<Node*> adj;
    bool visited;
    Node(int v) : val(v), visited(false) {}
    Node() : visited(false) {}
    Node(const Node& n) : val(n.val), visited(n.visited), adj(n.adj) {}
};

vector<Node> graph;

int main(void) {
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++) {
        graph.push_back(Node(i));
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].adj.push_back(&graph[b-1]);
        graph[b-1].adj.push_back(&graph[a-1]);
    }
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        // given a and b, see if a and b are connected
        queue<Node*> notebook;
        graph[a-1].visited = true;
        notebook.push(&graph[a-1]);
        bool connected = false;
        while (!notebook.empty()) {
            Node* current = notebook.front();
            notebook.pop();
            if (current->val == b-1) {
                connected = true;
                break;
            }
            for (int j = 0; j < current->adj.size(); j++) {
                if (!current->adj[j]->visited) {
                    current->adj[j]->visited = true;
                    notebook.push(current->adj[j]);
                    // cout << current->adj[j]->val << " ";
                }
            }
        }
        if (connected) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        for (int j = 0; j < graph.size(); j++) {
            graph[j].visited = false;
        }
    }
}