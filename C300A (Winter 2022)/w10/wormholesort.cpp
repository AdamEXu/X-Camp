#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<pair<int, int> > paths;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        paths.push_back(make_pair(a, b));
    }
    vector<pair<int, int> > walkedpaths;
    vector<char> preferedmilk;
    char tmp;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> tmp;
    }
}