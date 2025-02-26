#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void) {
    // freopen("tttt.in", "r", stdin);
    // freopen("tttt.out", "w", stdout);
    bool singletictactoedwinners[26] = {false};
    set<string> doubletictactoedwinners;
    vector<vector<int> > board;
    for (int i = 0; i < 3; i++) {
        vector<int> row;
        for (int j = 0; j < 3; j++) {
            char x;
            cin >> x;
            row.push_back(int(x)-int('A'));
        }
        board.push_back(row);
    }
    // find all the wins on the tic tac toe board
    for (int i = 0; i < 3; i++) {
        set<int> cows;
        for (int j = 0; j < 3; j++) {
            if (cows.count(board[i][j]) == 1) {
                continue;
            } else {
                cows.insert(board[i][j]);
            }
        }
        if (cows.size() == 1) {
            singletictactoedwinners[*cows.begin()] = true;
        } else if (cows.size() == 2) {
            doubletictactoedwinners.insert(string(1, char(*cows.begin()+int('A'))) + string(1, char(*cows.rbegin()+int('A'))));
            doubletictactoedwinners.insert(string(1, char(*cows.rbegin()+int('A'))) + string(1, char(*cows.begin()+int('A'))));
        }
    }
    for (int i = 0; i < 3; i++) {
        set<int> cows;
        for (int j = 0; j < 3; j++) {
            if (cows.count(board[j][i]) == 1) {
                continue;
            } else {
                cows.insert(board[j][i]);
            }
        }
        if (cows.size() == 1) {
            singletictactoedwinners[*cows.begin()] = true;
        } else if (cows.size() == 2) {
            doubletictactoedwinners.insert(string(1, char(*cows.begin()+int('A'))) + string(1, char(*cows.rbegin()+int('A'))));
            doubletictactoedwinners.insert(string(1, char(*cows.rbegin()+int('A'))) + string(1, char(*cows.begin()+int('A'))));
        }
    }
    // diaginals
    set<int> cows;
    for (int i = 0; i < 3; i++) {
        if (cows.count(board[i][i]) == 1) {
            continue;
        } else {
            cows.insert(board[i][i]);
        }
    }
    if (cows.size() == 1) {
        singletictactoedwinners[*cows.begin()] = true;
    } else if (cows.size() == 2) {
        doubletictactoedwinners.insert(string(1, char(*cows.begin()+int('A'))) + string(1, char(*cows.rbegin()+int('A'))));
        doubletictactoedwinners.insert(string(1, char(*cows.rbegin()+int('A'))) + string(1, char(*cows.begin()+int('A'))));
    }
    cows.clear();
    for (int i = 0; i < 3; i++) {
        if (cows.count(board[i][2-i]) == 1) {
            continue;
        } else {
            cows.insert(board[i][2-i]);
        }
    }
    if (cows.size() == 1) {
        singletictactoedwinners[*cows.begin()] = true;
    } else if (cows.size() == 2) {
        doubletictactoedwinners.insert(string(1, char(*cows.begin()+int('A'))) + string(1, char(*cows.rbegin()+int('A'))));
        doubletictactoedwinners.insert(string(1, char(*cows.rbegin()+int('A'))) + string(1, char(*cows.begin()+int('A'))));
    }
    int singles = 0, doubles = 0;
    for (int i = 0; i < 26; i++) {
        if (singletictactoedwinners[i]) {
            singles++;
        }
    }
    // find the number of trues in doubletictactoedwinners
    for (set<string>::iterator it = doubletictactoedwinners.begin(); it != doubletictactoedwinners.end(); it++) {
        if (singletictactoedwinners[int(it->at(0))] && singletictactoedwinners[int(it->at(1))]) {
            doubles++;
        }
    }
    cout << singles << endl << doubles << endl;
}