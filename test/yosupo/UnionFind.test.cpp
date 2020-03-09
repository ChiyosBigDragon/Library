#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../DataStructure/UnionFind.cpp"
#undef call_from_test

int main() {
	int n; cin >> n;
	UnionFind uf(n);
	int q; cin >> q;
	while(q--) {
		int t; cin >> t;
		int u, v; cin >> u >> v;
		if(t == 0) {
			uf.unite(u, v);
		}
		if(t == 1) {
			cout << uf.same(u, v) << '\n';
		}
	}
	return 0;
}