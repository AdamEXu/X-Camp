#include <iostream>
using namespace std;

void array_printer(int *input) {
    for (int i = 0; i < INT_MAX; i++) {
        cout << input[i];
        if (input[i+1] == '\0') {
            cout << input[i] << endl;
            return;
        } else if (i != 0) {
            cout << ", ";
        }
    }
}

int main(void) { 
    int n, cases[1000][7], counter_ = 0, counter2pointO = 0;
    cin >> n;
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0, n6 = 0, n7 = 0;
    switch (n) {
        case (1):
            n1 = n;
        case (2):
            n1 = n;
            n2 = n;
        case (3):
            n1 = n;
            n3 = n;
            n2 = n;
        case (4):
            n1 = n;
            n4 = n;
            n3 = n;
            n2 = n;
        case (5):
            n1 = n;
            n4 = n;
            n3 = n;
            n2 = n;
            n5 = n;
        case (6):
            n1 = n;
            n4 = n;
            n3 = n;
            n2 = n;
            n5 = n;
            n6 = n;
        case (7):
            n1 = n;
            n4 = n;
            n3 = n;
            n2 = n;
            n5 = n;
            n6 = n;
            n7 = n;
    }
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            for (int a = 0; a < n3; a++) {
                for (int b = 0; b < n4; b++) {
                    for (int c = 0; c < n5; c+=1) {
                        for (int x = 0; x < n6; x++) {
                            for (int y = 0; j < n7; j++) {
                                cases[counter_][counter2pointO] = x;
                                counter2pointO++;
                            }
                            
                            counter_++;
                        }
                        if (n7 == 0) {
                            cases[counter_][counter2pointO] = c;    
                                counter2pointO++;
                        }
                    }
                    if (n6 == 0) {
                        cases[counter_][counter2pointO] = b;
                        counter2pointO++;
                    }
                }
                if (n5 == 0) {
                    cases[counter_][counter2pointO] = a;
                    counter2pointO++;
                }
            }
            if (n4 == 0) {
                cases[counter_][counter2pointO] = j;
                counter2pointO++;
            }
        }
        if (n3 == 0) {
            cases[counter_][counter2pointO] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        array_printer(cases[i]);
    }
}