#include <iostream>
using namespace std;

void hanoi(int start, int end, int num) {
    if (num == 1) {
        cout << "Move disk " << num << " from rod " << start << " to rod " << end << endl;
    } else {
        int other = 6 - (start+end);
        hanoi(num - 1, start, other);
        cout << "Move disk " << num << " from rod " << start << " to rod " << end << endl;
        hanoi(num - 1, other, end);
    }
}

void array_printer(int *input, int size) {
    for (int i = 0; i < size; i++) {
        if (i != 0) {
            cout << ", ";
        }
        cout << input[i];
    }
    cout << endl;
}

void make_sequence(int total, int* eject) {
    for (int i = 0; i < total; i++) {
        eject[i] = i+1;
    }
}

int main(void) {
    int total;
    cin >> total;
    hanoi(1, 3, total);
}