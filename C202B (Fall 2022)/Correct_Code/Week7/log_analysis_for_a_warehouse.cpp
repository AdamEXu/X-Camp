#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
    int n, max = 0, maxct = 0;
    scanf("%d", &n);
    stack<int> s;
    stack<int> maxstack, maxctstack;
    maxstack.push(0);
    for (int i = 0; i < n; i++) {
        int operation;
        scanf("%d", &operation);
        if (operation == 0) {
            int ammount;
            scanf("%d", &ammount);
            if (ammount > max) {
                max = ammount;
                maxctstack.push(maxct);
                maxct = 1;
                maxstack.push(ammount);
            } else if (ammount == max) {
                maxct++;
            }
            s.push(ammount);
        } else if (operation == 1) {
            if (maxstack.size() > 0 && s.size() > 0 && s.top() == max && maxct == 1) {
                maxstack.pop();
                max = maxstack.top();
                maxct = maxctstack.top();
            }
            if (s.size() > 0) {
                s.pop();
            }
        } else if (operation == 2) {
            printf("%d\n", max);
        }
    }
}