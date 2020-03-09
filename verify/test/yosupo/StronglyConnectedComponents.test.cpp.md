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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/yosupo/StronglyConnectedComponents.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/StronglyConnectedComponents.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 20:54:23+09:00


* see: <a href="https://judge.yosupo.jp/problem/scc">https://judge.yosupo.jp/problem/scc</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/GraphTheory/StronglyConnectedComponents.cpp.html">GraphTheory/StronglyConnectedComponents.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include<bits/stdc++.h>
using namespace std;

#include "../../GraphTheory/StronglyConnectedComponents.cpp"

int main() {
	int n, m; cin >> n >> m;
	StronglyConnectedComponents scc(n);
	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		scc.addEdge(a, b);
	}
	scc.build();
	vector<int> ans[n];
	int k = 0;
	for(int i = 0; i < n; ++i) {
		const int idx = scc.get(i);
		ans[idx].push_back(i);
		k = max(k, idx + 1);
	}
	cout << k << '\n';
	for(int i = 0; i < k; ++i) {
		cout << ans[i].size();
		for(const int j : ans[i]) {
			cout << " " << j;
		}
		cout << '\n';
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/StronglyConnectedComponents.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include<bits/stdc++.h>
using namespace std;

#line 1 "test/yosupo/../../GraphTheory/StronglyConnectedComponents.cpp"
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
#line 6 "test/yosupo/StronglyConnectedComponents.test.cpp"

int main() {
	int n, m; cin >> n >> m;
	StronglyConnectedComponents scc(n);
	for(int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		scc.addEdge(a, b);
	}
	scc.build();
	vector<int> ans[n];
	int k = 0;
	for(int i = 0; i < n; ++i) {
		const int idx = scc.get(i);
		ans[idx].push_back(i);
		k = max(k, idx + 1);
	}
	cout << k << '\n';
	for(int i = 0; i < k; ++i) {
		cout << ans[i].size();
		for(const int j : ans[i]) {
			cout << " " << j;
		}
		cout << '\n';
	}
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

