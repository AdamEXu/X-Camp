#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
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
        if (board[up.x][up.y] != '#' && board[up.x][up.y] != '@' && board[up.x][up.y] != 'Y')
            children.push_back(up);
    }
    if (isValid(down, n, m)) {
        if (board[down.x][down.y] != '#' && board[down.x][down.y] != '@' && board[down.x][down.y] != 'Y')
            children.push_back(down);
    }
    if (isValid(left, n, m)) {
        if (board[left.x][left.y] != '#' && board[left.x][left.y] != '@' && board[left.x][left.y] != 'Y')
            children.push_back(left);
    }
    if (isValid(right, n, m)) {
        if (board[right.x][right.y] != '#' && board[right.x][right.y] != '@' && board[right.x][right.y] != 'Y')
            children.push_back(right);
    }

    // Return the valid children as a Point array
    return children;
}


// n x m board; start (startx,starty); end (endx, endy)
// find shortest path from start to end point
// update steps[][]
// findShortestPath(3, 3, 0, 0, 2, 2)
int findShortestPath(int n, int m, int startx, int starty, int endx, int endy, vector <vector <char> > board) {
    int rTime[n][m], cost = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rTime[i][j] = -1;
        }
    }

    queue<Point> notebook;
    for (int i = 0; i < notebook.size(); i++) {
        notebook.pop();
    }

    // push start node to Q

    if (!isValid(Point(startx, starty), n, m)) {
        cout << "You can't save Mengxin";
        return -1;
    }

    notebook.push(Point(startx, starty));
    rTime[startx][starty] = 0;
    board[startx][startx] = 'Y';

    while (!notebook.empty()) {
        point currentNode = notebook.front();
        int currentCount = rTime[currentNode.x][currentNode.y]; 
        vector<point> validChildren = findValidChild(currentNode, n, m, board);

        for (int i = 0; i < validChildren.size(); i++) {
            // add to Q
            notebook.push(validChildren[i]);
            // update rtime[][]
            rTime[validChildren[i].x][validChildren[i].y] = currentCount+1;
            if (board[validChildren[i].x][validChildren[i].y] == 'G') {
                rTime[validChildren[i].x][validChildren[i].y]++;
            }
            board[validChildren[i].x][validChildren[i].y] = 'Y';
            
            // Exit check
            if (validChildren[i].x == endx && validChildren[i].y == endy) {
                return rTime[validChildren[i].x][validChildren[i].y];
            }
        }
        // remove front node 
        notebook.pop();
    }
    cout << "You can't save Mengxin" << endl;
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

    cout << findShortestPath(len1, len2, startx, starty, endx, endy, map) << endl;
}