#include <iostream>
#include <string>
using namespace std;

void array_printer(int input[]) {
    for (int i = 0; i < INT_MAX; i++) {
        cout << input[i];
        if (input[i+1] == '\0') {
            cout << input[i] << endl;
            return;
        } else if (i != 0) {
            cout << ", ";
        }
    }
}

int input(istream& in=cin) {
    int x;
    in >> x;
    return x;
}

#define N 15
#define M 15

int main(void) {
    int n, temp;
	cin >> n;
	int mat[N][M];
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			mat[i][j] = 1;
		}
	}
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp = input();
			mat[i][j] = temp;
		}
	}
    for (int i = 0; i < N; i++) {
        array_printer(mat[i]);
    }
}