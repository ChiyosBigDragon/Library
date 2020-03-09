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


# :heavy_check_mark: GraphTheory/StronglyConnectedComponents.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f381732df2a59e8e35d7811ba3c2868c">GraphTheory</a>
* <a href="{{ site.github.repository_url }}/blob/master/GraphTheory/StronglyConnectedComponents.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 20:54:23+09:00




## Required by

* :heavy_check_mark: <a href="TwoSatisfiability.cpp.html">GraphTheory/TwoSatisfiability.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/StronglyConnectedComponents.test.cpp.html">test/yosupo/StronglyConnectedComponents.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/TwoSatisfiability.test.cpp.html">test/yosupo/TwoSatisfiability.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

// BEGIN CUT HERE
struct StronglyConnectedComponents {
	const int V;
	vector<vector<int>> G, revG;
	vector<int> id;
	StronglyConnectedComponents(const int V) : V(V), G(vector<vector<int>>(V, vector<int>())), revG(vector<vector<int>>(V, vector<int>())), id(vector<int>(V)) {}
	// 有向辺を追加
	void addEdge(const int from, const int to) {
		G[from].push_back(to);
		revG[to].push_back(from);
	}
	// SCC
	void build() {
		vector<bool> used(V, false);
		stack<int> st;
		for(int from = 0; from < V; ++from) {
			if(not used[from]) {
				dfs(from, used, st);
			}
		}
		int num = 0;
		while(not st.empty()) {
			const int from = st.top();
			st.pop();
			if(used[from]) {
				revdfs(from, num, used);
				++num;
			}
		}
	}
	// xの属する集合ID
	int get(const int x) const {
		return id[x];
	}

	private:
	void dfs(const int from, vector<bool>& used, stack<int>& st) {
		used[from] = true;
		for(const int to : G[from]) {
			if(not used[to]) {
				dfs(to, used, st);
			}
		}
		st.push(from);
	}
	void revdfs(const int from, int num, vector<bool>& used) {
		used[from] = false;
		id[from] = num;
		for(const int to : revG[from]) {
			if(used[to]) {
				revdfs(to, num, used);
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
#line 1 "GraphTheory/StronglyConnectedComponents.cpp"
#include <bits/stdc++.h>
using namespace std;

// BEGIN CUT HERE
struct StronglyConnectedComponents {
	const int V;
	vector<vector<int>> G, revG;
	vector<int> id;
	StronglyConnectedComponents(const int V) : V(V), G(vector<vector<int>>(V, vector<int>())), revG(vector<vector<int>>(V, vector<int>())), id(vector<int>(V)) {}
	// 有向辺を追加
	void addEdge(const int from, const int to) {
		G[from].push_back(to);
		revG[to].push_back(from);
	}
	// SCC
	void build() {
		vector<bool> used(V, false);
		stack<int> st;
		for(int from = 0; from < V; ++from) {
			if(not used[from]) {
				dfs(from, used, st);
			}
		}
		int num = 0;
		while(not st.empty()) {
			const int from = st.top();
			st.pop();
			if(used[from]) {
				revdfs(from, num, used);
				++num;
			}
		}
	}
	// xの属する集合ID
	int get(const int x) const {
		return id[x];
	}

	private:
	void dfs(const int from, vector<bool>& used, stack<int>& st) {
		used[from] = true;
		for(const int to : G[from]) {
			if(not used[to]) {
				dfs(to, used, st);
			}
		}
		st.push(from);
	}
	void revdfs(const int from, int num, vector<bool>& used) {
		used[from] = false;
		id[from] = num;
		for(const int to : revG[from]) {
			if(used[to]) {
				revdfs(to, num, used);
			}
		}
	}
};
// END CUT HERE

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

