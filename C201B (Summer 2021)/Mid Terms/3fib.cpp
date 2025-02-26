#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    vector<int> fib;
    int N;
    cin >> N;
    for (int i = 0; i < 3; i++) {
        fib.push_back(1);
    }
    for (int i = 1; i < N; i++) {
        fib.push_back(fib[0]+fib[1]+fib[2]);
        fib.erase(fib.begin());
    }
    cout << fib[0] << endl;
}