#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BigInt
{
public:
    BigInt(); // default constructor, value = 0
    BigInt(int); // assign an integer value
    BigInt(const string &); // assign a string
    // may need these in alternative implementation
    // BigInt(const BigInt &); // copy constructor
    // ~BigInt(); // destructor
    // const BigInt & operator = (const BigInt &);
    // assignment operator
    // operators: arithmetic, relational
    const BigInt & operator += (const BigInt &);
    const BigInt & operator -= (const BigInt &);
    const BigInt & operator *= (const BigInt &);
    const BigInt & operator *= (int num);
    string ToString() const; // convert to string
    int ToInt() const; // convert to int
    double ToDouble() const; // convert to double
    // facilitate operators ==, <, << without friends
    bool Equal(const BigInt & rhs) const;
    bool LessThan(const BigInt & rhs) const;
    void Print(ostream & os) const;
private:
    // other helper functions
    bool IsNegative() const; // return true iff number is negative
    bool IsPositive() const; // return true iff number is positive
    int NumDigits() const; // return # digits in number
    int GetDigit(int k) const;
    void AddSigDigit(int value);
    void ChangeDigit(int k, int value);
    void Normalize();
    // private state/instance variables
    enum Sign{positive,negative};
    Sign mySign; // is number positive or negative
    vector<char> myDigits; // stores all digits of number
    int myNumDigits; // stores # of digits of number
};

// free functions
ostream & operator <<(ostream &, const BigInt &);
istream & operator >>(istream &, BigInt &);
BigInt operator +(const BigInt & lhs, const BigInt & rhs);
BigInt operator -(const BigInt & lhs, const BigInt & rhs);
BigInt operator *(const BigInt & lhs, const BigInt & rhs);
BigInt operator *(const BigInt & lhs, int num);
BigInt operator *(int num, const BigInt & rhs);
bool operator == (const BigInt & lhs, const BigInt & rhs);
bool operator < (const BigInt & lhs, const BigInt & rhs);
bool operator != (const BigInt & lhs, const BigInt & rhs);
bool operator > (const BigInt & lhs, const BigInt & rhs);
bool operator >= (const BigInt & lhs, const BigInt & rhs);
bool operator <= (const BigInt & lhs, const BigInt & rhs);

int main(void) {
    BigInt n = 100000000;
    BigInt n2 = 100000000;
    BigInt result = 0;
    result = result + n;
    result += n2;
    cout << result << endl;
}