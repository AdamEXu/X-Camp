#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

vector <int> convert_int_to_Intvec(int input) {
    stack<int> sd;
    vector <int> my_output;

    while (input > 0)
    {
        int digit = input%10;
        input /= 10;
        sd.push(digit);
    }

    while (!sd.empty())
    {
        int digit = sd.top();
        sd.pop();
        my_output.push_back(digit);
    }
    return my_output;
}

vector <int> convert_string_to_Intvec(string s1) {
    vector <int> a;
    for (int i = 0; i < s1.size(); i++) {
        a.push_back(s1[s1.size()-i-1]-'0');
    }
    return a;
}

// adds two int vectors together
vector <int> add_big_int(vector<int> a, vector<int> b) {
    int len1 = a.size();
    int len2 = b.size();
    int len3 = max(len1, len2)+1;

    while (a.size() < b.size()) {
        a.push_back(0);
    }
    while (a.size() > b.size()) {
        b.push_back(0);
    }

    vector <int> c;

    // Add the two vectors (a and b) together
    int carry = 0;
    for (int i = 0; i < len3-1; i++) {
        int sum = a[i] + b[i] + carry;
        carry = 0;
        if (sum >= 10) {
            carry = 1;
            c.push_back(sum-10);
        } else {
            c.push_back(sum);
        }
    }

    if (carry == 1) {
        c.push_back(1);
    }
    return c;
}

void print_vector(vector <int> myin) {
    for (int i = 0; i < myin.size(); i++) {
        cout << myin[i];
    }
    cout << endl;
}

// Add all elements of a vector together 
// and keep them to a single digiter int vector
vector <int> sum_all (vector <vector <int> > myin) {
    vector <int> mySum;   
    mySum.push_back(0);
    // mySum = add_big_int(mySum, myin[i]);
    for (int i = 0; i < myin.size(); i++) {
        mySum = add_big_int(mySum, myin[i]);
    }

    return mySum;
}

vector <int> climb_stairs(vector <vector <int> > countSteps, int n, int k) {
  // base case(s) n<=k
  // 1) n<=2
    if(n <= 2) {
        vector <int> temp;
        temp.push_back(n);
        return temp;
    } 

    int mySize = 0;

    // define the contents of the vector
    for (int i = 1; i <= 2; i++) {
        vector <int> temp;
        temp.push_back(i);
        countSteps.push_back(temp);
    }
    vector <int> myNext;

    // Base case 2) 3 < n <=k
    for (int i = 3; i <= k; i++) {
        vector <int> one;
        one.push_back(1);

        myNext = add_big_int(sum_all(countSteps), one);

        countSteps.push_back(myNext);
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
    
    int miniSize = countSteps[mySize-1].size();
    return countSteps[mySize-1];
}

// Driver code
int main(void) {
    int n;
    int k;
    cin >> n;
    cin >> k;
    if (k > n) {
        k = n;
    }

    // keep <= k elements
    vector <vector <int> > countSteps;

    vector <int> result = climb_stairs(countSteps, n, k);
    reverse(result.begin(), result.end());
    print_vector(result);


    //print_vector(sum_all);
}