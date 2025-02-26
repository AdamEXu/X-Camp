#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define LL long long
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int a = 0, b = 1, c = 1;
    for (int i = 3; i < n; i++){
        int temp = a;
        a = c + 2*b + temp;
        c = b;
        b = temp;
    }
    cout << a << endl;
}