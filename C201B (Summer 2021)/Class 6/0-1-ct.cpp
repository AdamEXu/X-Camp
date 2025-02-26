#include <iostream>
#include <vector>
using namespace std;

int l = 0;

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

long long power(int n, int p) {
    long long result = n;
    for (int i = 0; i < p; i++) {
        result*=n;
    }
    return result;
}

long long vecToInt(vector<int> vec){
    int n = 0;
    for (int i = 0; i < vec.size(); i++) {
        n*=10;
        n+=vec[i];
    }
    return n;
}

int addnumber(vector<int> current, long long max) {
    int n;
    // make sure the number isn't above n
    if (vecToInt(current) > max) {
        return 0;
    // optimization
    } else if (current.size() > l+1) {
        return 0;
    // check to see if first digit is 0
    } else if (current.size() != 0 && current[0] <= 0) { // I do not trust this bit.
        n = 0;
    } else if (vecToInt(current) == 0) {
        n = 0;
    } else {
        n = 1;
    }
    cout << n << endl;
    cout << vecToInt(current) << endl;
    vecout(current);
    cout << endl;
    current.insert(current.begin(), 1);
    n+=addnumber(current, max);
    current.erase(current.begin());
    if (n > 1) {
        current.insert(current.begin(), 0);
        n+=addnumber(current, max);
        current.erase(current.begin());
    }
    return n;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> temp;
    int t = n;
    while (t != 0) {
        t/=10;
        l++;
    }
    // temp.push_back(0);
    // temp.push_back(1);
    // temp.push_back(3);
    // cout << vecToInt(temp) << endl;
    cout << addnumber(temp, n) << endl;
}