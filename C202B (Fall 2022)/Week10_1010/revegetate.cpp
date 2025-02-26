#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool findmatch(vector<int> a, vector<int> b) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    int boxct, cowct;
    cin >> boxct >> cowct;
    vector<int> boxes[boxct];
    vector<int> seeds[4];
    int labels[boxct];
    for (int i = 0; i < cowct; i++) {
        int a, b;
        cin >> a >> b;
        boxes[a-1].push_back(i);
        boxes[b-1].push_back(i);
    }
    for (int i = 0; i < boxct; i++) {
        int seed_num = 0;
        for (int j = 0; j < 4; j++) {
            if (!findmatch(boxes[i], seeds[j])) {
                seed_num = j;
                break;
            }
        }
        for (int j = 0; j < boxes[i].size(); j++) {
            seeds[seed_num].push_back(boxes[i][j]);
            labels[i] = seed_num+1;
        }
    }
    for (int i = 0; i < boxct; i++) {
        cout << labels[i];
    }
    cout << endl;
}