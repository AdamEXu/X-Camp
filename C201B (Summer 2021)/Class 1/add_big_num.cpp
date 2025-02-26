#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(vector <int> myin) {
    for (int i = 0; i < myin.size(); i++) {
        cout << myin[i];
        if (i != myin.size()) {
            cout << ", ";
        }
    }
    cout << endl;
}

vector <int> convert_string_to_Intvec(string s1) {
    vector <int> a;
    for (int i = 0; i < s1.size(); i++) {
        a.push_back(s1[s1.size()-i-1]-'0');
    }
    return a;
}

// adds two int vectors together
vector <int> add_big_int(vector<int> a, vector<int> b) {
    int len1 = a.size();
    int len2 = b.size();
    int len3 = max(len1, len2)+1;

    while (a.size() < b.size()) {
        a.push_back(0);
    }
    while (a.size() > b.size()) {
        b.push_back(0);
    }

    vector <int> c;

    // Add the two vectors (a and b) together
    int carry = 0;
    for (int i = 0; i < len3-1; i++) {
        int sum = a[i] + b[i] + carry;
        // c.push_back(a[i] + b[i] + carry);
        carry = 0;
        if (sum >= 10) {
            carry = 1;
            c.push_back(sum-10);
        } else {
            c.push_back(sum);
        }
    }

    if (carry == 1) {
        c.push_back(1);
    }
    return c;
}

void print_vector(vector <int> myin) {
    for (int i = 0; i < myin.size(); i++) {
        cout << myin[i];
    }
    cout << endl;
}

// Add all elements of a vector together 
// and keep them to a single digiter int vector
vector <int> sum_all (vector <vector <int> > myin) {
    vector <int> mySum;   
    mySum.push_back(0);
    // mySum = add_big_int(mySum, myin[i]);
    for (int i = 0; i < myin.size(); i++) {
        mySum = add_big_int(mySum, myin[i]);
    }

    return mySum;
}

// Add all elements of a vector together 
// and keep them to a single digiter int vector
vector <int> sum_all_array (vector <int> myin[], int size) {
    vector <int> mySum;   
    mySum.push_back(0);
    // mySum = add_big_int(mySum, myin[i]);
    for (int i = 0; i < myin->size(); i++) {
        mySum = add_big_int(mySum, myin[i]);
    }

    return mySum;
}

vector <int> climb_stairs(int n, int k) {
	// base case n = 0  f(n) = 1
  	// base case n = 1 f(n) = 1


  // n = 2 f(n) = f(n-1) + f(n-2);
  // n = 3 f(n) = f(n-1) + f(n-2) + f(n-3)
  // n = n   f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(n-k)
  // 1) base case
  	if (n <= 1) {
    	vector <int> temp;
    	temp.push_back(1);
    	return temp;
  	}

    // n > 1
    vector <int> result[k];
    vector <int> resultEle1;
    vector <int> resultEle2;

    resultEle1.push_back(1);
    resultEle2.push_back(1);

    result[0] = resultEle1;
    result[1] = resultEle2;

    for (int i = 2; i <= n; i++){

       vector<int> temp = sum_all_array(result, k);
       
		if( i >= k){
            for(int j = 0; j<k; j++){
				result[j] = result[j+1];
			}
			result[k-1] = temp; 
         }
    }
    return result[k-1];
}



int main(void) {
    // Get 2 strings as input
    // print_vector(convert_string_to_Intvec("10"));

    // return 0;
    // string s1, s2, s3, s4;
    // cin >> s1 >> s2 >> s3 >> s4;
    // int len1 = s1.size();
    // int len2 = s2.size();
    // int len3 = max(len1, len2)+1;

    // Define the vectors
    // vector <int> a;
    // vector <int> b;
    // vector <int> c;
    // vector <int> d;

    // // Convert the strings to integer vectors 
    // a = convert_string_to_Intvec(s1);
    // b = convert_string_to_Intvec(s2);
    // c = convert_string_to_Intvec(s3);
    // d = convert_string_to_Intvec(s4);

    // vector <int> all[4];

    // // all.push_back(a);
    // // all.push_back(b);
    // // all.push_back(c);
    // // all.push_back(d);
	// all[0] = a;
	// all[1] = b;
	// all[2] = c;
	// all[3] = d;

    // for (int i = 0; i < all.size(); i++) {
    //     print_vector(all[i]);
    // }

    // vector <int> myout = sum_all_array(all, 4);
    // reverse(myout.begin(), myout.end());
    // print_vector(myout);

    // print_vector(add_big_int(a, b));
    int n;
    int k;
    cin >> n;
    cin >> k;
    if (k > n) {
        k = n;
    }

    // keep <= k elements
    //vector <int> countSteps[100];
	
    print_vector(climb_stairs(n, k));
}