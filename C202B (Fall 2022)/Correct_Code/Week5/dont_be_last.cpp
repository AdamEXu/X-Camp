#include <iostream>
#include <map>
using namespace std;

int main(void) {
    map<string, int> cows;
    int n;
    cin >> n;
    string names[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    for (int i = 0; i < 7; i++) {
        cows[names[i]] = 0;
    }
    for (int i = 0; i < n; i++) {
        string name;
        int milk;
        cin >> name >> milk;
        cows[name] += milk;
    }
    int least = 100000;
    for (int i = 0; i < cows.size(); i++) {
        if (cows[names[i]] < least) {
            least = cows[names[i]];
        }
    }
    for (int i = 0; i < cows.size(); i++) {
        if (cows[names[i]] == least) {
            cows[names[i]] = 100000;
        }
    }
    int second_least = 100000;
    string second_least_cow = "";
    for (int i = 0; i < cows.size(); i++) {
        if (cows[names[i]] < second_least) {
            second_least_cow = names[i];
            second_least = cows[names[i]];
        } else if (cows[names[i]] == second_least) {
            second_least_cow = "Tie";
        }
    }
    cout << second_least_cow << endl;
}