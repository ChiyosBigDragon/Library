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


# :heavy_check_mark: test/aoj/CGL_1_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/CGL_1_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-03 22:28:13+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_B">https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Geometry/template.cpp.html">Geometry/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_B"
#define ERROR "1e-8"
#include<bits/stdc++.h>
using namespace std;

#include "../../Geometry/template.cpp"

using namespace geometry;
int main() {
	Point p1, p2; cin >> p1 >> p2;
	Line l(p1, p2);
	int q; cin >> q;
	while(q--) {
		Point p; cin >> p;
		cout << reflection(p, l) << '\n';
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/CGL_1_B.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_B"
#define ERROR "1e-8"
#include<bits/stdc++.h>
using namespace std;

#line 2 "Geometry/template.cpp"
using namespace std;

// BEGIN CUT HERE
namespace geometry {
	using Real = double;
	using Point = complex<Real>;
	constexpr Real EPS = 1e-9;
	// 誤差を考慮した符号
	inline int sgn(const Real x) {
		return (x > EPS) - (x < -EPS);
	}
	// 誤差を考慮した l - r の符号
	inline int sgn(const Real l, const Real r) {
		return sgn(l - r);
	}
	struct Circle {
		Point p;
		Real r;
		Circle(const Point p, const Real r) : p(p), r(r) {}
	};
	struct Line {
		Point a, b;
		Line(const Point a, const Point b) : a(a), b(b) {}
	};
	struct Segment : Line {
		Segment(const Point a, const Point b) : Line(a, b) {}
	};
	// 内積
	inline Real dot(const Point& lhs, const Point& rhs) {
		return (conj(lhs) * rhs).real();
	}
	// 外積
	inline Real cross(const Point& lhs, const Point& rhs) {
		return (conj(lhs) * rhs).imag();
	}
	// a の b に対する正射影ベクトル
	inline Point projection(const Point& a, const Point& b) {
		return b * dot(a, b) / norm(b);
	}
	// 点pから直線lに下ろした垂線の足
	inline Point projection(const Point& p, const Line& l) {
		return projection(p - l.a, l.b - l.a) + l.a;
	}
	// 直線lを対称軸として点pと線対称な点
	inline Point reflection(const Point& p, const Line& l) {
		return p + (projection(p, l) - p) * 2.0;
	}
	// 反時計回り(a -> b -> c)
	static constexpr int CCW_COUNTER_CLOCKWISE = 0b00001;
	// 時計回り(a -> b -> c)
	static constexpr int CCW_CLOCKWISE = 0b00010;
	// 同一直線上(c -> a -> b)
	static constexpr int CCW_ONLINE_BACK = 0b00100;
	// 同一直線上(a -> b -> c, b on ac)
	static constexpr int CCW_ONLINE_FRONT = 0b01000;
	// 同一直線上(a -> c -> b)
	static constexpr int CCW_ON_SEGMENT = 0b10000;
	// 3点の位置関係
	inline int ccw(const Point& a, Point b, Point c) {
		b = b - a, c = c - a;
		if(sgn(cross(b, c)) > 0) return CCW_COUNTER_CLOCKWISE;
		if(sgn(cross(b, c)) < 0) return CCW_CLOCKWISE;
		if(dot(b, c) < 0) return CCW_ONLINE_BACK;
		if(norm(b) < norm(c)) return CCW_ONLINE_FRONT;
		return CCW_ON_SEGMENT;
	}
	// 平行判定
	inline bool parallel(const Line& l1, const Line& l2) {
		return sgn(cross(l1.a - l1.b, l2.a - l2.b)) == 0;
	}
	// 直交判定
	inline bool orthogonal(const Line& l1, const Line& l2) {
		return sgn(dot(l1.a - l1.b, l2.a - l2.b)) == 0;
	}
	// 直線と直線の交差判定
	inline bool intersect(const Line& l1, const Line& l2) {
		return not parallel(l1, l2);
	}
	// 線分と直線の交差判定
	inline bool intersect(const Segment& s, const Line& l) {
		constexpr int plus = CCW_COUNTER_CLOCKWISE | CCW_ONLINE_BACK;
		constexpr int minus = CCW_CLOCKWISE | CCW_ONLINE_FRONT;
		int f[2] = {ccw(l.a, l.b, s.a), ccw(l.a, l.b, s.b)};
		for(int i = 0; i < 2; ++i) {
			f[i] = (f[i] & plus) ? +1 : ((f[i] & minus) ? -1 : 0);
		}
		return (f[0] * f[1] <= 0);
	}
	// 線分と線分の交差判定
	inline bool intersect(const Segment& s1, const Segment& s2) {
		constexpr int plus = CCW_COUNTER_CLOCKWISE | CCW_ONLINE_BACK;
		constexpr int minus = CCW_CLOCKWISE | CCW_ONLINE_FRONT;
		int f[4] = {ccw(s1.a, s1.b, s2.a), ccw(s1.a, s1.b, s2.b), ccw(s2.a, s2.b, s1.a), ccw(s2.a, s2.b, s1.b)};
		for(int i = 0; i < 4; ++i) {
			f[i] = (f[i] & plus) ? +1 : ((f[i] & minus) ? -1 : 0);
		}
		return (f[0] * f[1] <= 0) and (f[2] * f[3] <= 0);
	}
	// 直線と直線の交点（要：交差判定）
	inline Point crossPoint(const Line& l1, const Line& l2) {
		assert(intersect(l1, l2));
		Point a = l1.b - l1.a;
		Point b = l2.b - l2.a;
		return l1.a + a * cross(b, l2.a - l1.a) / cross(b, a);
	}
	// 線分と線分の交点（要：交差判定）
	inline Point crossPoint(const Segment& s1, const Segment& s2) {
		assert(intersect(s1, s2));
		return crossPoint((Line)s1, (Line)s2);
	}
	// 円と円の交点
	vector<Point> crossPoint(const Circle& c1, const Circle& c2) {
		const Real dist = abs(c1.p - c2.p);
		vector<Point> ret;
		if(dist > c1.r + c2.r) return ret;
		if(dist < abs(c1.r - c2.r)) return ret;
		const Real rc = (dist * dist + c1.r * c1.r - c2.r * c2.r) / (2 * dist);
		const Real rs = sqrt(c1.r * c1.r - rc * rc);
		const Point vec = (c2.p - c1.p) / dist;
		ret.emplace_back(c1.p + vec * Point(rc, rs));
		ret.emplace_back(c1.p + vec * Point(rc, -rs));
		return ret;
	}
	// 点と点の距離
	inline Real distance(const Point& a, const Point& b) {
		return abs(a - b);
	}
	// 点と直線の距離
	inline Real distance(const Point& p, const Line& l) {
		return abs(p - projection(p, l));
	}
	// 点と線分の距離
	inline Real distance(const Point& p, const Segment& s) {
		const Point pro = projection(p, s);
		const Line l(p, pro);
		if(intersect(s, l)) return distance(p, pro);
		return min(distance(p, s.a), distance(p, s.b));
	}
	// 線分と直線の距離
	inline Real distance(const Segment& s, const Line& l) {
		if(intersect(s, l)) return 0.0;
		Real ret = distance(s.a, l);
		ret = min(ret, distance(s.b, l));
		return ret;
	}
	// 線分と線分の距離
	inline Real distance(const Segment& s1, const Segment& s2) {
		if(intersect(s1, s2)) return 0.0;
		Real ret = distance(s1.a, s2);
		ret = min(ret, distance(s1.b, s2));
		ret = min(ret, distance(s2.a, s1));
		ret = min(ret, distance(s2.b, s1));
		return ret;
	}
	// 面積
	inline Real area(const vector<Point>& p) {
		int n = p.size();
		Real ret = 0;
		for(int i = 1; i <= n; ++i) {
			ret += cross(p[i - 1], p[i % n]);
		}
		return abs(ret / 2);
	}
	// 凸性判定（if rev false : 反時計回り）
	inline bool convexity(const vector<Point>& p, const bool rev = false) {
		int n = p.size();
		int ret = 0;
		for(int i = 1; i <= n; ++i) {
			ret |= ccw(p[(i - 1) % n], p[i % n], p[(i + 1) % n]);
		}
		if(rev) {
			ret &= CCW_COUNTER_CLOCKWISE; 
		} else {
			ret &= CCW_CLOCKWISE;
		}
		return ret == 0;
	}
	// 凸包（Monotone chain）
	vector<Point> convexHull(vector<Point>& p) {
		const int n = p.size();
		sort(p.begin(), p.end(), [](Point& l, Point& r) {
			return (sgn(r.imag(), l.imag()) != 0) ? (sgn(l.imag(), r.imag()) < 0) : (sgn(l.real(), r.real()) < 0);
		});
		vector<Point> ch(2 * n);
		constexpr int mask = CCW_CLOCKWISE | CCW_ON_SEGMENT;
		int k = 0;
		for(int i = 0; i < n; ch[k++] = p[i++]) {
			while(k >= 2 and ccw(ch[k - 2], ch[k - 1], p[i]) & mask) {
				--k;
			}
		}
		for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {
			while(k >= t and ccw(ch[k - 2], ch[k - 1], p[i]) & mask) {
				--k;
			}
		}
		ch.resize(k - 1);
		return ch;
	}
	inline istream& operator>>(istream& is, Point& p) {
		Real x, y;
		is >> x >> y;
		p = Point(x, y);
		return is;
	}
	inline ostream& operator<<(ostream& os, const Point &p) {
		return os << fixed << setprecision(15) << p.real() << " " << p.imag();
	}
}
// END CUT HERE
#line 7 "test/aoj/CGL_1_B.test.cpp"

using namespace geometry;
int main() {
	Point p1, p2; cin >> p1 >> p2;
	Line l(p1, p2);
	int q; cin >> q;
	while(q--) {
		Point p; cin >> p;
		cout << reflection(p, l) << '\n';
	}
	return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

