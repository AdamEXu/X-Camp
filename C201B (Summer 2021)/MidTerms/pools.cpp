#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > findNeighbors(vector<vector<int> > board, int n, int m, int x, int y) {
    if (x<0||y<0||x>=n||y>=m) {
        return board;
    }
    if (board[x][y]==2||board[x][y]==0) {
        return board;
    }

    board[x][y] = 2;

    board = findNeighbors(board, n, m, x+1, y);
    board = findNeighbors(board, n, m, x, y+1);
    board = findNeighbors(board, n, m, x-1, y);
    board = findNeighbors(board, n, m, x, y-1);
    board = findNeighbors(board, n, m, x+1, y+1);
    board = findNeighbors(board, n, m, x+1, y-1);
    board = findNeighbors(board, n, m, x-1, y+1);
    board = findNeighbors(board, n, m, x-1, y-1);

    return board;
}

int main(void) {
    int n, m;
    cin >> n >> m;

    vector <vector <int> > board;

    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            char temp2;
            cin >> temp2;
            temp.push_back(int(temp2)-int('0'));
        }
        board.push_back(temp);
    }

    int puddles = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) {
                board = findNeighbors(board, n, m, i, j);
                puddles++;
            }
        }
    }

    cout << puddles << endl;
}