#include <iostream>
#include <vector>
using namespace std;
vector<int> flibber;

int labyrinth(vector<vector<int> > maze, int x, int y, int n, int d) {
    if (x < 0 || y < 0 || x >= n || y >= n) {
        return 2147483647;
    } else if (maze[x][y] == 1) {
        return 2147483647;
    } else if (maze[x][y] == 2) {
        return 2147483647;
    } else if (x == n-1 && y == n-1) {
        flibber.push_back(d+1);
        return d+1;
    }
    maze[x][y] = 2;
    int a = labyrinth(maze, x+1, y, n, d+1);
    int b = labyrinth(maze, x-1, y, n, d+1);
    int shortestnum = 1;
    if (a == b)
        shortestnum++;
    else if (b < a)
        a = b;
        shortestnum = 1;
    b = labyrinth(maze, x, y+1, n, d+1);
    if (a == b)
        shortestnum++;
    else if (b < a)
        a = b;
        shortestnum = 1;
    b = labyrinth(maze, x, y-1, n, d+1);
    if (a == b)
        shortestnum++;
    else if (b < a)
        a = b;
        shortestnum = 1;
    return a;
}

int main(void) {
    int n;
    cin >> n;
    vector<vector<int> > maze;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            int b;
            cin >> b;
            temp.push_back(b);
        }
        maze.push_back(temp);
    }
    int temp = labyrinth(maze, 0, 0, n, 0);
    int count = 0;
    for (int i = 0; i < flibber.size(); i++) {
        if (flibber[i] == temp) {
            count++;
        }
    }
    cout << count << endl << temp << endl;
}