#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    std::queue<int> test;
    test.push(1);
    test.push(2);
    test.push(3);
    if (test.empty()) {
        cout << "It is empty." << endl;
    }
    cout << test.size() << endl;
}