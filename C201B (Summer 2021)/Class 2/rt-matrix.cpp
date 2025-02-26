#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    vector<vector<int> > matrix;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            int foo;
            cin >> foo;
            temp.push_back(foo);
        }
        matrix.push_back(temp);
    }
    for (int i = 0; i < m; i++) {
        // cout << "No Segmentation Fault Yet. i = " << i << endl;
        for (int j = n-1; j >= 0; j--) {
            // cout << "No Segmentation Fault Yet. j = " << j << endl;
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}