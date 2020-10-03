#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"
#include<bits/stdc++.h>
using namespace std;

#include "../../DataStructure/LazySegmentTree.cpp"

auto f = [](int l, int r) {
	return min(l, r);
};
auto g = [](int l, int r) {
	return r;
};
auto h = [](int l, int r) {
	return r;
};
constexpr int se = (1ll << 31) - 1;
constexpr int te = -1;

int main() {
	int n, q; cin >> n >> q;
	LazySegmentTree<int, int> seg(n, f, g, h, se, te);
	while(q--) {
		int t; cin >> t;
		if(t == 0) {
			int l, r, x; cin >> l >> r >> x;
			seg.apply(l, r + 1, x);
		}
		if(t == 1) {
			int l, r; cin >> l >> r;
			cout << seg.get(l, r + 1) << '\n';
		}
	}
	return 0;
}