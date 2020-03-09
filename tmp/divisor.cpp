#include <bits/stdc++.h>
using namespace std;

vector<int64_t> divisor(int64_t n) {
    vector<int64_t> ret;
    for(int64_t i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.emplace_back(i);
            if(i * i != n) ret.emplace_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}
