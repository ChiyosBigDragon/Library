#include <bits/stdc++.h>
using namespace std;

// BEGIN CUT HERE
struct UnionFind {
	const int V;
	// par[x] := xのroot
	vector<int> par;
	// sz[x] := xを含む集合のサイズ
	vector<int> sz;
	UnionFind(const int V) : V(V), par(vector<int>(V)), sz(vector<int>(V, 1)) {
		iota(par.begin(), par.end(), 0);
	}
	// xとyを結合
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if(same(x, y)) {
			return false;
		}
		if(y < x) {
			swap(x, y);
		}
		par[y] = x;
		sz[x] += sz[y];
		return true;
	}
	// xの集合ID
	int root(const int x) {
		if(par[x] == x) {
			return x;
		}
		return (par[x] = root(par[x]));
	}
	// xとyが同じ集合か
	bool same(const int x, const int y) {
		return (root(x) == root(y));
	}
	// xが属する集合のサイズ
	int size(const int x) {
		return sz[root(x)];
	}
};
// END CUT HERE