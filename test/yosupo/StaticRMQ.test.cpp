#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include<bits/stdc++.h>
using namespace std;

#include "../../DataStructure/SegmentTree.cpp"

int f(int l, int r) {
	return min(l, r);
}
constexpr int e = 1e9 + 7;

int main() {
	int n, q; cin >> n >> q;
	vector<int> a(n); for(int& i : a) cin >> i;
	SegmentTree<int, f, e> seg(a);
	while(q--) {
		int l, r; cin >> l >> r;
		cout << seg.get(l, r) << '\n';
	}
	return 0;
}