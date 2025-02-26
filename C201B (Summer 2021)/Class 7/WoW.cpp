#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
using namespace std;

struct Point {
    int x;
    int y;

    Point(int a, int b) {
        x = a;
        y = b;
    }
};

// INside boundary check
bool isValid(Point a, int n, int m) {
    // Check if it goes out of bounds
    if ((a.x < 0 || a.y < 0) || (a.x >= n || a.y >= m)) {
        return false;
    }
    return true;
}

// 4 directions move, one step only, (UP, DOWN, LEFT, RIGHT)
// for valid 
//      - need to be in the boundary
//      - Can not move: #    

vector<Point> findValidChild(Point current, int n, int m, vector <vector <char> > board) {
    vector<Point> children;
    // Up
    Point up = Point(current.x-1, current.y);
    // Down
    Point down = Point(current.x+1, current.y);
    // Left
    Point left = Point(current.x, current.y-1);
    // Right
    Point right = Point(current.x, current.y+1);

    // cout << board[current.x][current.y] << endl;
    // cout << n << endl;
    // cout << m << endl;

    // Check if the children are valid
    if (isValid(up, n, m)) {
        if (board[up.x][up.y] != '#' && board[up.x][up.y] != '@')
            children.push_back(up);
    }
    if (isValid(down, n, m)) {
        if (board[down.x][down.y] != '#' && board[down.x][down.y] != '@')
            children.push_back(down);
    }
    if (isValid(left, n, m)) {
        if (board[left.x][left.y] != '#' && board[left.x][left.y] != '@')
            children.push_back(left);
    }
    if (isValid(right, n, m)) {
        if (board[right.x][right.y] != '#' && board[right.x][right.y] != '@')
            children.push_back(right);
    }

    // Return the valid children as a Point array
    return children;
}

bool isFound(queue<Point> notebook, Point element) {
    for (int i = 0; i < notebook.size(); i++) {
        if (notebook.front().x == element.x && notebook.front().y == element.y) {
            return true;
        }
        notebook.pop();
    }
    return false;
}

bool findPortal(char input) {
    if (int(toupper(input)) >= 65 && int(toupper(input)) <= 90) {
        return true;
    }
    return false;
}

Point findPortalExit(Point current, vector<vector<char> > board) {
    char portal_id = board[current.x][current.y];
    board[current.x][current.y] = '0';
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == portal_id) {
                Point exit_loc = Point(i, j);
                return exit_loc;
            }
        }
    }
    return Point(INT_MAX, INT_MAX);
}

// n x m board; start (startx,starty); end (endx, endy)
// find shortest path from start to end point
// update steps[][]
// findShortestPath(3, 3, 0, 0, 2, 2)
int findShortestPath(int n, int m, int startx, int starty, int endx, int endy, vector <vector <char> > board) {
    int rTime[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rTime[i][j] = INT_MAX;
        }
    }

    queue<Point> notebook;
    for (int i = 0; i < notebook.size(); i++) {
        notebook.pop();
    }

    // push start node to Q

    if (!isValid(Point(startx, starty), n, m)) {
        // cout << "You can't save Mengxin";
        return INT_MAX;
    }

    notebook.push(Point(startx, starty));
    rTime[startx][starty] = 0;
    // board[startx][startx] = 'Y';

    while (!notebook.empty()) {
        Point currentNode = notebook.front();
        int currentCount = rTime[currentNode.x][currentNode.y]; 
        vector<Point> validChildren = findValidChild(currentNode, n, m, board);

        for (int i = 0; i < validChildren.size(); i++) {
            // update rtime[][]
            int temp = rTime[validChildren[i].x][validChildren[i].y];
            if (currentCount+1 < temp) {
                rTime[validChildren[i].x][validChildren[i].y] = currentCount+1;
                if ((board[validChildren[i].x][validChildren[i].y]) != '0' && currentCount+2 < temp) {
                    rTime[validChildren[i].x][validChildren[i].y]++;
                } else if (currentCount+1 > temp) {
                    rTime[validChildren[i].x][validChildren[i].y] = temp;
                    // notebook.pop();
                    continue;
                }
            } else {
                // notebook.pop();
                continue;
            }
            // add to Q
            // if (!isFound(notebook, validChildren[i]))
            if (findPortal(board[validChildren[i].x][validChildren[i].y])) {
                notebook.push(findPortalExit(Point(validChildren[i].x, validChildren[i].y), board));
            } else {
                notebook.push(validChildren[i]);
            }
            // board[validChildren[i].x][validChildren[i].y] = 'Y';
        }
        // remove front node 
        notebook.pop();
    }
    return rTime[endx][endy];
}

int main(void) {
    int n, m;
    cin >> n >> m;

    vector <vector <char> > map;
 
    for (int i = 0; i < n; i++) {
        vector<char> elements;
        
        for (int j = 0; j < m; j++) {   
            char temp;
            std::cin >> temp;
            elements.push_back(temp);
        }
        map.push_back(elements);
    }

    int result = findShortestPath(n, m, 0, 0, n-1, m-1, map);
    if (result != INT_MIN+1) {std::cout << result << endl;}
    else {std::cout<<"No Solution."<<endl;}
}