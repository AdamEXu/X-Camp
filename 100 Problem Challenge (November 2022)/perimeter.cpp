#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<vector<int> > maze (100, vector<int> (100, 0));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> y >> x;
        maze[100-x][y-1] = 1;
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cout << maze[i][j] << ' ';
        }
        cout << '\n';
    }
    int perimeter = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (maze[i][j] == 1) {
                int count = 0;
                if (i >= 0 && maze[i-1][j] == 0) {
                    // if maze[i-1][j] is surrounded by 1s, then it's not a perimeter
                    if (i-2 >= 0 && maze[i-2][j] == 0 && i-1 >= 0 && maze[i-1][j-1] == 0 && i-1 >= 0 && maze[i-1][j+1] == 0) {
                        count++;
                    }
                }
                if (i < 100 && maze[i+1][j] == 0) {
                    if (i+2 < 100 && maze[i+2][j] == 0 && i+1 < 100 && maze[i+1][j-1] == 0 && i+1 < 100 && maze[i+1][j+1] == 0) {
                        count++;
                    }
                }
                if (j >= 0 && maze[i][j-1] == 0) {
                    if (j-2 >= 0 && maze[i][j-2] == 0 && j-1 >= 0 && maze[i-1][j-1] == 0 && j-1 >= 0 && maze[i+1][j-1] == 0) {
                        count++;
                    }
                }
                if (j < 100 && maze[i][j+1] == 0) {
                    if (j+2 < 100 && maze[i][j+2] == 0 && j+1 < 100 && maze[i-1][j+1] == 0 && j+1 < 100 && maze[i+1][j+1] == 0) {
                        count++;
                    }
                }
                perimeter += count;
            }
        }
    }
    cout << perimeter << '\n';
}