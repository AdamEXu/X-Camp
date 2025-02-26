#include <iostream>
using namespace std;

int main(void) {
    int myArray[5][5];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> myArray[i][j];
        }
    }
}