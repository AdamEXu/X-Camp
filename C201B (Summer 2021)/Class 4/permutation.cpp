#include <iostream>
#include <vector>
using namespace std;

void permutation(vector<int> current, vector<int> possibilities, int n){
    if (possibilities.size() == 0) {
        for (int i = 0; i < n; i++) {
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < possibilities.size(); i++) {
        vector<int> temp;
        temp = possibilities;
        vector<int>::iterator iter = temp.begin();
        for (int j = 0; j < i; j++) {
            iter = next(iter);
        }
        temp.erase(iter);
        current.push_back(possibilities[i]);
        permutation(current, temp, n);
        current.erase(prev(current.end()));
    }
}

int main(void) {
    int n;
    cin >> n;
    vector<int> temp, temp2;
    for (int i = 0; i < n; i++) {
        temp.push_back(i+1);
    }
    permutation(temp2,temp,n);
}