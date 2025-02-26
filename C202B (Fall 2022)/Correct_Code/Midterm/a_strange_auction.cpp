#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
  
int arr[1000000];
int w,p,a,b;
  
  
long long dfs(int cur) {
  if(cur < p) {
    return 0;
  }
  if(cur == p) {
    return 1;
  }
  
  if(arr[cur] != 0) {
    return arr[cur];
  }
  else {
    arr[cur] = dfs(cur -a) + dfs(cur -b);
  }
  
  return arr[cur];
}
  
int main() {
  cin >> w >> p >> a >> b;
  memset(arr, 0, sizeof(arr));
  
  cout << dfs(w) << endl;
}