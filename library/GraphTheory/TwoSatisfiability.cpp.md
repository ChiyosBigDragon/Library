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


# :warning: GraphTheory/TwoSatisfiability.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f381732df2a59e8e35d7811ba3c2868c">GraphTheory</a>
* <a href="{{ site.github.repository_url }}/blob/master/GraphTheory/TwoSatisfiability.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 21:04:12+09:00




## Depends on

* :heavy_check_mark: <a href="StronglyConnectedComponents.cpp.html">GraphTheory/StronglyConnectedComponents.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

#include "./StronglyConnectedComponents.cpp"

struct TwoSatisfiability {
	const int V;
	vector<bool> pos;
	StronglyConnectedComponents scc;
	TwoSatisfiability(const int V) : V(V), pos(vector<bool>(2 * V)), scc(StronglyConnectedComponents(2 * V)) {}
	constexpr int NOT(const int A) const {
		return (A + V) % (2 * V);
	}
	// A -> B <=> not B -> not A
	inline void addIF(int A, const bool Apos, int B, const bool Bpos) {
		if(not Apos) A = NOT(A);
		if(not Bpos) B = NOT(B);
		scc.addEdge(A, B); // A -> B
		scc.addEdge(NOT(B), NOT(A)); // not B -> not A
	}
	// A <=> (not A -> A)
	void addUNARY(const int A, const bool Apos) {
		addIF(A, not Apos, A, Apos); // not A -> A
	}
	// A or B <=> not A -> B
	void addOR(const int A, const bool Apos, const int B, const bool Bpos) {
		addIF(A, not Apos, B, not Bpos); // not A -> B
	}
	// not(A and B) => A -> not B
	void addNAND(const int A, const bool Apos, const int B, const bool Bpos) {
		addIF(A, Apos, B, not Bpos); // A -> not B
	}
	// A xor B <=> not(A and B) and not(not A and not B)
	void addXOR(const int A, const bool Apos, const int B, const bool Bpos) {
		addNAND(A, Apos, B, Bpos); // not(A and B)
		addNAND(A, not Apos, B, not Bpos); // not(not A and not B)
	}
	// not(A xor B) <=> A xor not B
	void addXNOR(int A, bool Apos, int B, bool Bpos) {
		addXOR(A, Apos, B, not Bpos); // A xor not B
	}
	bool solve() {
		scc.build();
		for(int i = 0; i < V; ++i) {
			if(scc.get(i) == scc.get(i + V)) {
				return false;
			}
			pos[i] = (scc.get(i) > scc.get(i + V));
		}
		return true;
	}
	bool get(int x) {
		return pos[x];
	}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "GraphTheory/TwoSatisfiability.cpp"
#include <bits/stdc++.h>
using namespace std;

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
#line 5 "GraphTheory/TwoSatisfiability.cpp"

struct TwoSatisfiability {
	const int V;
	vector<bool> pos;
	StronglyConnectedComponents scc;
	TwoSatisfiability(const int V) : V(V), pos(vector<bool>(2 * V)), scc(StronglyConnectedComponents(2 * V)) {}
	constexpr int NOT(const int A) const {
		return (A + V) % (2 * V);
	}
	// A -> B <=> not B -> not A
	inline void addIF(int A, const bool Apos, int B, const bool Bpos) {
		if(not Apos) A = NOT(A);
		if(not Bpos) B = NOT(B);
		scc.addEdge(A, B); // A -> B
		scc.addEdge(NOT(B), NOT(A)); // not B -> not A
	}
	// A <=> (not A -> A)
	void addUNARY(const int A, const bool Apos) {
		addIF(A, not Apos, A, Apos); // not A -> A
	}
	// A or B <=> not A -> B
	void addOR(const int A, const bool Apos, const int B, const bool Bpos) {
		addIF(A, not Apos, B, not Bpos); // not A -> B
	}
	// not(A and B) => A -> not B
	void addNAND(const int A, const bool Apos, const int B, const bool Bpos) {
		addIF(A, Apos, B, not Bpos); // A -> not B
	}
	// A xor B <=> not(A and B) and not(not A and not B)
	void addXOR(const int A, const bool Apos, const int B, const bool Bpos) {
		addNAND(A, Apos, B, Bpos); // not(A and B)
		addNAND(A, not Apos, B, not Bpos); // not(not A and not B)
	}
	// not(A xor B) <=> A xor not B
	void addXNOR(int A, bool Apos, int B, bool Bpos) {
		addXOR(A, Apos, B, not Bpos); // A xor not B
	}
	bool solve() {
		scc.build();
		for(int i = 0; i < V; ++i) {
			if(scc.get(i) == scc.get(i + V)) {
				return false;
			}
			pos[i] = (scc.get(i) > scc.get(i + V));
		}
		return true;
	}
	bool get(int x) {
		return pos[x];
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

