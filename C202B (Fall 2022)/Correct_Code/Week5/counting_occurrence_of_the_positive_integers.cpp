#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int main(void) {
    map<int, int> numbers;
    int n;
    scanf("%d", &n);
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (numbers.count(num) == 0) {
            numbers[num] = 1;
        } else {
            numbers[num]++;
        }
    }
    for (map<int, int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        printf("%d %d\n", it->first, it->second);
    }
}