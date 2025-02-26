#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> insertsort(vector<int> arr) {
    for (int i = 1; i < arr.size(); i++) {
        int j = i;
        while (j > 0 && arr[j] < arr[j-1]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
    return arr;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    arr = insertsort(arr);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}