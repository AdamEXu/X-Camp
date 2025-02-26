#include <iostream>
using namespace std;

void find_all_step_length(int max, int *n) { // Find all step length from max
    for (int i = 0; i < max; i++) {
        n[i] = i+1;
    }
}

void find_all_sets(int max, int total, int n[], int *sets, int current) {
    sets[current] = n[current];
    current++;
    max--;
    if ((current == max) || (max == 0)) {
        return;
    }
    find_all_sets(max, total, n, &sets[0], current);
}

int main(void) {
    int distance, max_step_len, result, n[1000];
    /*Input*/ cin >> distance; 
    cin >> max_step_len;
    /*Error check*/ if (max_step_len > distance) { return 1; } else if (distance == 0) { return -1; }
    find_all_step_length(max_step_len, &n[0]);
    for (int i = 0; i < max_step_len; i++) {
        cout << n[i];
        if (n[i+1] != n[i]+1) {
            break;
        }
        else {
            cout << ", ";
        }
    }
    cout << endl;
    int sets[1000];
    find_all_sets(max_step_len, distance, n, &sets[0], 0);
    for (int i = 0; i < max_step_len; i++) {
        cout << n[i];
        if (sets[i+1] != sets[i]+1) {
            break;
        }
        else {
            cout << ", ";
        }
    }
    cout << endl;
}