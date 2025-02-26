#include <iostream>
#include <vector>
using namespace std;

long long counter = 0; 

void vecout(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size()-1) {
            cout << ", ";
        } else {
            cout << endl;
        }
    }
}

void make_comb(vector<int> current, vector<int> blocks, int n, int d) {
    cout << current.size() << endl;
    vecout(current);
    cout << "n = " << n << endl;
    if (current.size() == n) {
        bool temp = true;
        for (int i = 1; i < n; i++) {
            vecout(current);


            if (i>=4 || i<1) {
                exit(-1);
            }
            if (current[i]-d >= current[i-1]) {
            } else {
                cout << "false: i: " << i << "     current[i]: " << current[i] << " i-1:  " << current[i-1] << endl;

                temp = false;
            }
            if (temp) {
                cout << "true: i: " << i << "     current[i]: " << current[i] << " i-1:  " << current[i-1] << endl;

                vecout(current);
            }
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << "i = " << i << endl;
        current.insert(current.end(), blocks[i]);
        make_comb(current, blocks, n, d);
        cout << "put in" << endl;
        vecout(current);
        current.erase(prev(current.end()));
        cout << "take out" << endl;
    }
}

int maoge_tower(int n, int D, vector <int> bricks) {
    cout << n << " " << D << endl;
    vecout(bricks);
    vector<int> temp;
    make_comb(temp, bricks, n, D);
    cout << counter << endl;
    return 0;
}

int main(void) {
    int n, d;
    cin >> n >> d;
    vector<int> bricks;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        bricks.insert(bricks.end(), temp);
    }
    maoge_tower(n, d, bricks);
    return 0;
}