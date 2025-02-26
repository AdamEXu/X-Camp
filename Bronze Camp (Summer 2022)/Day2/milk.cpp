#include <iostream>
#include <algorithm>
using namespace std;

// Pour function by hongkang zhao
void pour(int &bucket1, int &max2, int &bucket2) {
    int amount = min(bucket1, max2 - bucket2);
    bucket1-=amount;
    bucket2+=amount;
}

int main() {
    int max1, max2, max3;
    int bucket1, bucket2, bucket3;
    cin >> max1 >> bucket1 >> max2 >> bucket2 >> max3 >> bucket3;

    for (int i = 0; i < 33; i++) {
        pour(bucket1, max2, bucket2);
        pour(bucket2, max3, bucket3);
        pour(bucket3, max1, bucket1);
    }
    pour(bucket1, max2, bucket2);

    cout << bucket1 << endl << bucket2 << endl << bucket3 << endl;
}