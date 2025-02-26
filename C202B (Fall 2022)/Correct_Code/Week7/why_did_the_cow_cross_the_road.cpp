#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int cowside[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int crosses = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int cow, side;
        cin >> cow >> side;
        if (cowside[cow-1] != side && cowside[cow-1] != -1) {
            crosses++;
        }
        cowside[cow-1] = side;
    }
    cout << crosses << endl;
}