#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string s;
    cin >> s;
    int a=0,b=0,c=0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            a++;
        } else if (s[i] == ')') {
            a--;
        } else if (s[i] == '[') {
            b++;
        } else if (s[i] == ']') {
            b--;
        } else if (s[i] == '{') {
            c++;
        } else if (s[i] == '}') {
            c--;
        }
    }
    if (a == 0 && b == 0 && c == 0) {
        cout << "OK" << endl;
    } else {
        cout << "Wrong" << endl;
    }
}