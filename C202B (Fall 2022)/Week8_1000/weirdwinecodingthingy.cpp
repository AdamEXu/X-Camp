#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int cap[3];
map<vector<int>, int> visited;
map<vector<int>, int> target;

int dx[6] = {0, 0, 1, 1, 2, 2};
int dy[6] = {1, 2, 0, 2, 0, 1};
queue<vector<int> >q;

int main(void) {
    cin >> cap[0] >> cap[1] >> cap[2];
    if (cap[0]%2==1) {
        cout << "NO"; return 1;
    }

    int half = cap[0]/2;
    vector<int> v({half, half, 0}); target[v] = 1;
    v = {0, half, half}; target[v] = 1;
    v = {half, 0, half}; target[v] = 1;

    v = {cap[0], 0, 0}; visited[v] = 0; q.push(v);
    while (!q.empty()) {
        v = q.front(); q.pop();
        for (int i = 0; i < 6; i++) {
            int from = dx[i];
            int to = dy[i];
            int vol = min(v[from], cap[to]-v[to]);
            vector<int> nv = v;
            nv[from] -= vol; nv[to] += vol;
            if (visited.count(nv) == 1) {
                continue;
            } 
            if (target.count(nv) == 1) {
                cout << visited[v]+1 << endl;
                return 0;
            }
            visited[nv] = visited[v]+1;
            q.push(nv);
        }
    }
}