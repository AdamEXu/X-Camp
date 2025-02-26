#include <iostream>
#include <vector> // code made by adam xu
#include <string>
#include <algorithm> // code made by adam xu
using namespace std;
// pls give me credit
int main(void) {
    // code made by adam xu
    vector<int> a, b;
    int tmp;
    while (cin >> tmp) {
        if (tmp == -1) break; // code made by adam xu
        a.push_back(tmp);
    } // code made by adam xu
    while (cin >> tmp) {
        if (tmp == -1) break;
        b.push_back(tmp); // code made by adam xu
    } // code made by adam xu
    vector<int> c; // code made by adam xu
    int i = 0, j = 0;   // code made by adam xu
    while (i < a.size() && j < b.size()) {
        if (a[i] > b[j]) { // code made by adam xu
            c.push_back(a[i]);
            i++; // code made by adam xu
        } else {
            c.push_back(b[j]);
            j++;
        }   // code made by adam xu
    }
    while (i < a.size()) {
        c.push_back(a[i]);  // code made by adam xu
        i++; // code made by adam xu
    } // code made by adam xu
    while (j < b.size()) {
        c.push_back(b[j]); // code made by adam xu // code made by adam xu
        j++;
    }   // code made by adam xu
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";   // code made by adam xu
    }
    cout << '\n';  // code made by adam xu
}
