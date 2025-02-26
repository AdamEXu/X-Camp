#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <climits>
#include <iomanip>
// #include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
    vector<pair<long long, long long> > patches(m);
	for (int i = 0; i < m; ++i) {
		cin >> patches[i].first >> patches[i].second;
	}
	sort(patches.begin(), patches.end());

	long long l = 0;
	long long r = patches[m - 1].second - patches[0].first + 1;
	while (l < r) {
		long long mid = l + (r - l + 1) / 2; 
        long long count = 1, temp = 0, current = patches[0].first;
		while ((current + mid) < patches[m - 1].second) {
			while (current+mid > patches[temp].second) {
				++temp;
			}
			current = max(patches[temp].first, current + mid);
			++count;
			if (count == n) break;
		}

		if (count >= n) l = mid;
		else r = mid-1;
	}
	cout << l << '\n';
}