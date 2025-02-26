#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// void bfs(){    
// while(!Q.empty()){
//     top=Q.front();
//     if(top.x==ex&&top.y==ey) {
//         flag=true;
//         cout<< top.step; return ;   
//         }
//     if(a[top.x][top.y]=='G') {
//         top.step++;Q.push(top);Q.pop();a[top.x][top.y]='.'; 
//         continue; 
//     }
//     Q.pop();
//     for(int i=0;i<4;i++)
//     {   int t1=top.x+dx[i];
//         int t2=top.y+dy[i];
//         if(t1<1||t1>n||t2<1||t2>m||a[t1][t2]=='#') continue;
//         if(b[t1][t2]) continue;
//         node.x=t1;
//         node.y=t2;
//         int step1=top.step+1;
//         node.step=step1; 
// //        cout<<"("<<t1<<","<<t2<<")\n";     
//         Q.push(node);
//         b[t1][t2]=true;
//     }
// }
// }

struct Point {
    int x;
    int y;
    int step;

    Point(int a, int b, int c) {
        x=a;
        y=b;
        step=c;
    }
};

queue<Point> notebook;
bool visited[200][200];

void findShortestPath(int n, int m, Point start, Point end) {
    bool flag = false;
    cout << "hello world" << endl;
    // push start node to Q
    notebook.push(start);
    visited[start.x][start.y] = true;
    while(!notebook.empty()) {
        Point current = notebook.front();
        if (current.x == end.x && current.y == end.y) {
            flag = true;
            cout << current.step << endl;
            return;
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

    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            visited[i][j] = false;
        }
    }

    findShortestPath(len1, len2, Point(startx,starty,0), Point(endx,endy,0));
}