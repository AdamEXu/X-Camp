#include<iostream>
#include<vector>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int diff = b-a+1; // 2
        for (int j = 0; j < diff/2; j++) {
            int temp = nums[a+j-1]; // 
            nums[a+j-1] = nums[a+diff-j-2];
            nums[a+diff-j-2] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}