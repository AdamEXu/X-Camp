#include <iostream>
#include <vector>
using namespace std;

int input(istream& in=cin) {
    int x;
    in >> x;
    return x;
}

int main(void) {
    vector<vector<int> > matrix;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            temp.push_back(input());
        }
        matrix.push_back(temp);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}