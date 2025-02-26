#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
    // there are n cows
    int n;
    cin >> n;
    // input cow types 
    string cows;
    cin >> cows;
    int minG, maxG, minH, maxH;
    // calculate minG
    for (int i = 0; i < n; ++i) {
        if (cows[i] == 'G') {
            minG = i;
            break;
        }
    }
    // calculate maxG
    for (int i = n-1; i >= 0; --i) {
        if (cows[i] == 'G') {
            maxG = i;
            break;
        }
    }
    // calculate minH
    for (int i = 0; i < n; ++i) {
        if (cows[i] == 'H') {
            minH = i;
            break;
        }
    }
    // calculate maxH
    for (int i = n-1; i >= 0; --i) {
        if (cows[i] == 'H') {
            maxH = i;
            break;
        }
    }
    // input e[i] value for each cow
    vector<int> e(n);
    for (int i = 0; i < n; ++i) {
        cin >> e[i];
        --e[i]; // convert to 0-indexed
    }
    int count = 0; // count the number of possible pairs of leaders
    // Case #1
    // G leader is minG
    if (e[minG] >= maxG) {
        // loop through all H cows that come before minG (the leader)
        for (int Hp = minH+1; Hp < minG; ++Hp) {
            // see if the H cow's list contains the leader
            if (cows[Hp] == 'H' && e[Hp] >= minG) {
                // if yes: increment count
                ++count;
            }
        }
    }
    // Case #2
    // H leader is minH
    if (e[minH] >= maxH) {
        // loop through all G cows that come before minH (the leader)
        for (int Gp = minG+1; Gp < minH; ++Gp) {
            // see if the G cow's list contains the leader
            if (cows[Gp] == 'G' && e[Gp] >= minH) {
                // if yes: increment count
                ++count;
            }
        }
    }
    // Case #3
    // G leader is minG and H leader is minH
    // see if any of the following conditions are true:
    if (
        (e[minG] >= maxG && e[minH] >= maxH) /* G leader's list contains all of the G cows and H leader's list contains all the H cows */  || // OR
        (e[minG] >= maxG && e[minH] >= minG) /* G leader's list contains all of the G cows and H leader's list contains the G leader */ || // OR
        (e[minH] >= maxH && e[minG] >= minH) // H leader's list contains all of the H cows and G leader's list contains the H leader
    ) ++count; // if yes: increment count
    // print out the count
    cout << count << '\n';
}