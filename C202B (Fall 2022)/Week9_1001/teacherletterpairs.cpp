#include <iostream>
#include <string>
using namespace std;
int char_counts[60];
bool ajacency_matrix[105][105];
int min_char = 58; // from 'A' to 'Z'
string ans;

void dfs(int i) {
    ans += (char)(i + 'A');
    for (int j = 0; j < 58; j++) {
        if (ajacency_matrix[i][j]) {
            ajacency_matrix[i][j] = ajacency_matrix[j][i] = 0;
            dfs(j);
            return;
        }
    }
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        int x = a - 'A';
        int y = b - 'A';
        ajacency_matrix[x][y] = ajacency_matrix[y][x] = 1;
        min_char = min(min_char, min(x, y));
        char_counts[x]++;
        char_counts[y]++;
    }
    // Number of odd chars
    // since we have n pairs and want n+1 length of string
    // num of odd must be 0 or 2
    int odd_count = 0;
    for (int i = 0; i < 58; i++) {
        if ((char_counts[i] % 2) != 0) {
            odd_count++;
            switch (odd_count) {
                case 1:
                    min_char = i;
                    break;
                case 2:
                    min_char = min(min_char, i);
                    break;
                default:
                    cout << "No Solution" << endl;
                    return 0;
            }
        }
    }

    if (odd_count == 0 || odd_count == 2) {
        dfs(min_char);
        cout << ans << endl;
    } else {
        cout << "No Solution" << endl;
    }
}