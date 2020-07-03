#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_A"
#include<bits/stdc++.h>
using namespace std;

#include "../../Geometry/template.cpp"

using namespace geometry;
int main() {
	int n; cin >> n;
	vector<Point> p(n);
	for(int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	vector<Point> ch = convexHull(p);
	cout << ch.size() << '\n';
	for(Point& e : ch) {
		cout << (int)e.real() << " " << (int)e.imag() << '\n';
	}
	return 0;
}
