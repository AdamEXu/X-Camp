#include<iostream>
#include<list> // for list functions
using namespace std;

Class BigInteger {

    private list<int> big_value;

     

};

int count_stairs(list<int> results, int n, int k){

    // base case
    if(n == 0 or n == 1){
        return 1;
    }

    for (int i = 0; i <= n; i++){
        
        if ( i == 0 or i == 1){
            results.push_back(1);
        }
        else{
            // Add all the elements in the list
            int sum = 0;
            for (auto it = results.crbegin(); it != results.crend(); ++it){
                sum += *it;
            }
            cout << "i = " << i << "; sum = " << sum << endl;
            results.push_back(sum);
            if (results.size() > k)
                results.pop_front();
        }
 
    }
    int lastEle = results.back();
    cout << "last Element = " << lastEle << endl;
    return lastEle;
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;

    if(n == 0 or n == 1){
        return 1;
    }
    // Declaring a list
    list<int> results;

    int my_count = count_stairs(results, n, k);

    return my_count;
}