#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <set>
#include <list>
using namespace std;

struct Point {
    int x;
    int y;
    int step;

    Point(int a, int b, int temp) {
        x = a;
        y = b;
        step = temp;
    }
};

queue<Point> Q;
bool b[200][200];

void findShortestPath(){    
    Point top();
    bool flag;
    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    while(!Q.empty()){
        top=Q.front();
        if (top.x == ex && top.y == ey) {
            flag = true;
            cout << top.step; 
            return;   
            }
        if (a[top.x][top.y]=='G') {
            top.step++;
            Q.push(top);
            Q.pop();
            a[top.x][top.y]='.'; 
            continue; 
        }
        Q.pop();
        for(int i=0;i<4;i++) {
            // 4 directions move
            // t1 - row ; dx[] - -1, +1, 0, 0
            int t1=top.x+dx[i];
            // t2 - col; dy[] - 0, 0, -1, +1
            int t2=top.y+dy[i];

            // invalid - case of outof boundary, case of #
            if(t1<1||t1>n||t2<1||t2>m||a[t1][t2]=='#') 
                continue;
            
            // boolean 2D arry, visited or not
            if(b[t1][t2]) 
                continue;
            

            Point() node;
            node.y=t2;
            int step1=top.step+1;
            node.step=step1; 
    //        cout<<"("<<t1<<","<<t2<<")\n";     
            Q.push(node);
            b[t1][t2]=true;
        }
    }
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

    findShortestPath(len1, len2, startx, starty, endx, endy, map);
    
}