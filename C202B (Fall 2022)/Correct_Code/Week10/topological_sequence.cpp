#include <iostream>
#include <vector>
#include <set>
using namespace std;
void topseq(vector<vector<int> >& arr) {
    vector<int> dep(arr.size(), 0);
    set<int> myset;
    vector<int> result;
    int size = arr.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            dep[j] += arr[i][j];
        }
    }
    for (int i = 0; i < size; i++) {
        if (dep[i] == 0) {
            myset.insert(i);
        }
    }
 
    while (!myset.empty()) {
        int current = *myset.begin();
        myset.erase(myset.begin());
        result.push_back(current);
        size = arr[current].size();
        for (int i = 0; i < size; i++) {
            if (arr[current][i] == 0) {
                continue;
            }
            dep[i] -= arr[current][i];
            if (dep[i] == 0) {
                myset.insert(i);
            }
        }
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i]+1 << " ";
    }
    cout << endl;
}
 
int main(void) {
    int n, m, a, b;
 
    cin >> n >> m;
    vector<vector<int> > arr(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a-1][b-1] = 1;
    }
    topseq(arr);
}