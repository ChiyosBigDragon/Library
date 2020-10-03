#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"
#include<bits/stdc++.h>
using namespace std;

#include "../../DataStructure/LazySegmentTree.cpp"

struct S {
	int64_t val;
	int64_t len;
};
auto f = [](S l, S r) {
	return S{l.val + r.val, l.len + r.len};
};
auto g = [](S l, int64_t r) {
	return S{l.len * r, l.len};
};
auto h = [](int64_t l, int64_t r) {
	return r;
};
constexpr S se = S{0, 1};
constexpr int64_t te = -1e9;

int main() {
	int64_t n, q; cin >> n >> q;
	LazySegmentTree<S, int64_t> seg(n, f, g, h, se, te);
	while(q--) {
		int t; cin >> t;
		if(t == 0) {
			int64_t l, r, x; cin >> l >> r >> x;
			seg.apply(l, r + 1, x);
		}
		if(t == 1) {
			int64_t l, r; cin >> l >> r;
			cout << seg.get(l, r + 1).val << '\n';
		}
	}
	return 0;
}
