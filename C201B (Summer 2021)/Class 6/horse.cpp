#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

/*
Step 1	Start from 1,1
Step 2	Find all child nodes
Step 3	isValidChild() true, put in queue
Step 4	Update steps 2-D array
Step 5	Dequeue parent node
Step 6	Check end rountine
*/

// 3x3 board, start 1,1  end 3,3  - find shortest path

struct Point {
    int x;
    int y;

    Point(int a, int b) {
        x = a;
        y = b;
    }
};

vector <int> convert_int_to_Intvec(int input) {
    stack<int> sd;
    vector <int> my_output;

    if (input == 0) {
        vector<int> temp;
        temp.push_back(0);
        return temp;
    }

    while (input > 0)
    {
        int digit = input%10;
        input /= 10;
        sd.push(digit);
    }

    while (!sd.empty())
    {
        int digit = sd.top();
        sd.pop();
        my_output.push_back(digit);
    }
    return my_output;
}

bool isValid(Point a, int n, int m) {
    // Check if it goes out of bounds
    if ((a.x < 0 || a.y < 0) || (a.x >= n || a.y >= m)) {
        return false;
    }
    return true;
}

vector<Point> findValidChild(Point current, int n, int m) {
    vector<Point> children;
    // Up
    Point upLeft = Point(current.x-2, current.y-1);
    Point upRight = Point(current.x-2, current.y+1);
    // Down
    Point downLeft = Point(current.x+2, current.y-1);
    Point downRight = Point(current.x+2, current.y+1);
    // Left
    Point leftUp = Point(current.x-1, current.y-2);
    Point leftDown = Point(current.x+1, current.y-2);
    // Right
    Point rightUp = Point(current.x-1, current.y+2);
    Point rightDown = Point(current.x+1, current.y+2);

    // Check if the children are valid
    if (isValid(upLeft, n, m)) {
        children.push_back(upLeft);
    }
    if (isValid(upRight, n, m)) {
        children.push_back(upRight);
    }
    if (isValid(downLeft, n, m)) {
        children.push_back(downLeft);
    }
    if (isValid(downRight, n, m)) {
        children.push_back(downRight);
    }
    if (isValid(leftDown, n, m)) {
        children.push_back(leftDown);
    }
    if (isValid(leftUp, n, m)) {
        children.push_back(leftUp);
    }
    if (isValid(rightDown, n, m)) {
        children.push_back(rightDown);
    }
    if (isValid(rightUp, n, m)) {
        children.push_back(rightUp);
    }

    // Return the valid children as a Point array
    return children;
}


// n x m board; start (startx,starty); end (endx, endy)
// find shortest path from start to end point
// update steps[][]
// findShortestPath(3, 3, 0, 0, 2, 2)
int findShortestPath(int n, int m, int startx, int starty, int endx, int endy) {
    int steps[n][m];
    // cout << "Initial steps[][]: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            steps[i][j] = -1;
            // cout << steps[i][j] << "     ";
        }
        // cout << endl;
    }

    queue<Point> notebook;
    notebook.push(Point(startx, starty));
     int count = 0;
    steps[startx][starty] = count;
 
   
    while (!notebook.empty()) {

        Point currentNode = notebook.front();
        // cout << "current node x and y is:  " << endl;
        // cout << currentNode.x << "; " << currentNode.y << "." << endl;

        int currentCount = steps[currentNode.x][currentNode.y];
        // find 
        vector<Point> validChildren = findValidChild(currentNode, n, m);

        if (validChildren.size() != 0) {
            // cout << "I am in, valid children size = " << validChildren.size()  << endl;
            count++;
            // for each child note
            for (int i = 0; i < validChildren.size(); i++) {
                // add to Q
                if (steps[validChildren[i].x][validChildren[i].y] == -1) {
                    notebook.push(validChildren[i]);
                    // update steps[][]
                    steps[validChildren[i].x][validChildren[i].y] = currentCount + 1;
                    // cout << "child count = " << steps[validChildren[i].x][validChildren[i].y] << endl;
                }
                
                // // Exit check
                if (validChildren[i].x == endx && validChildren[i].y == endy) {
                    return steps[validChildren[i].x][validChildren[i].y];
                }
            }
        }
        // remove front node 
        notebook.pop();
        // if (notebook.empty() == true) {
        //     cout << "notebook empty" << endl;
        //     return -1;
        // }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (steps[i][j] == -1) {
                cout << "-1   ";
            } else {
                cout << steps[i][j];
                int len = convert_int_to_Intvec(steps[i][j]).size();
                int spaces = 5 - len;
                for (int a = 0; a < spaces; a++) {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    return -1;
}

void print_vector(vector<Point> input) {
    for (int i = 0; i < input.size(); i++) {
        cout << input[i].x << " " << input[i].y << endl;
    }
}

int main(void) {
    // cout << "hello world!" << endl;
    // Get input from console
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    // cout << "n = " << n << ", m = " << m << ", x = " << x << ", y = " << y << endl;

    // x--;
    // y--;

    // int steps[n][m];

    // queue <Point> notebook;

    // print_vector(findValidChild(Point(0,0), 3, 3));
    // findShortestPath(3, 3, 0, 0, 2, 2)
    findShortestPath(n, m, x-1, y-1, n-1, m-1);
}