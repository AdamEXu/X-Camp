// A C++ program to implement flood fill algorithm
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

// Dimentions of paint screen
#define N 500
#define M 500

int counter = 0;

int input(istream& in=cin) {
    int x;
    in >> x;
    return x;
}

// A recursive function to replace previous color 'prevC' at '(x, y)'
// and all surrounding pixels of (x, y) with new color 'newC' and
void floodFillUtil(int screen[][N], int x, int y, int prevC, int newC)
{
	// Base cases
	if (x < 0 || x >= M || y < 0 || y >= N)
		return;
	if (screen[x][y] != prevC)
		return;
	if (screen[x][y] == newC)
		return;

	counter++;
	
	// Replace the color at (x, y)
	screen[x][y] = newC;

	// Recur for down, up, top-left and bottom-right
	floodFillUtil(screen, x+1, y, prevC, newC);

	floodFillUtil(screen, x-1, y, prevC, newC);

	floodFillUtil(screen, x-1, y-1, prevC, newC);

	floodFillUtil(screen, x+1, y+1, prevC, newC);

}

// It mainly finds the previous color on (x, y) and
// calls floodFillUtil()
void floodFill(int screen[][N], int x, int y, int newC)
{
	int prevC = screen[x][y];
	floodFillUtil(screen, x, y, prevC, newC);
}

// Driver code
int main()
{
	int n, temp, split[10], startx, starty;
	cin >> n >> startx >> starty;
	int screen[N][M];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			screen[i][j] = 1;
		}
	}
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			temp = input();
			screen[i][j] = temp;
		}
	}
	// int screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
	// 				{1, 1, 1, 1, 1, 1, 0, 0},
	// 				{1, 0, 0, 1, 1, 0, 1, 1},
	// 				{1, 2, 2, 2, 2, 0, 1, 0},
	// 				{1, 1, 1, 2, 2, 0, 1, 0},
	// 				{1, 1, 1, 2, 2, 2, 2, 0},
	// 				{1, 1, 1, 1, 1, 2, 1, 1},
	// 				{1, 1, 1, 1, 1, 2, 2, 1},
	// 				};
	// int screen[3][3] = {{0, 0, 0}, {0, 1, 0}, {1, 0, 1}};
	int x = 0, y = 0, newC = 3;
	floodFill(screen, x, y, newC);

	// cout << "Updated screen after call to floodFill: \n";
	// for (int i=0; i<M; i++)
	// {
	// 	for (int j=0; j<N; j++)
	// 	cout << screen[i][j] << " ";
	// 	cout << endl;
	// }

	cout << counter << endl;
}
