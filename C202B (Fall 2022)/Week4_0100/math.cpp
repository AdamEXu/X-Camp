#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

double doit(double a, double b, char o) {
    if (o == '+') {
        return a+b;
    } else if (o == '-') {
        return a-b;
    } else if (o == '*') {
        return a*b;
    } else if (o == '/') {
        return a/float(b);
    } else if (o == '^') {
        double result = 1;
        for (int i = 0; i < b; i++) {
            result*=a;
        }
        return result;
    }
    return -1;
}

double calculator(string expression) {
    stack<char> operationStack;
    stack<double> numberStack;
    for (int i = 0; i < expression.length(); i++) {
        char current = expression[i];
        if (current >= '0' && current <= '9') {
            int n = 0;
            int nlength = 0;
            while (i < expression.length() && expression[i] >= '0' && expression[i] <= '9') {
                n*=10;
                n+=expression[i+nlength]-'0';
                i++;
            }
            i--;
            numberStack.push(n);
            continue;
        }
        else {
            if (current == ')') {
                int index = i-1;
                int paras = 1;
                while (expression[index] != '(' && paras != 0) {
                    if (expression[index] == ')') {
                        paras++;
                    } else if (expression[index] == '(') {
                        paras--;
                    }
                    index--;
                    cout << index << endl;
                }
                operationStack.pop();
                while (operationStack.top() != '(') {
                    numberStack.pop();
                    operationStack.pop();
                }
                numberStack.pop();
                operationStack.pop();
                string subexpression = expression.substr(index+1, i-1-index);
                cout << subexpression << endl;
                double answer = calculator(subexpression);
                cout << answer << endl;
                numberStack.push(answer);
            } else if (current == '(') {
                operationStack.push(current);
            } else if (current == '^') {
                if (operationStack.empty()) {
                    operationStack.push(current);
                } else if (operationStack.top() == '+' || operationStack.top() == '-' || operationStack.top() == '*' || operationStack.top() == '/' || operationStack.top() == '^' || operationStack.top() == '(') {
                    operationStack.push(current);
                } else if (operationStack.top() == ')') {
                    double a = numberStack.top();
                    numberStack.pop();
                    double b = numberStack.top();
                    numberStack.pop();
                    double result = doit(b, a, operationStack.top());
                    numberStack.push(result);
                    operationStack.pop();
                }
            } else if (current == '*' || current == '/') {
                if (operationStack.empty()) {
                    operationStack.push(current);
                } else if (operationStack.top() == '+' || operationStack.top() == '-' || operationStack.top() == '*' || operationStack.top() == '/' || operationStack.top() == '^' || operationStack.top() == '(') {
                    operationStack.push(current);
                } else if (operationStack.top() == '^' || operationStack.top() == ')') {
                    double a = numberStack.top();
                    numberStack.pop();
                    double b = numberStack.top();
                    numberStack.pop();
                    double result = doit(b, a, operationStack.top());
                    numberStack.push(result);
                    operationStack.pop();
                    operationStack.push(current);
                }
            } else if (current == '+' || current == '-') {
                if (operationStack.empty()) {
                    operationStack.push(current);
                } else if (operationStack.top() == '+' || operationStack.top() == '-' || operationStack.top() == '(') {
                    operationStack.push(current);
                } else if (operationStack.top() == '*' || operationStack.top() == '/' || operationStack.top() == '^' || operationStack.top() == ')') {
                    double a = numberStack.top(); numberStack.pop();
                    double b = numberStack.top(); numberStack.pop();
                    char o = operationStack.top(); operationStack.pop();
                    numberStack.push(doit(b, a, o));
                    operationStack.push(current);
                }
            }
        }
    }
    while (!operationStack.empty()) {
        double a = numberStack.top();
        numberStack.pop();
        double b = numberStack.top();
        numberStack.pop();
        numberStack.push(doit(b, a, operationStack.top()));
        operationStack.pop();
    }
    return numberStack.top();
}

int main(void) {
    string expression;
    getline(cin, expression);
    double final;
    final = calculator(expression);
    cout << fixed << setprecision(2) << final << endl;
    return final;
}