#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void vecout(vector<vector <int> > vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j];
            if (j != vec.size()-1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }
}

int main(void) {
    vector<vector<int> > matrix;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            if (a < 0) {
                a = 0-a;
            }
            temp.insert(temp.end(), a);
        }
        matrix.insert(matrix.end(), temp);
    }
    vecout(matrix);
}