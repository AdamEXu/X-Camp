#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>
// #include <bits/stdc++.h>
using namespace std;

list <list <string> > res;

int lenOf2D(int inarr[10][10]) {
    int size = sizeof(inarr)/sizeof(inarr[0]);
    return size;
}

int lenOf(int inarr[]) {
    int size = sizeof(inarr)/sizeof(inarr[0]);
    return size;
}

void addToList(int board[10][10]) {
    list<string> mylist;
    for (int i = 0; i < lenOf2D(board); i++) {
        string temp = "";
        for (int j = 0; j < lenOf2D(board); j++) {
            if (board[i][j] == 0) {
                temp += ".";
            }
            else {
                temp += "Q";
            }
        }
        mylist.push_back(temp);
    }
    res.push_back(mylist);
}

// void placeQueen(int board[10][10], int i, set <int> diagonal, set<int> diagonal2, set<int> vertical) {
//     if (i == lenOf2D(board)) {
//         addToList(board);
//         return;
//     }
//     for (int j = 0; j < lenOf2D(board); j++) {
//         if (!diagonal.find(i+j) == diagonal2.back() && !diagonal2.find(j-i) == diagonal.back()) {
//             board[i][j] = 1;
//             diagonal.push_back(i+j); 
//             diagonal2.push_back(j-i);
//             vertical.push_back(j);
//             placeQueen(board, i+1, diagonal, diagonal2, vertical);
//             board[i][j] = 0;
//             diagonal.push_back(i+j);
//             diagonal2.push_back(j-i);
//             vertical.push_back(j);
//         }
//     }
// }

int main(void) {
    int n;
    cin >> n;
    int board[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    set <int> diagonal1;
    set <int> diagonal2;
    set <int> vertical;
    // placeQueen(board, 0, diagonal1, diagonal2, vertical);
    cout << "test" << endl;
}