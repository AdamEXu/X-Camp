#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define True 0
#define False 1

bool beenthere[100][100];
int counter = 0;

int floodfill(int maze[1000][1000], int current_loc_x, int current_loc_y) {
    if (!beenthere[current_loc_x][current_loc_y]) {
        // up
        if (maze[current_loc_x-1][current_loc_y] == 0) {
            maze[current_loc_x-1][current_loc_y] = 2;
            counter++;
            beenthere[current_loc_x-1][current_loc_y] = True;
            floodfill(maze, current_loc_x-1, current_loc_y);
        }
        // down
        if (maze[current_loc_x+1][current_loc_y] == 0) {
            maze[current_loc_x+1][current_loc_y] = 2;
            counter++;
            beenthere[current_loc_x+1][current_loc_y] = True;
            floodfill(maze, current_loc_x+1, current_loc_y);
        }
        // top-left
        if (maze[current_loc_x-1][current_loc_y-1] == 0) {
            maze[current_loc_x-1][current_loc_y-1] = 2;
            counter++;
            beenthere[current_loc_x-1][current_loc_y-1] = True;
            floodfill(maze, current_loc_x-1, current_loc_y-1);
        }
        // bottom-right
        if (maze[current_loc_x+1][current_loc_y+1] == 0) {
            maze[current_loc_x+1][current_loc_y+1] = 2;
            counter++;
            beenthere[current_loc_x+1][current_loc_y+1] = True;
            floodfill(maze, current_loc_x+1, current_loc_y+1);
        }
    }
}

int main(void) {
    int n, maze[1000][1000], startx, starty;
    cin >> n >> startx >> starty;
    for (int i = 0; i < n; i++) {
        char *temp;
        cin >> temp;
        char* splitStr = strtok(temp, " ");
        for (int j = 0; j < strlen(temp); j++) {
            maze[i][j] = int(splitStr[j]);
        }
    }
    floodfill(maze, startx, starty);
}