#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A"
#include<bits/stdc++.h>
using namespace std;

#include "../../Geometry/template.cpp"

using namespace geometry;
int main() {
	int q; cin >> q;
	while(q--) {
		Point p[4];
		for(int i = 0; i < 4; ++i) cin >> p[i];
		Line s1(p[0], p[1]);
		Line s2(p[2], p[3]);
		int ans = 0;
		if(parallel(s1, s2)) ans = 2;
		if(orthogonal(s1, s2)) ans = 1;
		cout << ans << '\n';
	}
	return 0;
}