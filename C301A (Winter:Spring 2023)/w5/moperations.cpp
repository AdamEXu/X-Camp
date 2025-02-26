#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <iomanip>
#include <climits>
// #include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(void) {
    /*****************
     * USACO Bronze Problem 3. Moo Operations
     * Code written by Adam Xu
    *****************/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string phrases[n];
    for (int i = 0; i < n; ++i) {
        cin >> phrases[i];
    }
    for (int i = 0; i < n; ++i) {
        // use bfs to do the following operations to the current phrase:
            // remove the first character
            // remove the last character
            // swap the first character (if the first character is 'M' then swap it with 'O' and vice versa)
            // swap the last character (if the last character is 'M' then swap it with 'O' and vice versa)
        // if the current phrase is "MOO" then print the number of operations it took to get there
        // if cannot get to "MOO" then print -1

        if (phrases[i] == "MOO") {
            cout << 0 << '\n';
            continue;
        }

        queue<string> q;
        q.push(phrases[i]);
        // set<string> visited;
        map<string, int> visited;
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            if (s == "MOO") {
                cout << visited[s] << '\n';
                break;
            }

            if (s.length() > 3) {
                // remove first character
                if (visited[s.substr(1, s.length()-1)] == 0) {
                    q.push(s.substr(1, s.length()-1));
                    visited[s.substr(1, s.length()-1)] = visited[s] + 1;
                }
                // remove last character
                if (visited[s.substr(0, s.length()-1)] == 0) {
                    q.push(s.substr(0, s.length()-1));
                    visited[s.substr(0, s.length()-1)] = visited[s] + 1;
                }
            }

            // swap first character
            if (s[0] == 'O') {
                if (visited["M" + s.substr(1, s.length()-1)] == 0) {
                    q.push("M" + s.substr(1, s.length()-1));
                    visited["M" + s.substr(1, s.length()-1)] = visited[s] + 1;
                }
            }
            // swap last character
            if (s[s.length()-1] == 'M') {
                if (visited[s.substr(0, s.length()-1) + "O"] == 0) {
                    q.push(s.substr(0, s.length()-1) + "O");
                    visited[s.substr(0, s.length()-1) + "O"] = visited[s] + 1;
                }
            }
        }

        // if it is not possible to get to "MOO"
        if (q.empty() && visited["MOO"] == 0) {
            cout << -1 << '\n';
        }
    }
}