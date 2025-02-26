#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    vector<Node*> dependencies;
    Node(int v) : val(v) {}
};

int n, m;
queue<int> q;
vector<int> result;
vector<bool> inlist (1000, false);
vector<Node> graph;

void checkq(void) {
    if (q.empty()) {
        return;
    }
    for (int i = 0; i < q.size(); i++) {
        int num = q.front();
        Node front = graph[num];
        q.pop();
        bool all_in = true;
        for (int j = 0; j < front.dependencies.size(); j++) {
            if (!inlist[front.dependencies[j]->val]) {
                q.push(front.dependencies[j]->val);
                all_in = false;
                break;
            }
        }
        if (all_in) {
            result.push_back(front.val);
            inlist[front.val] = true;
        }
    }
}

bool check_dependencies(int id) {
    for (int i = 0; i < graph[id].dependencies.size(); i++) {
        if (!inlist[graph[id].dependencies[i]->val]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        graph.push_back(Node(i));
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b-1].dependencies.push_back(&graph[a-1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].dependencies.size(); j++) {
            cout << graph[i].dependencies[j]->val << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        if (!check_dependencies(i)) {
            q.push(i);
            cout<<"no dependencies i = " <<i<<endl;
        } else {
            //
            result.push_back(i+1);
            inlist[i] = true;
        }
        checkq();
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}