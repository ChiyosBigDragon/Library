#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"
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
	return S{l.val + l.len * r, l.len};
};
auto h = [](int64_t l, int64_t r) {
	return l + r;
};
constexpr S se{0, 1};
constexpr int64_t te = 0;

int main() {
	int n, q; cin >> n >> q;
	LazySegmentTree<S, int64_t> seg(n, f, g, h, se, te);
	while(q--) {
		int t; cin >> t;
		if(t == 0) {
			int l, r, x; cin >> l >> r >> x;
			seg.apply(l - 1, r, x);
		}
		if(t == 1) {
			int l, r; cin >> l >> r;
			cout << seg.get(l - 1, r).val << '\n';
		}
	}
	return 0;
}