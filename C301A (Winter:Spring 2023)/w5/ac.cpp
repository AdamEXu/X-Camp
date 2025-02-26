/***********************************************************************

 * Problem ID: 1276
 * Problem Name: Air Cownditioning II
 * Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=1276
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

struct Cow { // Farmer John's cows
    int s, t, c;
    Cow(int startstall, int endstall, int requirecoolness) {
        this->s = startstall; // cow covers stalls from s to t
        this->t = endstall;
        this->c = requirecoolness; // cow requires at least c units of coolness to be comfortable
    }
};

struct AC { // Farmer John's air conditioners
    int a, b, p, m;
    AC(int startstall, int endstall, int coolness, int price) {
        this->a = startstall; // air conditioner cools stalls from a to b
        this->b = endstall;
        this->m = coolness; // air conditioner adds m units of coolness to each stall
        this->p = price; // air conditioner costs p dollars to run
    }
};

vector<Cow> cows; // list of N cows
vector<AC> acs; // list of M air conditioners
int n, m, mincost = INT_MAX; // mincost is the minimum cost to cool all the cows

// the checker function checks if the string s is a valid solution
// makes sure that all the cows are comfortable
void checker(string s) {
    int cost = 0; // inital cost is 0
    int coolness[100] = {0}; // inital coolness of each stall is 0
    for (int i = 0; i < s.length(); ++i) { // go through each air conditioner
        if (s[i] == '1') { // if it is on:
            cost += acs[i].p; // add the cost of running the air conditioner
            for (int j = acs[i].a; j <= acs[i].b; ++j) { // go through each stall that the air conditioner cools
                coolness[j] += acs[i].m; // and add the coolness of the air conditioner to the coolness of the stall
            }
        }
    }
    for (int i = 0; i < n; ++i) { // now go through each cow
        for (int j = cows[i].s; j <= cows[i].t; ++j) { // and go through each stall that the cow occupies
            if (coolness[j] < cows[i].c) { // if the coolness of the stall is less than the cow's requirement
                return; // then the cow is not comfortable, so this combination of air conditioners is not valid
            }
        }
    }
    // if the program reaches this point, then all the cows are comfortable
    mincost = min(mincost, cost); // so update the minimum cost if necessary
    return;
}

int main(void) {
    // input N (number of cows) and M (number of air conditioners)
    cin >> n >> m;
    // input the N cows
    for (int i = 0; i < n; ++i) {
        int s, t, c;
        cin >> s >> t >> c;
        cows.push_back(Cow(s, t, c));
    }
    // input the M air conditioners
    for (int i = 0; i < m; ++i) {
        int a, b, p, m;
        cin >> a >> b >> p >> m;
        acs.push_back(AC(a, b, p, m));
    }

    // use BFS to generate all possible combinations of air conditioners on/off
    queue<string> q;
    q.push(""); // empty string
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        if (s.length() == m) { // if the string is of length M, check if all the cows can be comfortable
            checker(s);
        } else {
            q.push(s + "0"); // try adding 0 to the end of the string (AC off)
            q.push(s + "1"); // try adding 1 to the end of the string (AC on)
        }
    }
    // at this point, the minimum cost is stored in mincost
    if (mincost == INT_MAX) { // if mincost is still INT_MAX, then no combination of air conditioners can cool all the cows
        cout << -1 << endl; // in the problem it states that there will always be a solution, so this should never happen
    } else { // now print the minimum cost (this should always happen unless this code is wrong)
        cout << mincost << '\n';
    }
    return; // FINISHED!
    // score: 11/11 on analysis mode
}