#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector <int> myin) {
    for (int i = 0; i < myin.size()-1; i++) {
        cout << myin[i] << ", ";
    }
    cout << endl;
}

vector <int> add_big_int(vector <int> num1, vector <int> num2) {
    while (num1.size() < num2.size()) {
        num1.insert(num1.begin(), 0);
    }
    while (num2.size() < num1.size()) {
        num2.insert(num2.begin(), 0);
    }
    int j = num2.size();
    int carry = 0;
    vector <int> result;
    for(int i = num1.size(); i > 0; i--) {
        int added = num1[i] + num2[j] + carry - 1;
        bool it_works = false;
        if ((added >= 10) && (i != num1.size())) {
            added -= 10;
            it_works = true;
            // carry = 1;
        }
        result.insert(result.begin(), added);
        carry = 0;
        if (it_works) {
            carry = 1;
        }
        j--; 
    }
    if (carry >= 1) {
        result.insert(result.begin(), carry);
    }
    return result;
}

int main(void) {
    vector <int> num1;
    vector <int> num2;
    // int in1, in2;
    // cin >> in1 >> in2;
    for (int i = 0; i < 10; i++) {
        int temp;
        cin >> temp;
        num1.push_back(temp);
    }
    cout << "DONE WITH NUM1! NOW FOR NUM2." << endl;
    for (int i = 0; i < 10; i++) {
        int temp;
        cin >> temp;
        num2.push_back(temp);
    }
    vector <int> result = add_big_int(num1, num2);
    print_vector(result);
}