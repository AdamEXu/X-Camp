#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int input(istream& in=cin) {
    int x;
    in >> x;
    return x;
}

int main(void) {
    int x=0, y=0, current = 1, n = input(), a = input(), b = input();
    vector<vector<int> > matrix;
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        temp.push_back(-1);
    }
    for (int i = 0; i < n; i++) {
        matrix.push_back(temp);
    }
    while (current < n*n) {
        for (int i = y; i < n-y-1; i++) {
            if (current >= n*n) {
                // cout << "why u here? btw current is currently this value right over here: " << current << endl;
                break;
            }
            matrix[x][i] = current;
            current++;
            // matrixout(matrix);
            // cout << endl;
        }
        for (int i = x; i < n-x; i++) {
            if (current >= n*n) {
                // cout << "why u here? btw current is currently this value right over here: " << current << endl;
                break;
            }            matrix[i][n-y-1] = current;
            current++;
            // matrixout(matrix);
            // cout << endl;
            // cout << i << endl;
        } 
        for (int i = n-y-2; i >= y; i--) {
            if (current >= n*n) {
                // cout << "why u here? btw current is currently this value right over here: " << current << endl;
                break;
            }
            matrix[n-x-1][i] = current;
            current++;
            // matrixout(matrix);
            // cout << endl;
        }
        x++;
        for (int i = n-x-1; i >= x; i--) {
            if (current >= n*n) {
                // cout << "why u here? btw current is currently this value right over here: " << current << endl;
                break;
            }
            matrix[i][y] = current;
            current++;
            // matrixout(matrix);
            // cout << endl;
        }
        y++;
    }
    if (n % 2 == 0) {
        matrix[n/2][n/2-1] = n*n;
    } else {
        matrix[n/2][n/2] = n*n;
    }
    // matrixout(matrix);

    cout << matrix[a-1][b-1] << endl;
}