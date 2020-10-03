#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"
#include<bits/stdc++.h>
using namespace std;

#include "../../DataStructure/LazySegmentTree.cpp"

auto f = [](int64_t l, int64_t r) {
	return min(l, r);
};
auto g = [](int64_t l, int64_t r) {
	return l + r;
};
auto h = [](int64_t l, int64_t r) {
	return l + r;
};
constexpr int64_t se = 1e9;
constexpr int64_t te = 0;

int main() {
	int64_t n, q; cin >> n >> q;
	vector<int64_t> v(n, 0);
	LazySegmentTree<int64_t, int64_t> seg(v, f, g, h, se, te);
	while(q--) {
		int t; cin >> t;
		if(t == 0) {
			int64_t l, r, x; cin >> l >> r >> x;
			seg.apply(l, r + 1, x);
		}
		if(t == 1) {
			int64_t l, r; cin >> l >> r;
			cout << seg.get(l, r + 1) << '\n';
		}
	}
	return 0;
}
