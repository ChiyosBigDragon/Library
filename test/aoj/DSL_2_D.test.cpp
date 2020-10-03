#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"
#include<bits/stdc++.h>
using namespace std;

#include "../../DataStructure/LazySegmentTree.cpp"

auto f = [](int l, int r) {
	return l;
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
			int i; cin >> i;
			cout << seg.get(i) << '\n';
		}
	}
	return 0;
}