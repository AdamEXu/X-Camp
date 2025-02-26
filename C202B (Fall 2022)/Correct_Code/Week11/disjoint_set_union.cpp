#include <iostream>
using namespace std;
 
int set[10001] = { 0 };
int s[10001] = { 0 };
 
int get(int x) {
  if(set[x] == 0) return x;
  return set[x] = get(set[x]);
}
 
//unite by rank
void unite(int a, int b) {
  int x = get(a);
  int y = get(b);
  if (x != y) {
    if(s[x] == s[y]) {
      set[x] = y;
      s[y]++;
    }
    else if (s[x] < s[y])
      set[x] = y;
    else
      set[y] = x;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  int zi, xi, yi;
  char ans[m];
  int ansit = 0;
  for(int i = 0; i < m; i++) {
    cin >> zi >> xi >> yi;
    if(zi == 2) {
      if(get(xi) == get(yi)) ans[ansit] = 'Y';
      else ans[ansit] = 'N';
      ansit++;
    }
    else if (zi==1) {
      unite(xi, yi);
    }
  }
  for(int i = 0; i < ansit; i++) {
    printf("%c \n", ans[i]);
  }
}