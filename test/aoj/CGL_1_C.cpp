#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C"
#include<bits/stdc++.h>
using namespace std;

#include "../../Geometry/template.cpp"

using namespace geometry;
int main() {
	Point p0, p1; cin >> p0 >> p1;
	int q; cin >> q;
	while(q--) {
		Point p2; cin >> p2;
		int ret = ccw(p0, p1, p2);
		string ans;
		if(ret & CCW_COUNTER_CLOCKWISE) ans = "COUNTER_CLOCKWISE";
		if(ret & CCW_CLOCKWISE) ans = "CLOCKWISE";
		if(ret & CCW_ONLINE_BACK) ans = "ONLINE_BACK";
		if(ret & CCW_ONLINE_FRONT) ans = "ONLINE_FRONT";
		if(ret & CCW_ON_SEGMENT) ans = "ON_SEGMENT";
		cout << ans << '\n';
	}
	return 0;
}