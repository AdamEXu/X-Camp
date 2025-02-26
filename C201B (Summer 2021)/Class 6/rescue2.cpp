#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
using namespace std;

/*
Step 1	Start from 1,1; end 0,0
Step 2	push start to Q
step 3  current = Q.frontNode; Find all valid children of current
Step 4	isValidChild() true, put in queue
Step 5	Update rTime 2-D array
Step 6	Check end rountine
Step 7	 Dequeue parent node 
Step 8 repeat step 3 - 7
*/

// 32x2 board, start 1,1  end 0,0  - find shortest TIME

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
                if (board[validChildren[i].x][validChildren[i].y] == 'G' && currentCount+2 < temp) {
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
            notebook.push(validChildren[i]);
            // board[validChildren[i].x][validChildren[i].y] = 'Y';
        }
        // remove front node 
        notebook.pop();
    }
    return rTime[endx][endy];
}

int main(void) {
    // vector <vector<int>> map
    // char temp;
    int startx, starty, endx, endy, len1, len2;
    cin >> len1 >> len2;

    vector <vector <char> > map;

    for (int i = 0; i < len1; i++) {
        vector<char> elements;
        
        for (int j = 0; j < len2; j++) {
            char temp;
            cin >> temp;
            if (temp == '@') {
                startx = i, starty = j;
            }
            if (temp == 'M') {
                endx = i, endy = j;
            }
            elements.push_back(temp);
        }
        map.push_back(elements);
    }

    int temp = findShortestPath(len1, len2, startx, starty, endx, endy, map);
    if (temp == INT_MAX) {
        cout << "You can't save Mengxin" << endl;
    } else {
        cout << temp << endl;
    }
}