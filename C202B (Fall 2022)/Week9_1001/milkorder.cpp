#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> stringsplitter(string s, char c) {
    vector<string> v;
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            v.push_back(temp);
            temp = "";
        } else {
            temp+=s[i];
        }
    }
    v.push_back(temp);
    return v;
}

int main(void) {
    string cows[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    int n;
    cin >> n;
    vector<pair<string, string> > rules;
    for (int i = 0; i < n; i++) {
        string rule;
        getline(cin, rule);
        vector<string> splitrule = stringsplitter(rule, ' ');
        rules.push_back(make_pair(splitrule[0], splitrule[5]));
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < 8; k++) {
                if (i == k || j == k) {
                    continue;
                }
                for (int l = 0; l < 8; l++) {
                    if (i == l || j == l || k == l) {
                        continue;
                    }
                    for (int a = 0; a < 8; a++) {
                        if (i == a || j == a || k == a || l == a) {
                            continue;
                        }
                        for (int b = 0; b < 8; b++) {
                            if (i == b || j == b || k == b || l == b || a == b) {
                                continue;
                            }
                            for (int c = 0; c < 8; c++) {
                                if (i == c || j == c || k == c || l == c || a == c || b == c) {
                                    continue;
                                }
                                for (int d = 0; d < 8; d++) {
                                    if (i == d || j == d || k == d || l == d || a == d || b == d || c == d) {
                                        continue;
                                    }
                                    bool valid = true;
                                    string coworder[8] = {cows[i], cows[j], cows[k], cows[l], cows[a], cows[b], cows[c], cows[d]};
                                    for (int x = 0; x < rules.size(); x++) {
                                        // get index for rules.first
                                        int aindex = 0;
                                        for (int y = 0; y < 8; y++) {
                                            if (coworder[y] == rules[x].first) {
                                                aindex = y;
                                                break;
                                            }
                                        }
                                        // get index for rules.second
                                        int bindex = 0;
                                        for (int y = 0; y < 8; y++) {
                                            if (coworder[y] == rules[x].second) {
                                                bindex = y;
                                                break;
                                            }
                                        }
                                        if (abs(aindex - bindex) == 1) {
                                            continue;
                                        } else {
                                            valid = false;
                                            break;
                                        }
                                    }
                                    if (valid) {
                                        cout << coworder[0] << " " << coworder[1] << " " << coworder[2] << " " << coworder[3] << " " << coworder[4] << " " << coworder[5] << " " << coworder[6] << " " << coworder[7] << endl;
                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}