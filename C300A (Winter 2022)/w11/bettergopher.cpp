#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main() {
  int n, temp, ans = 0;
  cin >> n;
  vector<pair<int, int> > gophers (n, make_pair(0, 0));
  for(int i = 0; i < n; ++i) {
    cin >> temp;
    gophers[i].second = temp;
  }
  for(int i = 0; i < n; ++i) {
    cin >> temp;
    gophers[i].first = temp;
  }
  set<int> time;
  sort(gophers.begin(), gophers.end());
  for(int i = n; i >= 0; --i) {
    for(int j = gophers[i].second; j >= 1; --j) {
      if(time.count(j) == 0) {
        time.insert(j);
        ans += gophers[i].first;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}