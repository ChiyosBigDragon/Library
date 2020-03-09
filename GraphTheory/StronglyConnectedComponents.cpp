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