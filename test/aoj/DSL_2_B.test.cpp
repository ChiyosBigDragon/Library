#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"
#include<bits/stdc++.h>
using namespace std;

#include "../../DataStructure/SegmentTree.cpp"

auto f = [](int64_t l, int64_t r) {
	return l + r;
};
constexpr int64_t e = 0;

int main() {
	int n, q; cin >> n >> q;
	SegmentTree<int64_t> seg(n, f, e);
	while(q--) {
		int com, x, y; cin >> com >> x >> y;
		if(com == 0) {
			seg.set(x - 1, seg[x - 1] + y);
		}
		if(com == 1) {
			cout << seg.get(x - 1, y) << '\n';
		}
	}
	return 0;
}