#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
 
// 1 -2
//
 
int eval(string inp) {
 
  int nummode = 0;
  int currentnum = 0;
  stack<int> nums;
  stack<char> ops;
  for (char i : inp) {
    if ('0' <= i && i <= '9') {
      // i is a number
      if (nummode > 0) {
        currentnum *= pow(10, nummode);
      }
      currentnum += i - '0';
    }
    else if (i == ' ') {
      nummode+=1;
      continue;
    }
    else {
      nums.push(currentnum);
       
      nummode = 0;
      currentnum = 0;
      if (ops.size() > 0 && nums.size() >= 2) {
        int op1 = nums.top();
        nums.pop();
        int op2 = nums.top();
        nums.pop();
 
        char optr = ops.top();
        ops.pop();
 
        if (optr == '-') {
          nums.push(op2 - op1);
        } else {
          nums.push(op2 + op1);
        }
      }
      ops.push(i);
         
    }
  }
  nums.push(currentnum);
 
  while (!ops.empty()) {
    int op1 = nums.top();
    nums.pop();
    int op2 = nums.top();
    nums.pop();
 
    char optr = ops.top();
    ops.pop();
 
    if (optr == '-') {
      nums.push(op2 - op1);
    } else {
      nums.push(op2 + op1);
    }
  };
 
  int res = nums.top();
  return res;
}
 
 
void solve(string seq, int currentpos) {
  if (currentpos >= seq.size()) {
    if (eval(seq) == 0) {
      cout << seq << "\n";
    }
    return;
  }
 
  string spacestring = seq;
  spacestring.insert(currentpos, 1, ' ');
  solve(spacestring, currentpos + 2);
   
  string plusstring = seq;
  plusstring.insert(currentpos, 1, '+');
  solve(plusstring, currentpos + 2);
 
  string minusstring = seq;
  minusstring.insert(currentpos, 1, '-');
  solve(minusstring, currentpos + 2);
 
   
  return;
}
 
 
 
int main() {
  int rangetop;
  scanf("%d", &rangetop);
 
  string sequence;
   
  for (int i = 1; i<=rangetop; i++) {
    sequence.push_back((char) i + '0');
  }
  // for (int i = 1; i<sequence.size(); i+=2) {
  //   sequence.insert(i, 1, ' ');
  // }
   
  solve(sequence, 1);
 
}