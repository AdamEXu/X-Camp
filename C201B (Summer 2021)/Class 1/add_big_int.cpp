#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    // Get 2 strings as input
    string s1, s2;
    cin >> s1 >> s2;
    int len1=s1.size();
    int len2=s2.size();

    // Define the vectors
    vector <int> a;
    vector <int> b;
    vector <int> c;

    // Convert the strings to integer vectors
    for (int i = 0; i < len1; i++) {
        // a[len1-i-1] = s1[i]-'0';
        a.insert(a.begin(), s1[i]-'0');
    }
    for (int i = 0; i < len2; i++) {
        // b[len2-i-1] = s2[i]-'0';
        b.insert(b.begin(), s2[i]-'0');
    }

    // cout << "Done" << endl;

    // Add the two vectors (a and b) together
    int len3 = max(len1, len2)+1;
    for (int i = 0; i < len3-1; i++) {
        c.push_back(0);
        c[i] += a[i] + b[i];
        if (c[i] >= 10) {
            c[i+1]+=1;
            c[i] -=10;
        }
    }

    // Print result to the console
    int k = len3-1;
    while(c[k--] == 0 && len3 != 1) {
        len3--;
    }
    for (int i = len3-1; i >= 0; i--) {
        cout << c[i];
    }
    cout << endl;
}