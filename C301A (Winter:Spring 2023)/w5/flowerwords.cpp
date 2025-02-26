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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin >> n;
        vector<string> words;
        int currentlen = 0;
        while (currentlen <= n) {
            string temp;
            cin >> temp;
            words.push_back(temp);
            currentlen+=temp.length()+1;
        }
        for (int i = 0; i < words.size()-1; ++i) {
            if (words[i][words[i].size()-1] != words[i+1][0]) {
                cout << "NO" << '\n';
                return 0;
            }
        }
        if (words[0][0] != words[words.size()-1][words[words.size()-1].size()-1]) {
            cout << "NO" << '\n';
            return 0;
        }
        cout << "YES" << '\n';
    }