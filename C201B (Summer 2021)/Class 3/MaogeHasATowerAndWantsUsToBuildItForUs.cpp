#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void vecout(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size()-1) {
            cout << ", ";
        } else {
            cout << endl;
        }
    }
}

int main(void) {
    int n, d;
    cin >> n >> d;
    vector<int> bricks;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        bricks.insert(bricks.end(), temp);
    }
    sort(bricks.begin(), bricks.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        temp = vector<int>(bricks.begin() + i + 1, bricks.end());
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] - bricks[i] >= d) {
                ans++;
                ans%=1000000007;
            }
        }
    }
    cout << ans << endl;
    return 0;
}