// A C++ program to implement flood fill algorithm
#include<iostream>
#include<string.h>
#include<string>
#include <vector>
using namespace std;

// Dimentions of paint screen
#define N 20
#define M 20

int counter = 0;

char input(istream& in=cin) {
    char x;
    in >> x;
    return x;
}

// Prints a vector. Simple.
void print_vector(vector <int> myin) {
    for (int i = 0; i < myin.size()-1; i++) {
        cout << myin[i] << endl;
    }
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

	// Recur for up, down, left and right
	floodFillUtil(screen, x-1, y, prevC, newC);

	floodFillUtil(screen, x+1, y, prevC, newC);

	floodFillUtil(screen, x, y-1, prevC, newC);

	floodFillUtil(screen, x, y+1, prevC, newC);

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
    vector <int> output;
	int startx=0, starty=0, len1=255, len2=255;
	int screen[N][M];
    while (len1 != 0 && len2 != 0) {
        char temp;
        cin >> len1 >> len2;
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                screen[i][j] = 1;
            }
        }
        for (int i = 0; i < len2; i++) {
            for (int j = 0; j < len1; j++) {
                temp = input();
                if (temp == '.') {
                    temp = '0';
                } else if (temp == '#') {
                    temp = '1';

                } else if (temp == '@') {
                    startx = i;
                    starty = j;
                    temp = '0';
                }
                screen[i][j] = int(temp)-'0';
            }
        }

        int newC = 3;
        floodFill(screen, startx, starty, newC);
	    output.push_back(counter);
        counter = 0;
    }
    print_vector(output);
}
