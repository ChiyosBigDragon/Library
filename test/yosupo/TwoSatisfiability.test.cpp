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