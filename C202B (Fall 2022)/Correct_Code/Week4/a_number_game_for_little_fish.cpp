#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    stack<int> numbers;
    while (n != 0) {
        numbers.push(n);
        cin >> n;
    }
    while (!numbers.empty()) {
        cout << numbers.top() << " ";
        numbers.pop();
    }
}