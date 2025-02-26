#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// bfs from point a to point b but you can only move forwards one, backwards one, or multiply by 2.
int main(void) {
    long long a, b;
    cin >> a >> b;
    queue<long long> notebook;
    notebook.push(a);
    bool visited[100000] = {false};
    long long dist[100000] = {0};
    while (!notebook.empty()) {
        long long current = notebook.front();
        notebook.pop();
        if (current-1 >= 0 && !visited[current-1]) {
            if (current-1 == b) {
                cout << dist[current]+1 << endl;
                return 0;
            }
            dist[current-1] = dist[current]+1;
            visited[current-1] = true;
            notebook.push(current-1);
        }
        if (current+1 < 100001 && !visited[current+1]) {
            if (current+1 == b) {
                cout << dist[current]+1 << endl;
                return 0;
            }
            dist[current+1] = dist[current]+1;
            visited[current+1] = true;
            notebook.push(current+1);
        }
        if (current*2 < 100001 && !visited[current*2]) {
            if (current*2 == b) {
                cout << dist[current]+1 << endl;
                return 0;
            }
            dist[current*2] = dist[current]+1;
            visited[current*2] = true;
            notebook.push(current*2);
        }
    }
}