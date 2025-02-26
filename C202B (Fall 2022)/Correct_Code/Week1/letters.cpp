#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > maze;
vector<bool> letters;
int ans = 0;
int n=0,m=0;
int dirx[4] = {0, 0, 1, -1}, diry[4] = {1, -1, 0, 0};
 
bool isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        // cout << x << ", " << y << endl;
        return false;
    } else if (letters[maze[x][y]] == true) {
        // cout << x << " ," << y << endl;
        return false;
    }
    // cout << x << "," << y << endl;
    return true;
}
 
int dfs(int x, int y, int d) {
    // cout << x << ", " << y << endl;
    letters[maze[x][y]] = true;
    int result = 1;
    ans = max(ans, d);
    for (int i = 0; i < 4; i++) {
        int newx = x+dirx[i], newy = y+diry[i];
        if (isvalid(newx, newy)) {
            result = max(dfs(newx, newy, d+1), result)+1;
            // cout << result << endl;
        }
    }
    // cout << x << " ," << y << endl;
    letters[maze[x][y]] = false;
    return result;
}
 
int main(void) {
    for (int i = 0; i < 26; i++) {
        letters.push_back(false);
    }
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> templetters;
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            templetters.push_back(int(c-'A'));
        }
        maze.push_back(templetters);
    }
    dfs(0, 0, 0);
    cout << ans+1 << endl;
}