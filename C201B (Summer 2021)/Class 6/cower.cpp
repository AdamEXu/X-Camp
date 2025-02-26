#include <iostream>
#include <vector>
using namespace std;

int h;

void vecout(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int addtower(vector<int> stack, int csum, vector<int> left) {
    // cout << csum << endl;
    // vecout(stack);
    // vecout(left);
    // cout << endl << endl;
    if (csum >= h) {
        // cout << "base case" << endl;
        // vecout(stack);
        // cout << csum-h << endl;;
        return csum-h;
    }
    // cout << "running" << endl;
    int l = 2147483647;
    for (int i = 0; i < left.size(); i++) {
        vector<int> leftovers = left;
        // vecout(leftovers)≥÷;
        int c = leftovers[i];
        stack.push_back(c);
        leftovers.erase(leftovers.begin()+i);
        int t = addtower(stack, csum+c, leftovers);
        if (t < l) {
            l = t;
        }
        stack.erase(prev(stack.end()));
    }
    return l;
}

int main(void) {
    int n;
    cin >> n >> h;
    vector<int> cows;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cows.push_back(t);
    }
    vector<int> t;
    cout << addtower(t, 0, cows) << endl;;
}