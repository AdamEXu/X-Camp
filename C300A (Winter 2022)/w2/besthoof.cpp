#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> hoof (n+1);
    vector<int> paper (n+1);
    vector<int> scissors (n+1);
	for (int i = 1; i <= n; ++i) {
		hoof[i] += hoof[i-1];
		paper[i] += paper[i-1];
		scissors[i] += scissors[i-1];
		char temp;
		cin >> temp;
		if (temp == 'H') {
			++paper[i];
		} else if (temp == 'P') {
			++scissors[i];
		} else if (temp == 'S') {
			++scissors[i];
		}
	}
	int maxnum = 0;
	for (int i = 1; i <= n; ++i) {
		int prev = max(hoof[i], max(paper[i], scissors[i]));
		int current = max({hoof[n] - hoof[i], paper[n] - paper[i], scissors[n] - scissors[i]});
		maxnum = max(maxnum, prev + current);
	}
	cout << maxnum << '\n';
}