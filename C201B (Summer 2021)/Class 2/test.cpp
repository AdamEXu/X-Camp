int counter = 0;
// Recursive program for Tower of Hanoi
#include <iostream>
using namespace std;
// Recursive function to solve Tower
// of Hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod1, char aux_rod2)
{
    if (n == 0)
    return;
    if (n == 1) {
        cout << "\nMove disk " << n << " from rod " << from_rod << " to rod " << to_rod;
    return;
    }

    towerOfHanoi((n - 2), from_rod, aux_rod1, aux_rod2, to_rod);
    cout << "\nMove disk " << n-1 << " from rod " << from_rod << " to rod " << aux_rod2;
    
    cout << "\nMove disk " << n << " from rod " << from_rod << " to rod " << to_rod;
    
    cout << "\nMove disk " << n-1 << " from rod " << aux_rod2 << " to rod " << to_rod;
    
    towerOfHanoi((n - 2), aux_rod1, to_rod, from_rod, aux_rod2);
}

// driver program
int main()
{
    int n; // Number of disks
    cin >> n;
    // A, B, C and D are names of rods
    towerOfHanoi(n, 'A', 'D', 'B', 'C');
    cout << endl;
    return 0;
    
}