#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

long long sumvector(vector<long long> v) {
    long long size = 0;
    for (int i = 0; i < v.size(); i++) {
        size+=v[i];
    }
    return size;
}

int main(void) {
    long long n, k;
    cin >> n >> k;
    vector<long long> prevs;
    prevs.push_back(1);
    prevs.push_back(2);
    if (n<=2) {
        cout << n << endl;
        return 0;
    }
    for (int i = 3; i <= k; i++) {
        prevs.push_back((sumvector(prevs)+1)%1000000007);
    }
    for (int i = k+1; i <= n; i++) {
        prevs.push_back((sumvector(prevs))%1000000007);
        prevs.erase(prevs.begin());
    }
    cout << prevs[prevs.size()-1] % 1000000007 << endl;
}