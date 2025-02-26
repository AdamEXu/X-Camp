#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
// #include <bits/stdc++.h>
using namespace std;

int desired_sum, num_coins, temp;
vector<int> coins, memeorization;

int combinations(int current_val) {
    if (current_val == desired_sum) return 1;
    if (current_val > desired_sum) return 0;
    if (memeorization[current_val] != -1) return memeorization[current_val];
    int count = 0;
    for (int i = 0; i < num_coins; i++) {
        count += combinations(current_val + coins[i]);
        count %= 1000000007;
    }
    memeorization[current_val] = count;
    return count;
}

int main(void) {
    cin >> num_coins >> desired_sum;
    for (int i = 0; i < num_coins; i++) {
        cin >> temp;
        coins.push_back(temp);
    }
    memeorization.resize(desired_sum+1, -1);
    cout << combinations(0) << endl;
}