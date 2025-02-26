#include <iostream>
#include <vector>
using namespace std;

// Add all elements of a vector together
// int sum_preK(vector <int> myin, int n, int k){
//     int mySum = 0;

//     for (int i = 1; i <= k; i++) {
//         mySum += myin[n-i-1];
//     }
       
//     return mySum;
// }

void print_vector(vector <int> myin) {
    for (int i = 0; i < myin.size(); i++) {
        cout << myin[i] << ", ";
    }
    cout << endl;
}

// Add all elements of a vector together 
int sum_all (vector <int> myin) {
    int mySum = 0;

    for (int i = 0; i < myin.size(); i++) {
        mySum += myin[i];
    }

    return mySum;
}

int climb_stairs(vector <int> countSteps, int n, int k) {
  // base case(s) n<=k
  // 1) n<=2
    if(n <= 2) {
        return n;
    } 

    int mySize = 0;

    // define the contents of the vector
    for (int i = 1; i <= 2; i++) {
        countSteps.push_back(i);
    }
    int myNext = 0;
    // Base case 2) 3 < n <=k
    for (int i = 3; i <= k; i++) {
        myNext = sum_all(countSteps)+1;
        countSteps.push_back(myNext);
        // mySize = countSteps.size();
        // if (mySize > k) {
        //     countSteps.erase(countSteps.begin());
        // }
    }

    for (int i = k+1; i <= n; i++) {
        mySize = 0;
        myNext = sum_all(countSteps);
        countSteps.push_back(myNext);
        mySize = countSteps.size();
        if (mySize > k) {
            countSteps.erase(countSteps.begin());
        }
    }

    mySize = countSteps.size();
    return countSteps[mySize-1];
}

// Driver code
int main(void) {
    int n;
    int k = 3;
    cin >> n;
    // cin >> k;
    if (k > n) {
        k = n;
    }

    // keep <= k elements
    vector <int> countSteps;

    cout << climb_stairs(countSteps, n, k) << endl;
}