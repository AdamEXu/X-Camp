#include<iostream>
#include<vector>
#include<string>
#include<cctype>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>
#include<climits>
using namespace std;

struct point {
    int x;
    int y;
    point(int a, int b) {
        x=a;
        y=b;
    }
};

bool isValid(point a, int n, int m) {
    if ((a.x < 0 || a.y < 0) || (a.x >= n || a.y >= m)) {
        return false;
    }
    return true;
}

vector<point> findValidChild(point current, int n, int m, vector <vector <char> > board) {
    vector<point> children;
    point up = point(current.x-1, current.y);
    point down = point(current.x+1, current.y);
    point left = point(current.x, current.y-1);
    point right = point(current.x, current.y+1);

    if (isValid(up, board.size(), board[0].size())) {
        if (board[up.x][up.y] != '#' && board[up.x][up.y] != 'Y')
            children.push_back(up);
    }
    if (isValid(down, board.size(), board[0].size())) {
        if (board[down.x][down.y] != '#' && board[down.x][down.y] != 'Y')
            children.push_back(down);
    }
    if (isValid(left, board.size(), board[0].size())) {
        if (board[left.x][left.y] != '#' && board[left.x][left.y] != 'Y')
            children.push_back(left);
    }
    if (isValid(right, board.size(), board[0].size())) {
        if (board[right.x][right.y] != '#' && board[right.x][right.y] != 'Y')
            children.push_back(right);
    }

    return children;
}

int shortest_path(point startYou, point startFriend, point end, int n, int m, vector<vector<char> > map) {
    queue<point> notebookYou;
    queue<point> notebookFriend;

    notebookFriend.push(startFriend);
    notebookYou.push(startYou);
    int distanceYou[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            distanceYou[i][j] = INT_MAX;
        }
    }
    int distanceFriend[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            distanceFriend[i][j] = INT_MAX;
        }
    }

    vector<vector<char> > mapYou;
    vector<vector<char> > mapFriend;

    mapYou = map;
    mapFriend = map;

    int distanceA = INT_MAX;
    int distanceB = INT_MAX;

    while (!notebookYou.empty()) {
        point currentNode = notebookYou.front();
        int currentCount = distanceYou[currentNode.x][currentNode.y]; 
        vector<point> validChildren = findValidChild(currentNode, n, m, mapYou);

        for (int i = 0; i < validChildren.size(); i++) {
            notebookYou.push(validChildren[i]);
            distanceYou[validChildren[i].x][validChildren[i].y]++;

            mapYou[validChildren[i].x][validChildren[i].y] = 'Y';
            
            if (validChildren[i].x == end.x && validChildren[i].y == end.y) {
                distanceA = distanceYou[validChildren[i].x][validChildren[i].y];
            }
        }
        notebookYou.pop();
    }

    while (!notebookFriend.empty()) {
        point currentNode = notebookFriend.front();
        int currentCount = distanceFriend[currentNode.x][currentNode.y]; 
        vector<point> validChildren = findValidChild(currentNode, n, m, mapFriend);

        for (int i = 0; i < validChildren.size(); i++) {
            notebookFriend.push(validChildren[i]);
            distanceFriend[validChildren[i].x][validChildren[i].y]++;

            mapFriend[validChildren[i].x][validChildren[i].y] = 'Y';
            
            if (validChildren[i].x == end.x && validChildren[i].y == end.y) {
                distanceB = distanceFriend[validChildren[i].x][validChildren[i].y];
            }
        }
        notebookFriend.pop();
    }

    return distanceA+distanceB;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > map;
    vector<point> kfc_loc;
    point start = point(0,0), end = point(0,0);
    for (int i = 0; i < n; i++) {
        vector<char> tempVec;
		for (int j = 0; j < m; j++) {
			char temp;
			cin >> temp;
            if (temp == 'F') {
                kfc_loc.push_back(point(i, j));
            }
            if (temp == '@') {
                cout << "Found start YOU" << endl;
                start.x = i;
                start.y = j;
            }
            if (temp == '&') {
                cout << "Found start FRIEND" << endl;
                end.x = i;
                end.y = j;
            }
			tempVec.push_back(temp);
		}
        map.push_back(tempVec);
	}
    int result = INT_MAX;
    for (int i = 0; i < kfc_loc.size(); i++) {
        int temp = shortest_path(start, end, kfc_loc[i], n, m, map);
        if (temp < result) {
            result = temp;
        }
    }
    cout << result << endl;
    return 0;
}