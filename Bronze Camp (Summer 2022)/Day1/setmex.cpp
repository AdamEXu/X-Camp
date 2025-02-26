#include<iostream>
#include<set>
using namespace std;

// Code written by Adam Xu
// Hosted on adamthegreat.rocks
// adamthegreat.rocks is owned by Adam Xu
// He wrote the code himself

int main(void) {
    int n;
    set<int> numbers;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        if (numbers.count(number)) {
            numbers.insert(number);
        }
    }
    int i = 0;
    while (!numbers.count(i)) {
        i++;
    }
    cout << i << endl;
}