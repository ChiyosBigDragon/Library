#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include<bits/stdc++.h>
using namespace std;

#include "../../GraphTheory/LowestCommonAncestor.cpp"

int main() {
	int n, q; cin >> n >> q;
	LowestCommonAncestor lca(n);
	for(int i = 1; i <= n - 1; ++i) {
		int p; cin >> p;
		lca.addEdge(i, p);
	}
	lca.build();
	while(q--) {
		int u, v; cin >> u >> v;
		cout << lca.get(u, v) << '\n';
	}
	return 0;
}