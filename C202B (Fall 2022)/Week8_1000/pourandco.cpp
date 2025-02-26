#include<iostream>
#include<vector>
#include <queue>
#include<map>
using namespace std;

int cap[3];
map<vector<int>, int> visited;
map<vector<int>, int> target;

int dx[6] = {0, 0, 1, 1, 2, 2};
int dy[6] = {1, 2, 0, 2, 0, 1};
queue<vector<int> > q;

int main(void) {
    cin >> cap[0] >> cap[1] >> cap[2];
    if (cap[0]%2 == 1) {
        cout << "NO" << endl;
        return 0;
    }

    int half = cap[0]/2;
    vector<int> v(3, 0);
    v.push_back(0);
    v.push_back(half);
    v.push_back(half);
    // v = {0, half, half};
    target[v] = 1;
    v.clear();
    v.push_back(half);
    v.push_back(0);
    v.push_back(half);
    target[v] = 1;
    v.clear();
    v.push_back(cap[0]);
    v.push_back(0);
    v.push_back(0);
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int from = dx[i];
            int to = dy[i];
            int vol = min(v[from], cap[to]-v[to]);
            vector<int> newv = v;
            newv[from] -= vol;
            newv[to] += vol;
            if (visited.count(newv) == 1) {
                continue;
            }
            if (target.count(newv) == 1) {
                cout << visited[v]+1 << endl;
                return 0;
            }
            visited[newv] = visited[v]+1;
            q.push(newv);
        }
    }
}