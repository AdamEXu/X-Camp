#include <iostream>
#include <vector>
using namespace std;

class BigNum {
    private: vector <int> numberVec;

    void setNumberVec( vector <int> myVec){
        numberVec = myVec;
    };

    vector <int> getNumber(void) {
        return numberVec;
    };

    BigNum addBigNum(BigNum num1, BigNum num2){
       while (num1.size() < num2.size()) {
            num1.insert(num1.begin(), 0);
        }
        while (num2.size() < num1.size()) {
            num2.insert(num2.begin(), 0);
        }
        auto j = num2.end();
        vector <int> result;
        int carry = 0;
        for(auto i = num1.end(); i != num1.begin(); i--) {
            result.insert(result.begin(), ((*i+*j)%10)+carry);
            carry = *i / *j;
            j--;
        }
        return result;
   }
};

int main(void) {
    BigNum num1 = new BigNum();
    num1.addBigNum();

}