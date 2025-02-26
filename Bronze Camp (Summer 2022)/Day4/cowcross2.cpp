#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    // freopen("circlecross.in", "r", stdin);
    // freopen("circlecross.out", "w", stdout);
    string s;
    cin >> s;
    int p = 0;
    for (int i = 0; i < 52; i++) {
        int otherlettercount[26] = {0};
        for (int j = i; j < 52; j++) {
            if (s[i] == s[j]) {
                for (int k = 0; k < 26; k++) {
                    if (otherlettercount[k] == 1) {
                        p++;
                    }
                }
            } else {
                otherlettercount[s[j]-'A']++;
            }
        }
    }
    cout << p/2 << endl;
}