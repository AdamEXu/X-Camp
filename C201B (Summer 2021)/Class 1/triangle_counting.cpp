#include <iostream>
using namespace std;

// Counts triangles facing up
unsigned long long count_up(unsigned long long n) {
	return (n*(n+1))/2;
}

// Counts triangles facing down
unsigned long long count_down(unsigned long long n) {
	int total = 0;
	for (int i = 1; i < n; i+=2) {
		total += (n-i);
	}

	return total;
}

// Counts total triangles; recusive algorithm
unsigned long long tri_count(unsigned long long n) {
	if (n == 1) {
		return 1;
	}
	unsigned long long result = tri_count(n-1) + count_up(n) + count_down(n);
	return result;
}

#include <iostream>
using namespace std;

int main(void) {
	unsigned long long n;
	cin >> n;
	if (n == 0) {
		return 0;
	}
	// cout << tri_count(n) << endl;
	cout << (n*(n+2)*(2*(n+1)-1))/8 << endl;
}