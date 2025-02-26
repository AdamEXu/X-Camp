#include <iostream>
#include <vector>
using namespace std;

int main(void) {
int n;
while (cin >> n) {
    vector<int> scores;
    vector<int> below;
    double average = 0.0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        scores.push_back(temp);
        average+=temp;
    }
    average/=double(n);
    for (int i = 0; i < n; i++) {
        if (scores[i] < average) {
            cout << scores[i] << " ";
        }
    }
    cout << endl;
}
}