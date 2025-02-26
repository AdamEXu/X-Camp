#include <iostream>
#include <vector>
#include <string>
using namespace std;

void print_vector(vector <int> myin) {
    for (int i = 0; i < myin.size(); i++) {
        cout << myin[i];
        if (i != myin.size()-1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int sum_all(vector <int> myin) {
    int result = 0;
    for (int i = 0; i < myin.size(); i++) {
        result += myin[i];
        result = result % 1000000007;
    }
    return result;
}

int climbing_stairs(int n, int k) {
    if (n <= 1) {
        return 1;
    }
    
    vector <int> result;
    for (int i = 0; i < 2; i++) {
        result.push_back(1);
    }

    for (int i = 2; i <= n; i++) {
        result.push_back(sum_all(result));
        if (result.size() > k) {
            result.erase(result.begin());
        }
    }

    int mySize = result.size();
    int rvalue = result[mySize-1];
    return rvalue;
}

int main(void) {
    int k, n;
    cin >> n >> k;
    cout << climbing_stairs(n, k) << endl;
}