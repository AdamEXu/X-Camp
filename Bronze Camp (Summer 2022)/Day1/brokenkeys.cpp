#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string guess, original;
        cin >> guess >> original;
        int iter = 0, guessiter;
        bool possible = true;
        while (iter < guess.length()) {
            if (guess[iter] != original[iter]) {
                possible = false;
                break;
            }

        }
    }
}