#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Add all elements of a vector together
// int sum_preK(vector <int> myin, int n, int k){
//     int mySum = 0;

//     for (int i = 1; i <= k; i++) {
//         mySum += myin[n-i-1];
//     }
       
//     return mySum;
// }

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

// adds two int vectors together
vector <int> add_big_int (vector <int> num1, vector <int> num2) {
    while (num1.size() < num2.size()) {
        num1.insert(num1.begin(), 0);
    }
    while (num2.size() < num1.size()) {
        num2.insert(num2.begin(), 0);
    }

    int size1 = num1.size(), size2 = num2.size();
    int carry = 0;
    vector <int> result;
    for(int i = 0; i < size1; i++){
        int sum = num1[size1 - i  -1 ] + num2[size2 - i  -1 ] + carry;
        if (sum >= 10) {
            carry = 1;
            sum -= 10;
        } else {
            carry = 0;
        }
        result.insert(result.begin(), sum);
    }
    if (carry == 1) {
        result.insert(result.begin(), 1);
    }

    return result;
}

void print_vector(vector <int> myin) {
    for (int i = 0; i < myin.size(); i++) {
        cout << myin[i] << "";
    }
    cout << endl;
}

// Add all elements of a vector together 
// and keep them to a single digiter int vector
vector <int> sum_all (vector <vector <int> > myin) {
    vector <int> mySum;   
    // mySum.push_back(0);
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

class Node {
    public: int data;

    Node* next;
};

void print_list(Node* n){
    while (n != NULL){
        cout << n->data << " ";
        n = n->next;
    }
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

    k = 2;

    int result = 0 ;

   
    int[k]  countSteps = NULL;

    for (int i = 0; i < n; i ++ ){
        if (n==0 or n==1){
            countSteps[i] = 1;
         }
         int sum = 0;
         for(int j = 0; j< k; j++){
             sum+=countSteps[j];
         }




    }

    cout << "result = " << result << endl;
    // keep <= k elements
    // vector <vector <int> > countSteps;
    // vector <int> result = climb_stairs(countSteps, n, k);
    // print_vector(result);
    // //print_vector(sum_all);
}