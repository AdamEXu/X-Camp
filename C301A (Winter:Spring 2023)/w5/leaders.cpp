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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin >> n;
        vector<char> s(n);
        int minG=-1, maxG, minH=-1, maxH;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            if (s[i] == 'G') {
                if (minG == -1) minG = i;
                maxG = i;
            }
            else {
                if (minH == -1) minH = i;
                maxH = i;
            }
        }
        vector<int> e(n);
        vector<bool> willdo(n);
        for (int i = 0; i < n; i++) {
            cin >> e[i];
            --e[i];
            if (s[i] == 'G' && e[i] >= maxG && i <= minG) willdo[i] = true;
            else if (s[i] == 'H' && e[i] >= maxH && i <= minH) willdo[i] = true;
        }
        int count = 0;
        for (int Gp = minG; Gp < n; ++Gp) {
            while (Gp < n && s[Gp] != 'G') ++Gp;
            if (Gp == n) break;
            for (int Hp = minH; Hp < n; ++Hp) {
                while (Hp < n && s[Hp] != 'H') ++Hp;
                if (Hp == n) break;
                bool G = willdo[Gp], H = willdo[Hp];
                if (G && H) {
                    ++count;
                    continue;
                }
                if (!G && e[Gp] >= Hp && Gp <= Hp) {
                    G = true;
                    if (H) {
                        ++count;
                        continue;
                    }
                }
                if (!H && e[Hp] >= Gp && Hp <= Gp) {
                    H = true;
                    if (G) {
                        ++count;
                        continue;
                    }
                }
                if (G && H) {
                    ++count;
                    continue;
                }
            }
        }
        cout << count << '\n';
    }