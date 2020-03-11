#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A"
#include<bits/stdc++.h>
using namespace std;

#include "../../Geometry/template.cpp"

using namespace geometry;
int main() {
	int n; cin >> n;
	vector<Point> p(n);
	for(int i = 0; i < n; ++i) cin >> p[i];
	cout << fixed << setprecision(1) << area(p) << '\n';
	return 0;
}