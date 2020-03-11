#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_B"
#include<bits/stdc++.h>
using namespace std;

#include "../../Geometry/template.cpp"

using namespace geometry;
int main() {
	int q; cin >> q;
	while(q--) {
		Point p[4];
		for(int i = 0; i < 4; ++i) cin >> p[i];
		Segment s1(p[0], p[1]);
		Segment s2(p[2], p[3]);
		cout << intersect(s1, s2) << '\n';
	}
	return 0;
}
