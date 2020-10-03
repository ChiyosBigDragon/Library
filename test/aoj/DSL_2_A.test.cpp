#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"
#include<bits/stdc++.h>
using namespace std;

#include "../../DataStructure/SegmentTree.cpp"

auto f = [](int l, int r) {
	return min(l, r);
};
constexpr int e = (1ll << 31) - 1;

int main() {
	int n, q; cin >> n >> q;
	SegmentTree<int> seg(n, f, e);
	while(q--) {
		int com, x, y; cin >> com >> x >> y;
		if(com == 0) {
			seg.set(x, y);
		}
		if(com == 1) {
			cout << seg.get(x, y + 1) << '\n';
		}
	}
	return 0;
}
