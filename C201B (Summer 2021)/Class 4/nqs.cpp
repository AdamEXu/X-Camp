#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int attempts = 0;
int solutions = 0;

// Prints a vector
void PrintVector(const vector <int>& v) {
    for (const int& i : v) {
        cout << setw(3) << i;
    }
    cout << endl;
}

bool IsLegal(const vector <int>& v) {
    attempts++;

    int value = v.back();

    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == value) {
            return false;
        }
    }

    int offset = 1;
    for (int i = v.size() - 2; i >= 0; i--) {
        if (value == v[i] + offset) {
            return false;
        }
        if (value == v[i] - offset) {
            return false;
        }
        offset++;
    }

    return true;
}

void NQueens(vector <int>& v, int leftToPlace, int totalToPlace) {
    if (leftToPlace == 0) {
        solutions++;
        PrintVector(v);
        return;
    }

    v.push_back(0);

    for (int i = 0; i < totalToPlace; i++) {
        v.back() = i;

        if (IsLegal(v)) {
            NQueens(v, leftToPlace - 1, totalToPlace);
        }
    }
    v.pop_back();
}

void NQueens(int n) {
    vector <int> v;
    v.reserve(n);
    NQueens(v, n, n);
}

int main(void) {
    int in;
    cin >> in;
    NQueens(in);

    cout << solutions << endl;
    // cout << "Number of checks:    " << attempts << endl;

    return 0;
}