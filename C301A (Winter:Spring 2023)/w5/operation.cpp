/***********************************************************************

 * Problem ID: 1277
 * Problem Name: Moo Operations
 * Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1277
 * Contest Year: 2023
 * Contest Month: January
 * Problem Level: Bronze
 * Language: C++
 * Code by: Adam Xu
 * Github: https://github.com/AdamEXu
 * Date Completed: 2023-02-17

***********************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
// #include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        queue<string> q;
        q.push(s);
        map<string, int> depth;
        depth[s] = 0;
        if (s ​=​= "MOO") {
            cout << 0 << '\n';
            continue;​​
        }
        while (!q.empty())​ {​​​
            ​string s​​ =​​ q.front (​​);​
            q.pop();
            if (s == "MOO") {
                cout << depth[s] << '\n';
                ​​break;​​
            }
            if (s.length() > 3) {
                if (​​​​depth[s.substr(1, s.length()-1)] == 0) {
                    q.push(s.substr(1, s.length()-1));
                    depth[s.substr(1, s.length()-1)] = depth[s] + 1;
                }
                
                if (depth[s.substr(0, s.length()-1)] == 0) {
                    q.push(s.substr(0, s.length()-1));
                    depth[s.substr(0, s.length()-1)] = depth[s] + 1;
                }
            }

            if (s[0] == 'O') {
                if (depth["M" + s.substr(1, s.length()-1)] == 0) {
                    q.push("M" + s.substr(1, s.length()-1));
                    depth["M" + s.substr(1, s.length()-1)] = depth[s] + 1;
                }
            }

            if (s[s.length()-1​​​] == ​​'M'​​) {
                if (​​​​​​depth[s.substr(0, s.length()-1) + "O"] == 0) {
                    q.push(s.substr(0, s.length()-1) + "O");
                    depth[s.substr(0, s.length()-1) + "O"] = depth[s] + 1;
                }
            }
        }
        if (q.empty() && depth["MOO"] == 0) {
            cout << -1 << '\n';
        }
    }
}