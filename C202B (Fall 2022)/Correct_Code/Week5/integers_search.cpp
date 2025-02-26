#include <iostream>
#include <set>
#include <stdio.h>
using namespace std;

int main(void) {
    set<int> numbers;
    int n;
    scanf("%d", &n);
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (numbers.count(num) == 0) {
            printf("accepted\n");
            numbers.insert(num);
        } else {
            printf("ignored\n");
        }
    }
}