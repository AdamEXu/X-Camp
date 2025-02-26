#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > board;

int flood(int x, int y) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size()) {
        return 0;
    } else if (board[x][y] != 1) {
        return 0;
    }
    int ct = 1;
    board[x][y] = 0;
    ct+=flood(x-1, y);
    ct+=flood(x+1, y);
    ct+=flood(x, y-1);
    ct+=flood(x, y+1);
    // cout << ct << endl;
    return ct;
}

int sizeofship(int x, int y) {
    int oldx = x, oldy = y;
    x=1;y=1;
    while (x < board.size() && board[oldx+x][oldy] == 1) {
        x++;
    }
    while (y < board[x].size() && board[oldx][oldy+y] == 1) {
        y++;
    }
    // cout << (x-oldx+1)*(y-oldy+1) << endl;
    return x*y;
}

int main(void) {
    int n, m;
    cin >> n >> m;
    board = vector<vector<int> >(n, vector<int>(m, 0));
    char tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            if (tmp == '#') {
                board[i][j] = 1;
            } else if (tmp == '.') {
                board[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << i << " " << j << endl;
            if (board[i][j] == 1) {
                count++;
                int size=sizeofship(i, j);
                cout << size << endl;
                int num = flood(i, j);
                cout << num << endl;
                if (num != size) {
                    cout << "Bad placement." << endl;
                    return 0;
                }
            }
        }
    }
    cout << "There are " << count << " ships." << endl;
}