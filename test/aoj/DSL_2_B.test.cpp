#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"
#include<bits/stdc++.h>
using namespace std;

#include "../../DataStructure/SegmentTree.cpp"

int f(int l, int r) {
	return l + r;
}
constexpr int e = 0;

int main() {
	int n, q; cin >> n >> q;
	SegmentTree<int, f, e> seg(n);
	while(q--) {
		int com, x, y; cin >> com >> x >> y;
		--x;
		if(com == 0) {
			seg.set(x, seg[x] + y);
		}
		if(com == 1) {
			cout << seg.get(x, y) << '\n';
		}
	}
	return 0;
}