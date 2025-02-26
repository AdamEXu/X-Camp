#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

int main(void) {
    string word, toword;
    cin >> word >> toword;
    int n;
    cin >> n;
    map<string, int> dictionary;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        dictionary[temp] = -1;
    }
    queue<string> noteboook;
    noteboook.push(word);
    dictionary[word] = 0;
    while (!noteboook.empty()) {
        string current = noteboook.front();
        noteboook.pop();
        // cout << current << endl;
        // 3 possible ways to change the word: replace a letter, insert a letter, delete a letter
        // change the letter
        for (int i = 0; i < current.length(); i++) {
            string newword = current;
            for (int j = 0; j < 26; j++) {
                newword[i] = 'a' + j;
                if (dictionary[newword] != 0 && newword != current) {
                    if (newword == toword) {
                        cout << dictionary[current] + 1 << endl;
                        return 0;
                    }
                    noteboook.push(newword);
                    dictionary[newword] = dictionary[current] + 1;
                }
            }
        }
        // insert letter
        for (int i = 0; i < current.length(); i++) {
            string newword = current;
            for (int j = 0; j < 26; j++) {
                newword.insert(i, 1, 'a' + j);
                if (dictionary[newword] != 0) {
                    if (newword == toword) {
                        cout << dictionary[current] + 1 << endl;
                        return 0;
                    }
                    noteboook.push(newword);
                    dictionary[newword] = dictionary[current] + 1;
                }
                newword = current;
            }
        }
        // remove letter
        for (int i = 0; i < current.length(); i++) {
            string newword = current;
            newword.erase(i, 1);
            if (dictionary[newword] != 0) {
                if (newword == toword) {
                    cout << dictionary[current] + 1 << endl;
                    return 0;
                }
                noteboook.push(newword);
                dictionary[newword] = dictionary[current] + 1;
            }
        }
    }
    cout << -1 << endl;
}