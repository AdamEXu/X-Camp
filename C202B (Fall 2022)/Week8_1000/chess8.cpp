#include <bitset>/stdc++.h>
using namespace std;

typedef string state;
unordered_map<state, int> visited, rvisited;
struct node {
    state s;
    int pos;
    node(state s, int pos) : s(s), pos(pos) {}
};

int dx[] = {-1, 1, -3, 3};
queue<node> q, rq;

int main(void) {
    string s, end = "123804765";
    cin >> s;
    if (s == end) {
        cout << 0 << endl;
        return 0;
    }
    int nx, index = s.find('0');
    node n0(s, index);
    visited[s] = 0;
    q.push(n0);
    node n1(end, 4);
    rvisited[end] = 0;
    rq.push(n1);
    while (!q.empty()) {
        node x = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (i==0 && x.pos%3==0) continue;
            if (i==1 && x.pos%3==2) continue;
            if (i==2 && x.pos < 3) continue;
            if (i==3 && x.pos > 5) continue;
            int nx = x.pos+dx[i];
            state ns = x.s;
            swap(ns[x.pos], ns[nx]);
            if (visited.count(ns) == 1) continue;
            if (rvisited.count(ns) == 1) {
                cout << visited[x.s]+rvisited[ns]+1 << endl;
                return 0;
            }
        }
        x = rq.front();
        rq.pop();
        for (int i = 0; i < 4; i++) {
            if (i==0 && x.pos%3==0) continue;
            if (i==1 && x.pos%3==2) continue;
            if (i==2 && x.pos < 3) continue;
            if (i==3 && x.pos > 5) continue;
            int nx = x.pos+dx[i];
            state ns = x.s;
            swap(ns[x.pos], ns[nx]);
            if (rvisited.count(ns) == 1) continue;
            if (visited.count(ns) == 1) {
                cout << rvisited[x.s]+visited[ns]+1 << endl;
                return 0;
            }
            node nn(ns, nx);
            rq.push(nn);
            rvisited[ns] = rvisited[x.s]+1;
        }
    }
}