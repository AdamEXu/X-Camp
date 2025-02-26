#include <iostream>
#include <stack>
using namespace std;

bool isprime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i < n/2+1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(void) {
    int n;
    cin >> n;
    stack<int> primes;
    for (int i = 0; i <= n; i++) {
        if (isprime(i)) {
            primes.push(i);
        }
    }
    while (!primes.empty()) {
        cout << primes.top() << " ";
        primes.pop();
    }
    cout << endl;
}