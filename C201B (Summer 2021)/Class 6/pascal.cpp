#include <iostream>
#include <vector>
using namespace std;

void vecout(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size()-1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}

int main(void) {
    int n;
    cin >> n;
    if (n > 0) {
        vector<vector<int> > triangle;
        vector<int> temp;
        triangle.push_back(temp);
        triangle[0].push_back(1);
        vecout(triangle[0]);
        for (int i = 1; i < n; i++) {
            triangle.push_back(temp);
            for (int j = 0; j < i; j++) {
                triangle[i].push_back(triangle[i-1][j]+triangle[i-1][j-1]);
            }
            triangle[i].push_back(triangle[i-1][triangle[i-1].size()-1]);
            vecout(triangle[i]);
        }
    }
}