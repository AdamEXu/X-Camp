#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct coord {
  int x, y;
};

int n, m;
int map[201][201];
int visited[201][201];
vector<vector<int> > sDist(201, vector<int>(201, 0));
vector<vector<int> > fDist(201, vector<int>(201, 0));
int dir[5] = {0, 1, 0, -1, 0};
int inBound(int x, int y) {
  if (x >= 0 && y >= 0 && x < n && y < m && visited[x][y] == 0 &&
      map[x][y] != 1) {
    return true;
  }
  return false;
}

void resetVis() { // reset viisted array
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      visited[i][j] = 0;
    }
  }
}
void bfs(coord point, vector<vector<int> > &dist) {
  int count = 0;
  queue<coord> q;
  q.push(point);
  visited[point.x][point.y] = 1;
  dist[point.x][point.y] = count;

  int x, y;
  while (!q.empty()) {
    coord cur = q.front();
    x = cur.x;
    y = cur.y;
    q.pop();
    int nx, ny;
    for (int i = 0; i < 4; i++) {
      nx = x + dir[i];
      ny = y + dir[i + 1];

      if (inBound(nx, ny)) {
        visited[nx][ny] = 1;
        dist[nx][ny] = dist[x][y] + 1;
        coord nPoint;
        nPoint.x = nx;
        nPoint.y = ny;
        q.push(nPoint);
      }
    }
  }
}
int main() {

  cin >> n >> m;
  coord ps;
  coord pf;

  // 4 is KFC
  // 3 is friend spot
  // 2 is self spot
  // 1 is blocker
  // 0 is route

  for (int i = 0; i < n; i++) {
    string curLine;
    cin >> curLine;
    for (int j = 0; j < m; j++) {
      if (curLine[j] == 'F') {
        map[i][j] = 4;
      } else if (curLine[j] == '&') {
        map[i][j] = 3;
        pf.x = i;
        pf.y = j;

      } else if (curLine[j] == '@') {
        map[i][j] = 2;
        ps.x = i;
        ps.y = j;
      }

      else if (curLine[j] == '#') {
        map[i][j] = 1;
      } else {
        map[i][j] = 0;
      }
      visited[i][j] = 0;
    }
  }

  bfs(ps, sDist);
  if (sDist[pf.x][pf.y] == 0) {
    cout << "Meeting cancelled" << endl;
    return 0;
  }

  resetVis();
  bfs(pf, fDist);
  int least = 2147483647;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] == 4) {
        if (sDist[i][j] && fDist[i][j]) {
          int curDist = sDist[i][j] + fDist[i][j];
          least = min(curDist, least);
        }
      }
    }
  }
  cout << least << endl;

  return 0;
}