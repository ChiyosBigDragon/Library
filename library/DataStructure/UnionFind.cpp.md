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


# :heavy_check_mark: DataStructure/UnionFind.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/UnionFind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 20:27:18+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/UnionFind.test.cpp.html">test/yosupo/UnionFind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/UnionFind.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

