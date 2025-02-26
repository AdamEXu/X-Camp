#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'z') {
            s[i] = 'a';
        } else if (s[i] == ' ') {
            continue;
        } else {
            s[i]++;
        }
    }
    cout << s << endl;
}