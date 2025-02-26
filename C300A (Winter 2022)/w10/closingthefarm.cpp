#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<pair<int, int> > paths;
    int a, b;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        paths.push_back(make_pair(a, b));
    }
    vector<pair<int, int> > tofrom;
    vector<char> preferedmilk;
    char tmp;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> tmp;
        tofrom.push_back(make_pair(a, b));
        preferedmilk.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        pair<int, int> dest = tofrom[i];
        char milk = preferedmilk[i];
        // find path between dest.first and dest.second
        for (int j = 0; j < n-1; j++) {
            pair<int, int> path = paths[j];
            if (path.first == dest.first && path.second == dest.second) {
                // found path
                // check if milk is in path
                int start = path.first;
                int end = path.second;
                for (int k = start; k <= end; k++) {
                    if (s[k] == milk) {
                        cout << "1";
                        break;
                    }
                }
            }
        }
    }
}