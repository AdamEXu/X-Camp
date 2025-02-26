#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    queue<int> books;
    for (int i = 0; i < n; i++) {
        int book;
        cin >> book;
        books.push(book);
    }
    queue<int> order;
    for (int i = 0; i < n; i++) {
        int book;
        cin >> book;
        order.push(book);
    }
    bool bag[n];
    for (int i = 0; i < n; i++) {
        bag[i] = false;
    }
    while (!order.empty()) {
        int curr = order.front();
        order.pop();
        int bookstaken = 0;
        if (bag[curr-1] || books.empty()) {
            cout << 0 << " ";
            continue;
        }
        while (books.front() != curr) {
            // cout << books.front() << " ";
            bookstaken++;
            bag[books.front()-1] = true;
            books.pop();
        }
        // cout << books.front() << " ";
        bookstaken++;
        bag[books.front()-1] = true;
        books.pop();
        cout << bookstaken << " ";
    }
    cout << endl;
}