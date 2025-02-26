#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;

int main(void) {
    set<int> a;
    set<int> b;
    int lena, lenb;
    cin >> lena >> lenb;
    for (int i = 0; i < lena; i++) {
        int num;
        scanf("%d", &num);
        a.insert(num);
    }
    for (int i = 0; i < lenb; i++) {
        int num;
        scanf("%d", &num);
        b.insert(num);
    }
    bool asubb = true, bsuba = true, same = true;
    if (a.size() == b.size()) {
        for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
            if (b.count(*it) == 0) {
                same = false;
                break;
            }
        }
    } else {
        same = false;
    }
    for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
        if (b.count(*it) == 0) {
            asubb = false;
            continue;
        }
    }
    for (set<int>::iterator it = b.begin(); it != b.end(); it++) {
        if (a.count(*it) == 0) {
            bsuba = false;
            continue;
        }
    }
    bool disjoint = false;
    if (a.size() > b.size()) {
        for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
            if (b.count(*it) == 1) {
                disjoint = true;
                break;
            }
        }
    } else {
        for (set<int>::iterator it = b.begin(); it != b.end(); it++) {
            if (a.count(*it) == 1) {
                disjoint = true;
                break;
            }
        }
    }
    if (same) {
        cout << "A equals B" << endl;
    } else if (asubb) {
        cout << "A is a proper subset of B" << endl;
    } else if (bsuba) {
        cout << "B is a proper subset of A" << endl;
    } else if (!disjoint) {
        cout << "A and B are disjoint" << endl;
    } else {
        cout << "I'm confused!" << endl;
    }
}