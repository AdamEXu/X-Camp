// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, tmp;
    cin >> n >> x;
    vector<pair<int, int> > nums;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        nums.push_back(make_pair(tmp, i));
    }
    sort(nums.begin(), nums.end());
    int i = 0, j = i+1, k = n - 1;
    while (i < n-2) {
        while (j < k) {
            if (nums[i].first + nums[j].first + nums[k].first > x) {
                k--;
            } else if (nums[i].first + nums[j].first + nums[k].first < x) {
                j++;
            } else {
                cout << nums[i].second+1 << " " << nums[j].second+1 << " " << nums[k].second+1 << endl;
                return 0;
            }
        }
        i++;
        j = i+1;
        k = n - 1;
    }
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}