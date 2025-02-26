#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    vector<vector<int> > field;
    vector<int> row;
    for (int j = 0; j < 2000; j++) {
        row.push_back(0);
    }
    for (int i = 0; i < 2000; i++) {
        field.push_back(row);
    }
    int n, time = 0, maxx = -1;
    cin >> n;
    int x = 999, y = 999;
    for (int i = 0; i < n; i++) {
        // cout << time << endl;
        char direction;
        int steps;
        cin >> direction >> steps;
        if (direction == 'N') {
            for (int j = 0; j < steps; j++) {
                if (field[x][y] < time && field[x][y] != 0) {
                    if (maxx != -1) {
                        maxx = min(maxx, time-field[x][y]);
                    } else {
                        maxx = time-field[x][y];
                    }
                    field[x][y] = time;
                } else {
                    field[x][y] = time;
                }
                y--;
                time++;
            }
        } else if (direction == 'S') {
            for (int j = 0; j < steps; j++) {
                if (field[x][y] < time && field[x][y] != 0) {
                    if (maxx != -1) {
                        maxx = min(maxx, time-field[x][y]);
                    } else {
                        maxx = time-field[x][y];
                    }
                    field[x][y] = time;
                } else {
                    field[x][y] = time;
                }
                y++;
                time++;
            }
        } else if (direction == 'E') {
            for (int j = 0; j < steps; j++) {
                if (field[x][y] < time && field[x][y] != 0) {
                    if (maxx != -1) {
                        maxx = min(maxx, time-field[x][y]);
                    } else {
                        maxx = time-field[x][y];
                    }
                    field[x][y] = time;
                } else {
                    field[x][y] = time;
                }
                x++;
                time++;
            }
        } else if (direction == 'W') {
            for (int j = 0; j < steps; j++) {
                if (field[x][y] < time && field[x][y] != 0) {
                    if (maxx != -1) {
                        maxx = min(maxx, time-field[x][y]);
                    } else {
                        maxx = time-field[x][y];
                    }
                    field[x][y] = time;
                } else {
                    field[x][y] = time;
                }
                x--;
                time++;
            }
        }
    }
    cout << maxx << endl;
}