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

// int i = 0;
struct item {
    int totalweight, totalvalue;
    // item (int weight, int value, int quantity) {this->weight = weight;this->value = value;this->quantity = quantity;this->index = ++i;}
};

struct infinitevector {
    vector<infinitevector> thevectorisinfinite;
};

int main(void) {
    int n, maxweight;
    cin >> n >> maxweight;
    item items[n+1];
    for (int i = 1; i <= n; ++i) {
        int weight, value, quantity;
        cin >> weight >> value >> quantity;
        items[i].totalweight = weight * quantity;
        items[i].totalvalue = value * quantity;
    }
    int dp[n + 1][maxweight + 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= maxweight; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int max_index = 1; max_index <= n; ++max_index) {
        for (int capacity = 1; capacity <= maxweight; ++capacity) {
            // dp[max_index][capacity] = max(dp[max_index - 1][capacity], dp[max_index-1][capacity - items[max_index].totalweight] + items[max_index].totalvalue);
            if (capacity - items[max_index].totalweight >= 0) {
                dp[max_index][capacity] = max(dp[max_index - 1][capacity], dp[max_index-1][capacity - items[max_index].totalweight] + items[max_index].totalvalue);
            } else {
                dp[max_index][capacity] = dp[max_index - 1][capacity];
            }
        }
    }
    cout << dp[n][maxweight] << '\n';
    vector<int> selected;
    int capacity = maxweight;
    for (int item_index = n; item_index >= 1; --item_index) {
        if (dp[item_index][capacity] != dp[item_index - 1][capacity]) {
            selected.push_back(item_index);
            capacity -= items[item_index].totalweight;
        }
    }
    int selected_size = selected.size();
    for (int i = 0; i < selected_size; ++i) {
        cout << selected[selected_size-i-1] << ' ';
    }
    cout << '\n';
}