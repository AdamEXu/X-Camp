#include <iostream>
#include <vector>
using namespace std;

int max1;

long long vecToInt(vector<int> vec){
    int n = 0;
    for (int i = 0; i < vec.size(); i++) {
        n*=10;
        n+=vec[i];
    }
    return n;
}

int addnumber(vector<int> current) {
    if (vecToInt(current) > max1) {
        return 0;
    }
    int t = 1;
    current.push_back(1);
    t+=addnumber(current);
    current.erase(current.end()-1);
    current.push_back(0);
    t+=addnumber(current);
    current.erase(current.end()-1);
    return t;
}

int main(void) {
    cin >> max1;
    vector<int> temp;
    temp.push_back(1);
    cout << addnumber(temp) << endl;
}