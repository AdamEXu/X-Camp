#include <iostream>
#include <queue>
using namespace std;

bool check2equal(int a, int b, int c) {
    if ((a == b && c == 0) || (a == c && b == 0) || (b == c && a == 0)) {
        return true;
    }
    return false;
}

int theother2[2] = {0, 0};

void getother2(int a) {
    if (a == 0) {
        theother2[0] = 1;
        theother2[1] = 2;
    } else if (a == 1) {
        theother2[0] = 0;
        theother2[1] = 2;
    } else {
        theother2[0] = 0;
        theother2[1] = 1;
    }
}

int main(void) {
    int cups[3] = {0};
    int max[3];
    cin >> max[0] >> max[1] >> max[2];
    cups[0] = max[0];
    queue<int> notebook;
    notebook.push(0);
    int counter = 0;
    while (!notebook.empty()) {
        int current = notebook.front();
        notebook.pop();
        for (int chossn = 0; chossn < 3; chossn++) {
            getother2(chossn);
            // cout << theother2[0] << " " << theother2[1] << endl;
            for (int i = 0; i < 2; i++) {
                counter++;
                int over = 0;
                over = (cups[current]+cups[theother2[i]])%max[theother2[i]];
                if (over == 0) {
                    cups[theother2[i]]+=cups[current];
                    cups[current] = 0;
                } else {
                    cups[theother2[i]] = max[theother2[i]];
                    cups[current] = over;
                }
                notebook.push(theother2[i]);
                if (check2equal(cups[0], cups[1], cups[2])) {
                cout << cups[0] << " "  << cups[1] << " " << cups[2] << endl;
                    return 0;
                }
            }
        }
    }
}