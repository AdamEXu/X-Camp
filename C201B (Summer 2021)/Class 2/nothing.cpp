// Recursive program for Tower of Hanoi
#include
// Recursive function to solve Tower
// of Hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod,
char aux_rod1, char aux_rod2)
{
if (n == 0)
return;
if (n == 1) {
cout << "\n Move disk %d from rod %c to rod %c" << endl;;
return;
}

towerOfHanoi(n - 2, from_rod, aux_rod1, aux_rod2,to_rod);
printf("\n Move disk %d from rod %c to rod %c ",n - 1, from_rod, aux_rod2);
printf("\n Move disk %d from rod %c to rod %c ",n, from_rod, to_rod);
printf("\n Move disk %d from rod %c to rod %c ",n - 1, aux_rod2, to_rod);
towerOfHanoi(n - 2, aux_rod1, to_rod, from_rod,
aux_rod2);
}

// driver program
int main()
{
int n = 4; // Number of disks

// A, B, C and D are names of rods
towerOfHanoi(n, 'A', 'B', 'C', 'D');
return 0;
}