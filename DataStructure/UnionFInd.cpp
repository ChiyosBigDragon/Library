#include <bits/stdc++.h>
using namespace std;

// BEGIN CUT HERE
struct UnionFind {
	using uint = uint_fast32_t;
	const uint V;
	// par[x] := xのroot
	vector<uint> par;
	// sz[x] := xを含む集合のサイズ
	vector<uint> sz;
	UnionFind(const uint V) : V(V), par(vector<uint>(V)), sz(vector<uint>(V, 1)) {
		iota(par.begin(), par.end(), 0);
	}
	// xとyを結合
	bool unite(uint x, uint y) {
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
	uint root(const uint x) {
		if(par[x] == x) {
			return x;
		}
		return (par[x] = root(par[x]));
	}
	// xとyが同じ集合か
	bool same(const uint x, const uint y) {
		return (root(x) == root(y));
	}
	// xが属する集合のサイズ
	uint size(const uint x) {
		return sz[root(x)];
	}
};
// END CUT HERE