#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int queen_count = 0;
int board[12][12];
int counter = 1;
int method_count =0;


// Return 0 if a queen can be placed at position (x, y).
// Return 1 if it cannot. 
// Parameters: (int x, int y)
bool is_safe(int x, int y) {
    if (board[x][y] != 0) {
        return false;
    }
    return true;
}

// Returns how many ways there are to arange n queens.
int n_queens(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (counter == 8) {
                method_count++;
            }
            if (is_safe(i, j)) {
                // Sets the queen down
                board[i][j] = counter;
                // Occupies rows and colomns
                for (int a = 0; a < n; a++) {
                    if (board[a][j] == 0) {
                        board[a][j] = counter;
                    }
                    if (board[i][a] == 0) {
                        board[i][a] = counter;
                    }
                }
                // Fills in the diaginals
                for (int m = 0; m < n; m++) {
                    if (board[i+m][j+m] == 0 && !(i+m < n || j+m < n)) {
                        board[i+m][j+m] = counter;
                    }
                    if (board[i+m][j-m] == 0 && !(i+m < n || j-m < 0)) {
                        board[i+m][j-m] = counter;
                    }
                    if (board[i-m][j+m] == 0 && !(i-m < 0 || j+m < n)) {
                        board[i-m][j+m] = counter;
                    }
                    if (board[i-m][j-m] == 0 && !(i-m < 0 || j-m < 0)) {
                        board[i-m][j-m] = counter;
                    }
                }
                int result = n_queens(n);
                if (result != -1) {
                    
                }
                counter++;
            }
            else if (i == n && j == n) {
                return -1;
            }
        }
    }
    return method_count;
}

// Driver code
int main(void) {
    int n;
    cin >> n;
    cout << n_queens(n) << endl;
}