#include <bits/stdc++.h>
using namespace std;

// BEGIN CUT HERE
struct LowestCommonAncestor {
	const int DEPTH_MAX = 30;
	const int V;
	const int root;
	vector<vector<int>> edge;
	vector<int> depth;
	vector<vector<int>> par;
	LowestCommonAncestor(const int V, const int root = 0) : V(V), root(root), edge(vector<vector<int>>(V, vector<int>())), depth(vector<int>(V)), par(vector<vector<int>>(V, vector<int>(DEPTH_MAX, root))) {}
	LowestCommonAncestor(const int V, const vector<vector<int>>& edge, const int root = 0) : V(V), edge(edge), root(root), depth(vector<int>(V)), par(vector<vector<int>>(V, vector<int>(DEPTH_MAX, root))) {
		build();
	}
	void addEdge(const int from, const int to) {
		edge[from].push_back(to);
		edge[to].push_back(from);
	}
	void build() {
		dfs(root, root, 0);
		doubling();
	}
	// lとrの共通祖先
	int get(int l, int r) {
		if(depth[l] < depth[r]) swap(l, r);
		int diff = depth[l] - depth[r];
		for(int i = 0; i < DEPTH_MAX; ++i) {
			if(diff >> i & 1) {
				l = par[l][i];
			}
		}
		if(l == r) {
			return l;
		}
		for(int i = DEPTH_MAX - 1; i >= 0; --i) {
			if(par[l][i] != par[r][i]) {
				l = par[l][i];
				r = par[r][i];
			}
		}
		return par[l][0];
	}
	
	private:
	void dfs(const int from, const int _par, const int d) {
		depth[from] = d;
		par[from][0] = _par;
		for(const int to : edge[from]) {
			if(to == _par) continue;
			dfs(to, from, d + 1);
		}
	}
	void doubling() {
		for(int j = 1; j < DEPTH_MAX; ++j) {
			for(int i = 0; i < V; ++i) {
				par[i][j] = par[par[i][j - 1]][j - 1];
			}
		}
	}
};
// END CUT HERE
