---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: GraphTheory/LowestCommonAncestor.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f381732df2a59e8e35d7811ba3c2868c">GraphTheory</a>
* <a href="{{ site.github.repository_url }}/blob/master/GraphTheory/LowestCommonAncestor.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-10 14:31:49+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/LowestCommonAncestor.test.cpp.html">test/yosupo/LowestCommonAncestor.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "GraphTheory/LowestCommonAncestor.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

