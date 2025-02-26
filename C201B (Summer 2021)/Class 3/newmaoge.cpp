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
    vector<int> bricks, dp;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        bricks.insert(bricks.end(), temp);
    }
    sort(bricks.begin(), bricks.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        dp.push_back(1);
        for (int j = 0; j < i; j++) {
            if (bricks[i] - bricks[j] >= d) {
                dp[i]+=dp[j];
                dp[i]%=1000000007;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans+=dp[i];
        ans%=1000000007;
    }
    cout << ans%1000000007 << endl;
    return 0;
}