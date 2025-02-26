#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

struct Node {
    int val;
    vector<Node*> dependencies;
    bool visited;
    Node(int v) : val(v), visited(false) {}
};

vector<Node> graph;
// queue<Node*> waitingQ;
set<int> waiting;

bool nodesorthelp(Node* a, Node* b) {
    return a->val < b->val;
}
bool nodesorthelpalt(Node a, Node b) {
    return a.val < b.val;
}

bool all_visited(int id) {
    for (int i = 0; i < graph[id].dependencies.size(); i++) {
        if (!graph[id].dependencies[i]->visited) {
            return false;
        }
    }
    return true;
}

void check_waitingQ(void) {
    if (waiting.empty()) {
        return;
    }
    // cout << *waiting.begin() << endl;
    // cout << "steamed " << waitingQ.size() << " " << waitingQ.front()->val << endl;
    int s = waiting.size();
    for (int i = 0; i < s; i++) {
        // front = waiting[i];
        int front = *waiting.begin()+i;
        waiting.erase(*waiting.begin());
        if (all_visited(front)) {
            cout << front+1 << " ";
            graph[front].visited = true;
            // sort(waitingQ.front(), waitingQ.back(), nodesorthelpalt);
            // cout << "creamed" << waitingQ.size() << endl;
            i = 0; 
            s--;
        } else {
            waiting.insert(front);
        }
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        graph.push_back(Node(i+1));
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b-1].dependencies.push_back(&graph[a-1]);
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < graph[i].dependencies.size(); j++) {
    //         cout << graph[i].dependencies[j]->val << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++) {
        sort(graph[i].dependencies.begin(), graph[i].dependencies.end(), nodesorthelp);
    }

    for (int i = 0; i < n; i++) {
        if (graph[i].dependencies.empty()) {
            graph[i].visited = true;
            cout << graph[i].val << " ";
        } else {
            if (all_visited(i)) {
                graph[i].visited = true;
                cout << graph[i].val << " ";
            } else {
                // cout << endl << i << endl;
                waiting.insert(i);
            }
        }
        // for (int j = 0; j < n; j++) {
            check_waitingQ();
        // }
    }
    cout << endl;
}