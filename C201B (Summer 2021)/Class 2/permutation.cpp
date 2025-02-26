// C++ program to display all permutations
// of an array using STL in C++

// #include <bits/stdc++.h>
#include <iostream>
#include<algorithm>
using namespace std;

// Function to display the array
void display(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void find_all_sets(int max, int total, int n[], int *sets, int current) {
    sets[current] = n[current];
    current++;
    max--;
    if ((current == max) || (max == 0)) {
        return;
    }
    find_all_sets(max, total, n, &sets[0], current);
}

// Function to find the permutations
void findPermutations(int a[], int n)
{

	// Sort the given array
	std::sort(a, a + n);

	// Find all possible permutations
	// cout << "Possible permutations are:\n";
	do {
		display(a, n);
	} while (next_permutation(a, a + n));
}

// Driver code
int main()
{
	int myInput, myArray[100];
	
	cin >> myInput;

	for(int i=0; i < myInput; i++) {
		myArray[i] = i+1;
	}

	findPermutations(myArray, myInput);

	return 0;
}

for (i=0; i<N; i++) {
	for (j=0; j<N;j++) {
		for (k=0; k<N; k++) {
			print (i+1, j+1, k+1);
		}
	}
}
