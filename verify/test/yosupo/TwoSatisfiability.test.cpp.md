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


# :heavy_check_mark: test/yosupo/TwoSatisfiability.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/TwoSatisfiability.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 22:24:18+09:00


* see: <a href="https://judge.yosupo.jp/problem/two_sat">https://judge.yosupo.jp/problem/two_sat</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/GraphTheory/StronglyConnectedComponents.cpp.html">GraphTheory/StronglyConnectedComponents.cpp</a>
* :heavy_check_mark: <a href="../../../library/GraphTheory/TwoSatisfiability.cpp.html">GraphTheory/TwoSatisfiability.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include<bits/stdc++.h>
using namespace std;

#include "../../GraphTheory/TwoSatisfiability.cpp"

int main() {
	string p, cnf; cin >> p >> cnf;
	int n, m; cin >> n >> m;
	TwoSatisfiability sat(n);
	for(int i = 0; i < m; ++i) {
		int a, b, _0; cin >> a >> b >> _0;
		const bool apos = a > 0;
		const bool bpos = b > 0;
		a = abs(a);
		b = abs(b);
		--a, --b;
		sat.addOR(a, apos, b, bpos);
	}
	if(not sat.solve()) {
		cout << "s UNSATISFIABLE" << '\n';
		return 0;
	}
	cout << "s SATISFIABLE" << '\n';
	cout << "v ";
	for(int i = 0; i < n; ++i) {
		cout << (sat.get(i) ? i + 1 : -(i + 1)) << " ";
	}
	cout << 0 << '\n';
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/TwoSatisfiability.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include<bits/stdc++.h>
using namespace std;

#line 2 "GraphTheory/TwoSatisfiability.cpp"
using namespace std;

#line 2 "GraphTheory/StronglyConnectedComponents.cpp"
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

// BEGIN CUT HERE
struct TwoSatisfiability {
	const int V;
	// pos[x] := xの真偽値
	vector<bool> pos;
	StronglyConnectedComponents scc;
	TwoSatisfiability(const int V) : V(V), pos(vector<bool>(2 * V)), scc(StronglyConnectedComponents(2 * V)) {}
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
		addIF(A, not Apos, B, Bpos); // not A -> B
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
	void addXNOR(const int A, const bool Apos, const int B, const bool Bpos) {
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
	private:
	constexpr int NOT(const int A) const {
		return (A + V) % (2 * V);
	}
};
// END CUT HERE
#line 6 "test/yosupo/TwoSatisfiability.test.cpp"

int main() {
	string p, cnf; cin >> p >> cnf;
	int n, m; cin >> n >> m;
	TwoSatisfiability sat(n);
	for(int i = 0; i < m; ++i) {
		int a, b, _0; cin >> a >> b >> _0;
		const bool apos = a > 0;
		const bool bpos = b > 0;
		a = abs(a);
		b = abs(b);
		--a, --b;
		sat.addOR(a, apos, b, bpos);
	}
	if(not sat.solve()) {
		cout << "s UNSATISFIABLE" << '\n';
		return 0;
	}
	cout << "s SATISFIABLE" << '\n';
	cout << "v ";
	for(int i = 0; i < n; ++i) {
		cout << (sat.get(i) ? i + 1 : -(i + 1)) << " ";
	}
	cout << 0 << '\n';
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

