#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string addstring(string a, string b) {
    if (a.size() < b.size()) {
        swap(a, b);
    }
    int j = a.size()-1;
    for(int i = b.size()-1; i>=0; i--, j--) {
        a[j]+=(b[i]-'0');
    }
    for (int i = a.size()-1; i>0; i--) {
        if (a[i] > '9') {
            int d = a[i]-'0';
            a[i-1] = ((a[i-1]-'0') + d/10) + '0';
            a[i] = (d%10)+'0';
        }
    }
    if (a[0] > '9') {
        string k;
        k+=a[0];
        a[0] = ((a[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        a = k+a;
    }
    return a;
}

bool digitchecker(string s, vector<int> digits) {
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < digits.size(); j++) {
            if (s[i]-'0' == digits[j]) {
                break;
            } else if (j == digits.size()-1) {
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    string n;
    int m;
    cin >> n >> m;
    vector<int> digits;
    for (int i = 0; i < m; i++) {
        int digit;
        cin >> digit;
        digits.push_back(digit);
    }
    string current = n;
    while (!digitchecker(current, digits)) {
        current = addstring(current, n);
    }
    cout << current << endl;
    queue<string> notebook;
    
}