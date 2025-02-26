#include <iostream>
#include <string>
#include <queue>
#include <limits.h>
using namespace std;

bool visited[100][100];
struct Point
{
	int x, y;
	Point(int a, int b)
	{
		x = a;
		y = b;
	}
};
int directionx[4] = {-1, 1, 0, 0};
int directiony[4] = {0, 0, -1, 1};

int maze[100][100];
unsigned long long steps[100][100];
queue<Point> notebook;

Point findPortalExit(Point current) {
    char portal_id = maze[current.x][current.y];
    maze[current.x][current.y] = '0';
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (maze[i][j] == portal_id) {
                Point exit_loc = Point(i, j);
                return exit_loc;
            }
        }
    }
    return Point(INT_MAX, INT_MAX);
}

void findValidNeighbors(int x, int y, int n, int m) {
    for(int i = 0; i < 4; i++) {
        Point out = Point(x+directionx[i], y+directiony[i]);

        // Out of bounds check
        if (out.x < 1 || out.y < 1) {
            continue;
        }
        if (out.x > n || out.y > m) {
            continue;
        }

        if (visited[out.x][out.y]) {
            if (maze[x][y] > 9) {
                steps[out.x][out.y] = min(steps[out.x][out.y], steps[x][y] + 1);
            }
            continue;
        }

        if (maze[out.x][out.y] == 1) {
            continue;
        }
        
        steps[out.x][out.y] = steps[x][y] + 1;

        if (maze[out.x][out.y] > 9) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (maze[out.x][out.y] == maze[i][j] && (i != out.x || j != out.y)) {
                        Point portalExit = findPortalExit(out);
                        steps[portalExit.x][portalExit.y] = min(steps[out.x][out.y], steps[i][j]);
                    }
                }
            }
        }


        notebook.push(Point(out.x, out.y));

        visited[out.x][out.y] = true;
    }
}


void WoW(int n, int m) {
  steps[1][1] = 0;
  visited[1][1] = true;
  
  notebook.push(Point(1, 1));
  
  while(!notebook.empty())
  {
    Point currentNode = notebook.front();
    int x = currentNode.x;
    int y = currentNode.y;

    if(x == n && y == m) break;

    findValidNeighbors(x, y, n, m);
    notebook.pop();
  }
  
  cout << steps[n][m]-1 << endl;
}


int main(void) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            maze[i][j] = 1;
        }
    }

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
		{
			char temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}

    WoW(n, m);
} 


