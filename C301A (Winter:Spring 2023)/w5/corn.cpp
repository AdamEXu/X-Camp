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

static int mine(int a, int b, int c, int d) {
    return min(min(a, b), min(c, d));
}

static int maxe(int a, int b, int c, int d) {
    return max(max(a, b), max(c, d));
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> nums;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    // find the best way to split the array into 4 parts such that the difference of the sum of the maximum and minimum of each part is minimized
    // print out the minimum difference
    int mini = INT_MAX;
    for (int i = 0; i < N-3; ++i) {
        for (int j = i+1; j < N-2; ++j) {
            for (int k = j+1; k < N-1; ++k) {
                int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
                for (int l = 0; l <= i; ++l) sum1+=nums[l];
                for (int l = i+1; l <= j; ++l) sum2+=nums[l];
                for (int l = j+1; l <= k; ++l) sum3+=nums[l];
                for (int l = k+1; l < N; ++l) sum4+=nums[l];
                int difference = maxe(sum1, sum2, sum3, sum4) - mine(sum1, sum2, sum3, sum4);
                if (difference < mini) mini = difference;
            }
        }
    }
    cout << mini << '\n';
}