#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
 
// `M × N` matrix
#define M 15
#define N 15

int input(istream& in=cin) {
    int x;
    in >> x;
    return x;
}

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

// Check if it is possible to go to `(x, y)` from the current position. The
// function returns false if the cell has value 1 or already visited
bool isSafe(int mat[M][N], int visited[M][N], int x, int y)
{
    if (mat[x][y] == 1 || visited[x][y]) {
        return false;
    }
 
    return true;
}
 
// Returns false if not a valid position
bool isValid(int x, int y)
{
    if (x < M && y < N && x >= 0 && y >= 0) {
        return true;
    }
 
    return false;
}
 
// Find the shortest possible route in a matrix `mat` from source cell `(0, 0)`
// to destination cell `(x, y)`.
 
// `min_dist` is passed by reference and stores the length of the longest path
// from source to a destination found so far, and `dist` maintains the length
// of the path from a source cell to a current cell `(i, j)`.
 
void findShortestPath(int mat[M][N], int visited[M][N], int i, int j,
                int x, int y, int &min_dist, int dist)
{
    // if the destination is found, update `min_dist`
    if (i == x && j == y)
    {
        min_dist = min(dist, min_dist);
        return;
    }
    // set `(i, j)` cell as visited
    visited[i][j] = 1;

    // go to the bottom cell
    if (isValid(i + 1, j) && isSafe(mat, visited, i + 1, j)) {
        findShortestPath(mat, visited, i + 1, j, x, y, min_dist, dist + 1);
    }
 
    // go to the right cell
    if (isValid(i, j + 1) && isSafe(mat, visited, i, j + 1)) {
        findShortestPath(mat, visited, i, j + 1, x, y, min_dist, dist + 1);
    }
 
    // go to the top cell
    if (isValid(i - 1, j) && isSafe(mat, visited, i - 1, j)) {
        findShortestPath(mat, visited, i - 1, j, x, y, min_dist, dist + 1);
    }
 
    // go to the left cell
    if (isValid(i, j - 1) && isSafe(mat, visited, i, j - 1)) {
        findShortestPath(mat, visited, i, j - 1, x, y, min_dist, dist + 1);
    }
 
    // backtrack: remove `(i, j)` from the visited matrix
    dist--;
    visited[i][j] = 0;
}
 
int main()
{
    int n, temp;
	cin >> n;
	int mat[N][M];
    for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			mat[i][j] = 1;
		}
	}
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp = input();
			mat[i][j] = temp;
		}
	}

    // for (int i = 0; i < N; i++) {
    //     array_printer(mat[i]);
    // }
    
 
    // construct a matrix to keep track of visited cells
    int visited[M][N];
 
    // initially, all cells are unvisited
    memset(visited, 0, sizeof visited);
 
    int min_dist = INT_MAX;
    findShortestPath(mat, visited, 0, 0, n-1, n-1, min_dist, 0);
 
    if (min_dist != INT_MAX)
    {
        cout << min_dist + 1<< endl;
    }
    else {
        cout << "Destination can't be reached from a given source" << endl;
    }

    return 0;
}
