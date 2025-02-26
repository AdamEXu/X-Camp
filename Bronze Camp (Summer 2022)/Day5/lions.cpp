// Solution provided by Adam Xu (@Adam The Great#0323 on Discord)

#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

// Roar! James the lion is hungry! He sees Bessie the cow and wants to eat her!

// Luckily, Bessie finds out before it's too late. Bessie does some calculations and manages to retrieve a list of N (0 ≤ N ≤ 10000) words that James is scared of. Each word consists of only lowercase letters. Words have a maximum length of 8. Sadly however, Bessie has an accent and can only properly pronounce M (0 ≤ M ≤ 26) letters.

// Please find out the maximum amount of words Bessie can pronounce that James is scared of

// INPUT FORMAT:
// First line contains 2 numbers, N and M.

// Next N lines contains the words James is scared of.

// OUTPUT FORMAT:
// Please output the maximum amount of words that Bessie can pronounce, given the amount of letters she can pronounce.

int main(void) {
    // solution for the problem above

}

// int main(void) {
//     int n, m;
//     cin >> n >> m;
//     vector<string> words;
//     set<char> letters;
//     for (int i = 0; i < n; i++) {
//         string word;
//         cin >> word;
//         words.push_back(word);
//     }
//     for (int i = 0; i < m; i++) {
//         char letter;
//         cin >> letter;
//         letters.insert(letter);
//     }
//     int counter = 0;
//     for (int i = 0; i < n; i++) {
//         bool canbemade = true;
//         for (int j = 0; j < words[i].size(); j++) {
//             if (letters.count(words[i][j]) == 0) {
//                 canbemade = false;
//                 break;
//             }
//         }
//         if (canbemade) {
//             counter++;
//         }
//     }
//     cout << counter << endl;
// }