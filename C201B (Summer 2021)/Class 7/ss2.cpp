#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
using namespace std;

int place_cow(vector<int> cow_list, vector<int> placed_cows, int currentHeight, int neededHeight) {
    int least = INT_MAX;
    for (int i = 0; i < cow_list.size(); i++) {
        int currentCow = cow_list[0];
        cow_list.erase(cow_list.begin());
        placed_cows.push_back(currentCow);
        int result = place_cow(cow_list, placed_cows, least, neededHeight);
        if (result == 0) {
            return 0;
        }
        if (result < neededHeight) {
            
        }
        if (result < least) {
            least = result;
        }
    }
    return least;
}

int main(void) {
    vector<int> cow_list;
    vector<int> placed_cows;
    int n = 0, m=0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cow_list.push_back(temp);
    }
    cout << place_cow(cow_list, placed_cows, INT_MAX, m) << endl;
}