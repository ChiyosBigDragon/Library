#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_A"
#define ERROR "1e-8"
#include<bits/stdc++.h>
using namespace std;

#include "../../Geometry/template.cpp"

using namespace geometry;
int main() {
	Point p1, p2; cin >> p1 >> p2;
	int q; cin >> q;
	while(q--) {
		Point p; cin >> p;
		cout << projection(p - p1, p2 - p1) + p1 << '\n';
	}
	return 0;
}