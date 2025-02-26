#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

map<string, vector<string> > adj;
string cows[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

int main(void) {
    int n;
    string name1, name2, temp;
    set<string> lead_cows;
    map<string, bool> visited;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name1 >> temp >> temp >> temp >> temp >> name2;
        adj[name1].push_back(name2);
        adj[name2].push_back(name1);
    }

    for (int i = 0; i < 8; i++) {
        if (adj[cows[i]].size() != 2) {
            lead_cows.insert(cows[i]);
        }
    }

    for (auto x : lead_cows) {
        if (visited[x]) {
            continue;
        }
        visited[x] = true;
        cout << x << endl;
        if (adj[x].size() == 0) {
            continue;
        }
        string y = adj[x][0];
        while (true) {
            visited[y] = true;
            cout << y << endl;
            if (adj[y].size() > 1) {
                y = (visited[adj[y][0]]) ? adj[y][1] : adj[y][0];
            } else {
                break;
            }
        }
    }
}