#include <iostream>
using namespace std;

int hanoi(int n, char start, char aux1, char aux2, char end, int num) {
    if (n == 1) {
        cout << "Move disk " << num << " from rod " << start << " to rod " << end << endl;
        return 1;
    } else if (n == 2) {
        cout << "Move disk " << num << " from rod " << start << " to rod " << aux1 << endl;
        cout << "Move disk " << num+1 << " from rod " << start << " to rod " << end << endl;
        cout << "Move disk " << num << " from rod " << aux1 << " to rod " << end << endl;
        return 3;
    } else if (n == 3) {
        cout << "Move disk " << num << " from rod " << start << " to rod " << aux1 << endl;
        cout << "Move disk " << num+1 << " from rod " << start << " to rod " << aux2 << endl;
        cout << "Move disk " << num+2 << " from rod " << start << " to rod " << end << endl;
        cout << "Move disk " << num+1 << " from rod " << aux2 << " to rod " << end << endl;
        cout << "Move disk " << num << " from rod " << aux1 << " to rod " << end << endl;
    } else {
        int a = hanoi(n - 2, start, aux2, end, aux1, num+1);
        cout << "Move disk " << num+1 << " from rod " << start << " to rod " << aux2 << endl;
        cout << "Move disk " << num+1 << " from rod " << start << " to rod " << end << endl;
        cout << "Move disk " << num+1 << " from rod " << aux2 << " to rod " << end << endl;
        int b = hanoi(n - 2, aux1, start, aux2, end, num-1);
        return a+b+3;
    }
}

int main() {
    int n;
    cin >> n;
    hanoi(n, 'A', 'C', 'D', 'B', 1);
    return 0;
}