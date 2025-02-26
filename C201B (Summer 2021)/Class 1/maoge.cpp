#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <string>
#include <climits>
#define LL long long
// #include <bits/stdc++.h>
using namespace std;

long long count = 0;

void vecout(vector<long long> vec) {
    for (long long i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size()-1) {
            cout << ", ";
        } else {
            cout << endl;
        }
    }
}
 
long long input(istream& in=cin) {
    long long x;
    in >> x;
    return x;
}

bool find(vector<long long> vec, long long e) {
    for (long long i = 0; i < vec.size(); i++) {
        if (vec[i] == e) {
            return true;
        }
    }
    return false;
}

long long loop_function(vector<long long> blocks, vector<long long> used, long long n, long long d){
    long long count = 0;
    if (used.size() >= n) {
        count+=1;
    }
    for(long long i = 0; i < n; i++){
        cout << i << endl;
        if (!find(used, blocks[i])) {
            used.insert(used.end(), blocks[i]);
            vecout(used);
            if (used[used.size()-2] > blocks[i] >= d) {
                count += loop_function(blocks, used, n, d);
                cout << "Found" << endl;
            }
            used.erase(prev(used.end()));
        }
    }
    return count;
}

int main(void) {
    long long n, d;
    cin >> n >> d;
    vector<long long> bricks;
    for (long long i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        bricks.insert(bricks.end(), temp);
    }
    sort(bricks.begin(), bricks.end());
    bricks.insert(bricks.end(), INT_MIN);

    vector<long long> temp;
    for (long long i = 0; i < n-1; i++)
        temp.insert(temp.begin(), INT_MAX);
    cout << loop_function(bricks, temp, n, d) << endl;
}