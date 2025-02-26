#include <iostream>
using namespace std;

int main(void) {
  char correct[3][3], guess[3][3];
  int green=0, yellow=0, gascii[27] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, cascii[27] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> correct[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> guess[i][j];
      if (correct[i][j] == guess[i][j]) {
        green++;
        correct[i][j] = '@';
        guess[i][j] = '@';
      }
      cascii[int(correct[i][j])-'@']++;
      gascii[int(guess[i][j])-'@']++; 
    }
  }
  for (int i = 1; i < 27; i++){
    if (gascii[i] <= cascii[i]) {
      yellow += gascii[i];
    }
  }
  cout << green << endl;
  cout << yellow << endl;
}