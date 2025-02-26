#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
// #include <bits/stdc++.h>
using namespace std;

vector<int> sums;
unordered_set<int> s;

void combinationUtil(int arr[], int data[], int start, int end, int index) {
	if (index != 0) {
        int sum = 0;
		for (int j = 0; j < index; ++j) sum += data[j];
        // cout << sum << endl;
        if (s.find(sum) == s.end()) {
            sums.push_back(sum);
            s.insert(sum);
        }
		// return;
	}
	for (int i = start; i <= end; ++i) {
		data[index] = arr[i];
		combinationUtil(arr, data, i+1, end, index+1);
	}
}

int main() {
    int m;
    cin >> m;
	int arr[m];
    for (int i = 0; i < m; ++i) cin >> arr[i];
	int n = sizeof(arr)/sizeof(arr[0]);
	int data[m];
	// combinationUtil(arr, data, 0, n-1, 0);
    queue<int[]> q;
    q.push(data);
    cout << sums.size() << endl;
    sort(sums.begin(), sums.end());
    for (int i = 0; i < sums.size(); ++i) cout << sums[i] << ' ';
    cout << endl;
}