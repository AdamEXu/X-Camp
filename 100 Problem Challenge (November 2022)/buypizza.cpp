#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    cout << "How many pizzas do you want?";
    int n;
    cin >> n;
    cout << "You need to pay " << n*50 << " yuan, thank you.";
}