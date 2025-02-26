#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
    int n, start, end;
    cin >> n >> start >> end;
    vector<bool> visited;
    vector<int> labels, dist;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        labels.push_back(a);
        dist.push_back(-1);
        visited.push_back(false);
    }

    if (start == end) {
        cout << 0 << endl;
        return 0;
    }

    queue<int> notebook;
    notebook.push(start-1);
    dist[start-1] = 0;
    visited[start-1] = true;
    while (!notebook.empty()) {
        int current = notebook.front();
        notebook.pop();
        if (dist[current] > 1000) {
            cout << -1 << endl;
            return 0;
        }
        int floor = labels[current];
        // cout << current << endl;
        if (current-floor >= 0 && current-floor < n && !visited[current-floor]) {
            if (current-floor == end-1) {
                cout << dist[current]+1 << endl;
                return 0;
            }
            dist[current-floor] = dist[current]+1;
            visited[current-floor] = true;
            notebook.push(current-floor);
        } if (current+floor >= 0 && current+floor < n && !visited[current+floor]) {
            if (current+floor == end-1) {
                cout << dist[current]+1 << endl;
                return 0;
            }
            dist[current+floor] = dist[current]+1;
            visited[current+floor] = true;
            notebook.push(current+floor);
        }
        // visited[current] = false;
    }
    cout << -1 << endl;
}