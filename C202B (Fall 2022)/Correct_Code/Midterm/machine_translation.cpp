#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool find(vector<int> vec, int num) {
    if (vec.size() == 0) {
        return false;
    }
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == num) {
            return true;
        }
    }
    return false;
}

int main(void) {
    int m, n;
    cin >> m >> n;
    int counter = 0;
    vector<int> cache;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (!find(cache, num)) {
            counter++;
            cache.push_back(num);
            if (cache.size() > m) {
                cache.erase(cache.begin());
            }
        } 
    }
    cout << counter << endl;
}