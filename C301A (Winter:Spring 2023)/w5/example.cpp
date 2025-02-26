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

int N;
string s;
int arr[100];

int main(void) {
    cin >> N >> s;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    cout << "N: " << N << '\n';
    cout << "S: " << s << '\n';
    cout << "Arr: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    if ((arr[eG] >= lG 
 || (eG <= eH && arr[eG] >= eH))
 && (arr[eH] >= lH
 || (eH <= eG && arr[eH] >= eG)))
    cout << '\n';
}