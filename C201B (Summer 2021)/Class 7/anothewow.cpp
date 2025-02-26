#include <iostream>
#include <string>
#include <queue>
#include <climits>

#define ROW 4
#define COL 5

bool visited[ROW][COL];

using namespace std;

struct point
{
	int x, y;
	point(int a, int b)
	{
		x = a;
		y = b;
	}
};

int sx, sy, ex, ey;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int maze[ROW][COL];
unsigned long long dist[ROW][COL];
// unsigned long long ways[200][200];
queue<point> q;
//int steps = 0;
int n, m;

void explore_neighbours(int x, int y) {
  		for(int i = 0; i < 4; i++)
			{
				int new_x = x + dx[i];
				int new_y = y + dy[i];
				
        //Out of bound
        if(new_x < 1 || new_y < 1) continue;
        if(new_x > n || new_y > m) continue;

        if(visited[new_x][new_y] == true) {
          if (maze[x][y] > 9) {
            dist[new_x][new_y] = min(dist[new_x][new_y], dist[x][y] + 1);
          }
          continue;
        }


        //Blocked cell
        if(maze[new_x][new_y] == 1) continue;
        
        //All edge cases are excluded
        dist[new_x][new_y] = dist[x][y] + 1;


        if(maze[new_x][new_y] > 9)
        {
          for(int i=1;i<=n;i++)
          {
            for(int j=1;j<=m;j++)
            {
              if(maze[new_x][new_y] == maze[i][j] && (i != new_x || j != new_y))
              {
                dist[new_x][new_y] = min(dist[new_x][new_y], dist[i][j]);
              }
            }
          }
        }


        q.push(point(new_x, new_y));

        visited[new_x][new_y] = true;
		}
	}


void solve() {
  
  //Initialization
  dist[1][1] = 0;
  visited[1][1] = true;
  
  q.push(point(1, 1));
  
  while(!q.empty())
  {
    point curr = q.front();
    int x = curr.x;
    int y = curr.y;

    if(x == n && y == m) break;

    explore_neighbours(x, y);
    q.pop();
  }
  
  cout << dist[n][m];
}


int main()
{
  //Pre-process
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1; j <= m; j++)
		{
			char c;
			cin>> c;
			maze[i][j] = c - '0';
		}
	}


  memset(dist,0x7f,sizeof(dist));

  //BFS solution
  solve();

} 


