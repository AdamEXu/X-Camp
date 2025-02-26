#include <iostream>
#include <stack>
#include <cmath>
#include <string.h>
#include <iomanip>
using namespace std;
char s[1000];
int g_pos; // current index of string

// read whole number
double Translation(int &pos) {
    double integer = 0.0; // integer part
    double remainder = 0.0; // remainder part

    while (s[pos] >= '0' && s[pos] <= '9') {
        integer*=10;
        integer+=s[pos]-'0';
        pos++;
    }
    
    if (s[pos] == '.') {
        pos++;
        int c = 1;
        while (s[pos] >= '0' && s[pos] <= '9') {
            double t = s[pos] - '0';
            t *= pow(0.1, c);
            c++;
            remainder += t;
            pos++;
        }
    }
    return integer + remainder;
}

// priority level
int GetLevel(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// calculate two numbers and an operator
double Operate(double a1, char op, double a2) {
    switch (op) {
        case '+':
            return a1 + a2;
        case '-':
            return a1 - a2;
        case '*':
            return a1 * a2;
        case '/':
            return a1 / a2;
        case '^':
            return pow(a1, a2);
        default:
            return 0.0;
    }
}

// main calculation function
double Compute() {
    stack<char> optr; // for operators
    stack<double> opnd; // for operands

    optr.push('#'); // help us to know end of calculation
    int len = strlen(s);
    bool is_minus = true; //minus sign or negative sign?
                          // e.g. -5+3*2 or 3+(-2)+6

    for (g_pos = 0; g_pos < len;) {
        // 1. check minus sign
        if (s[g_pos] == '-' && is_minus) { // minus sign
            opnd.push(0); // add a 0
            optr.push('-');
            g_pos++;
        }
        // 2. closing parenthese ')'
        else if (s[g_pos] == ')') {
            is_minus = false;
            g_pos++;

            while (optr.top() != '(') {
                double a2 = opnd.top();
                opnd.pop();
                double a1 = opnd.top();
                opnd.pop();
                char op = optr.top();
                optr.pop();
                opnd.push(Operate(a1, op, a2));
            }
            optr.pop(); //delete '('
        }
        // 3. this is a number
        else if (s[g_pos] >= '0' && s[g_pos] <= '9') {
            is_minus = false;
            opnd.push(Translation(g_pos));
        }
        // 4. opening parenthese
        else if (s[g_pos] == '(') {
            is_minus = true;
            optr.push(s[g_pos]);
            g_pos++;
        }
        // 5. this is and operator
        else {
            while (GetLevel(s[g_pos]) <= GetLevel(optr.top())) {
                // current priority is lower than the top of stack
                // finish the calculation using top of stack
                double a2 = opnd.top();
                opnd.pop();
                double a1 = opnd.top();
                opnd.pop();
                char op = optr.top();
                optr.pop();
                opnd.push(Operate(a1, op, a2));
            }
            optr.push(s[g_pos]);
            g_pos++;
        }
    }

    while (optr.top() != '#') {
        double a2 = opnd.top();
        opnd.pop();
        double a1 = opnd.top();
        opnd.pop();
        char op = optr.top();
        optr.pop();
        opnd.push(Operate(a1, op, a2));
    }

    return opnd.top();
}

int main(void) {
    cin >> s;
    cout << setprecision(2) << fixed << Compute() << endl;
    return 0;
}