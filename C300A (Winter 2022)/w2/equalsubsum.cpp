#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;
    set<int> thesetofgreatnessyesimakethebestvariablenameshahanowtrydebuggingthiscodelolhehe;
    vector<int> prefixsums (n+1, 0);
    int count = 0, tmp, comp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        prefixsums[i] = prefixsums[i-1]+tmp;
        comp = x - tmp;
        thesetofgreatnessyesimakethebestvariablenameshahanowtrydebuggingthiscodelolhehe.insert(comp);
        if (thesetofgreatnessyesimakethebestvariablenameshahanowtrydebuggingthiscodelolhehe.count(prefixsums[i])) {
            count++;
            // thesetofgreatnessyesimakethebestvariablenameshahanowtrydebuggingthiscodelolhehe.erase(prefixsums[i]);
        }
    }
    cout << count << endl;
}