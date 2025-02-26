#include <iostream>
#include <vector>
using namespace std;
vector<vector<char> > board;
int rectangles = 0, n, m;
  
bool rectangle_elim(int x, int y) {
    rectangles++;
    int l=x, w=y;
    int olx=x, oly=y;
    while (l < n && board[l][y] == '#') {
        l++;
    }
    while (w < m && board[x][w] == '#') {
        w++;
    }
    int olw = w, oll = l;
 
      
    if (x-1 >= 0) {
        x--;
    } 
    if (y-1 >= 0) {
        y--;
    } 
    if (l+1 < n) {
        l++;
    } 
    if (w+1 < m) {
        w++;
    }
    cout << x << " " << y << endl;
    cout << l << " " << w << endl;
    int counter = 0;
    for (int i = x; i < l; i++) {
        for (int j = y; j < w; j++) {
            if (board[i][j] == '#') {
                board[i][j] = '.';
                counter++;
            }
        }
    }
    cout << counter << endl;
    if (counter == (oll-olx)*(olw-oly)) {
        return true;
    }
    return false;
}
  
int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<char> temp;
        for (int j = 0; j < m; j++) {
            char t;
            cin >> t;
            temp.push_back(t);
        }
        board.push_back(temp);
    }
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '#') {
                if (!rectangle_elim(i, j)) {
                    cout << "Bad placement." << endl;
                    return 0;
                }
            }
        }
    }
    cout << "There are " << rectangles << " ships." << endl;
}