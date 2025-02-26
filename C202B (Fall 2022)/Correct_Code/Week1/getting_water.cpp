#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Person {
    int i;
    int t;
    Person(int a, int b) {
        i=a;
        t=b;
    }
};

bool personsort (Person i, Person j) { if (i.t!=j.t) return (i.t<j.t); else return(i.i<j.i); }

int main(void) {    
    vector<Person> people;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        people.push_back(Person(i+1, t));
    }

    sort(people.begin(), people.end(), personsort);
    long long sumtotal = 0;
    for (int i = 0; i < n; i++) {
        sumtotal+=people[i].t * (n-i-1);
    }
    for (int i = 0; i < n; i++) {
        cout << people[i].i << " ";
    }
    cout << endl;
    cout << fixed;
    cout << setprecision(2);
    cout << double(sumtotal/double(n)) << endl;
}