#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include<bits/stdc++.h>
using namespace std;

#include "../../Math/ModInt.cpp"
#include "../../DataStructure/SegmentTree.cpp"

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;
struct S {
	mint a;
	mint b;
};
auto f = [](S l, S r) {
	return S{l.a * r.a, l.b * r.a + r.b};
};
const S e{1, 0};

int main() {
	int n, q; cin >> n >> q;
	vector<S> v(n);
	for(int i = 0; i < n; ++i) {
		int a, b; cin >> a >> b;
		v[i] = S{a, b};
	}
	SegmentTree<S> seg(v, f, e);
	while(q--) {
		int t; cin >> t;
		if(t == 0) {
			int p, c, d; cin >> p >> c >> d;
			seg.set(p, S{c, d});
		}
		if(t == 1) {
			int l, r, x; cin >> l >> r >> x;
			S s = seg.get(l, r);
			cout << s.a * x + s.b << '\n';
		}
	}
	return 0;
}
