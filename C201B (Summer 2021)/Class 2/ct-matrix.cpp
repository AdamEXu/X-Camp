#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> count(vector<vector <int> > vec, int n, int m) {
    vector<int> counts;
    for (int i = 0; i < m; i++) {
        counts.push_back(0);
        for (int j = 0; j < n; j++) {
            if (vec[j][i] == 1) {
                counts[i]+=1;
            }
        }
    }
    return counts;
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
    vector<int> counts = count(matrix, n, m);
    for (int i = 0; i < m; i++) {
        cout << counts[i] << endl;
    }
}