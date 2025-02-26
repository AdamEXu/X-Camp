#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void convert_int_to_vector(int n) {
    stack<int> temp;
    temp.push(n);
    while (n > 0) {
        int digit = n % 10;
        n /= 10;
        temp.push(digit);
        cout << temp.top();
    }
    cout << endl;
}

// void print_vector(vector<int> n) {
//     for (int i = 0; i < n.size(); i++) {
//         cout << n[i] << " ";
//     }
//     cout << endl;
// }

int main(void) {
    int n;
    cin >> n;
    convert_int_to_vector(n);
}