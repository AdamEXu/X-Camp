#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    vector<long long> prefix (n+1, 0), nums(n), leastsofar(n);
    for (long long i = 0; i < n; ++i) {
        cin >> nums[i];
        prefix[i+1] = prefix[i] + nums[i];
    }
    for (long long i = 0; i < n; ++i) {
        if (i == 0) leastsofar[i] = nums[i];
        else leastsofar[i] = min(leastsofar[i-1], nums[i]);
    }
    float maxscore = 0;
    vector<float> scores(n);
    for (long long i = 0; i < n-1; ++i) {
        float score = (prefix[n] - prefix[i] - leastsofar[i]) / (float) (n-i-1);
        if (score >= maxscore) {
            maxscore = score;
        }
        scores[i] = score;
    }
    for (long long i = 0; i < n-1; ++i) {
        if (scores[i] == maxscore) {
            cout << i << '\n';
        }
    }
}