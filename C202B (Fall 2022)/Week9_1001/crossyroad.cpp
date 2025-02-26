#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    map<int, vector<int> > mymap;
    for (int i = 0; i < n; i++) {
        int arrive, time;
        cin >> arrive >> time;
        if (mymap.count(arrive) == 0) {
            vector<int> tmp;
            tmp.push_back(time);
            mymap[arrive] = tmp;
        } else {
            mymap[arrive].push_back(time);
        }
    }
    int total = 0;
    for (auto it = mymap.begin(); it != mymap.end(); it++) {
        if (it->first >= total) {
            total = it->first;
        }
        for (int i = 0; i < it->second.size(); i++) {
            total += it->second[i];
        }
    }
    cout << total << endl;
}