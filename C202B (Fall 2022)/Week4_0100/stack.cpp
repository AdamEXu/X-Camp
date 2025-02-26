#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> mystack;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '-') {
            mystack.erase(mystack.begin());
        } else if (c == '+') {
            int temp;
            cin >> temp;
            mystack.insert(mystack.begin(), temp);
        }
    }
    for (int i = 0; i < mystack.size(); i++) {
        cout << mystack[i] << " ";
    }
}