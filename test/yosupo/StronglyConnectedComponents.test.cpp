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