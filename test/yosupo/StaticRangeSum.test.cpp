#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include<bits/stdc++.h>
using namespace std;

#include "../../DataStructure/SegmentTree.cpp"

int64_t f(int64_t l, int64_t r) {
	return l + r;
}
constexpr int64_t e = 0;

int main() {
	int64_t n, q; cin >> n >> q;
	vector<int64_t> a(n); for(int64_t& i : a) cin >> i;
	SegmentTree<int64_t, f, e> seg(a);
	while(q--) {
		int64_t l, r; cin >> l >> r;
		cout << seg.get(l, r) << '\n';
	}
	return 0;
}