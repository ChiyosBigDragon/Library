---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Geometry/template.cpp
    title: Geometry/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-8
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_D
  bundledCode: "#line 1 \"test/aoj/CGL_2_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_D\"\
    \n#define ERROR \"1e-8\"\n#include<bits/stdc++.h>\nusing namespace std;\n\n#line\
    \ 2 \"Geometry/template.cpp\"\nusing namespace std;\n\n// BEGIN CUT HERE\nnamespace\
    \ geometry {\n\tusing Real = double;\n\tusing Point = complex<Real>;\n\tconstexpr\
    \ Real EPS = 1e-9;\n\t// \u8AA4\u5DEE\u3092\u8003\u616E\u3057\u305F\u7B26\u53F7\
    \n\tinline int sgn(const Real x) {\n\t\treturn (x > EPS) - (x < -EPS);\n\t}\n\t\
    // \u8AA4\u5DEE\u3092\u8003\u616E\u3057\u305F l - r \u306E\u7B26\u53F7\n\tinline\
    \ int sgn(const Real l, const Real r) {\n\t\treturn sgn(l - r);\n\t}\n\tstruct\
    \ Circle {\n\t\tPoint p;\n\t\tReal r;\n\t\tCircle(const Point p, const Real r)\
    \ : p(p), r(r) {}\n\t};\n\tstruct Line {\n\t\tPoint a, b;\n\t\tLine(const Point\
    \ a, const Point b) : a(a), b(b) {}\n\t};\n\tstruct Segment : Line {\n\t\tSegment(const\
    \ Point a, const Point b) : Line(a, b) {}\n\t};\n\t// \u5185\u7A4D\n\tinline Real\
    \ dot(const Point& lhs, const Point& rhs) {\n\t\treturn (conj(lhs) * rhs).real();\n\
    \t}\n\t// \u5916\u7A4D\n\tinline Real cross(const Point& lhs, const Point& rhs)\
    \ {\n\t\treturn (conj(lhs) * rhs).imag();\n\t}\n\t// a \u306E b \u306B\u5BFE\u3059\
    \u308B\u6B63\u5C04\u5F71\u30D9\u30AF\u30C8\u30EB\n\tinline Point projection(const\
    \ Point& a, const Point& b) {\n\t\treturn b * dot(a, b) / norm(b);\n\t}\n\t//\
    \ \u70B9p\u304B\u3089\u76F4\u7DDAl\u306B\u4E0B\u308D\u3057\u305F\u5782\u7DDA\u306E\
    \u8DB3\n\tinline Point projection(const Point& p, const Line& l) {\n\t\treturn\
    \ projection(p - l.a, l.b - l.a) + l.a;\n\t}\n\t// \u76F4\u7DDAl\u3092\u5BFE\u79F0\
    \u8EF8\u3068\u3057\u3066\u70B9p\u3068\u7DDA\u5BFE\u79F0\u306A\u70B9\n\tinline\
    \ Point reflection(const Point& p, const Line& l) {\n\t\treturn p + (projection(p,\
    \ l) - p) * 2.0;\n\t}\n\t// \u53CD\u6642\u8A08\u56DE\u308A(a -> b -> c)\n\tstatic\
    \ constexpr int CCW_COUNTER_CLOCKWISE = 0b00001;\n\t// \u6642\u8A08\u56DE\u308A\
    (a -> b -> c)\n\tstatic constexpr int CCW_CLOCKWISE = 0b00010;\n\t// \u540C\u4E00\
    \u76F4\u7DDA\u4E0A(c -> a -> b)\n\tstatic constexpr int CCW_ONLINE_BACK = 0b00100;\n\
    \t// \u540C\u4E00\u76F4\u7DDA\u4E0A(a -> b -> c, b on ac)\n\tstatic constexpr\
    \ int CCW_ONLINE_FRONT = 0b01000;\n\t// \u540C\u4E00\u76F4\u7DDA\u4E0A(a -> c\
    \ -> b)\n\tstatic constexpr int CCW_ON_SEGMENT = 0b10000;\n\t// 3\u70B9\u306E\u4F4D\
    \u7F6E\u95A2\u4FC2\n\tinline int ccw(const Point& a, Point b, Point c) {\n\t\t\
    b = b - a, c = c - a;\n\t\tif(sgn(cross(b, c)) > 0) return CCW_COUNTER_CLOCKWISE;\n\
    \t\tif(sgn(cross(b, c)) < 0) return CCW_CLOCKWISE;\n\t\tif(dot(b, c) < 0) return\
    \ CCW_ONLINE_BACK;\n\t\tif(norm(b) < norm(c)) return CCW_ONLINE_FRONT;\n\t\treturn\
    \ CCW_ON_SEGMENT;\n\t}\n\t// \u5E73\u884C\u5224\u5B9A\n\tinline bool parallel(const\
    \ Line& l1, const Line& l2) {\n\t\treturn sgn(cross(l1.a - l1.b, l2.a - l2.b))\
    \ == 0;\n\t}\n\t// \u76F4\u4EA4\u5224\u5B9A\n\tinline bool orthogonal(const Line&\
    \ l1, const Line& l2) {\n\t\treturn sgn(dot(l1.a - l1.b, l2.a - l2.b)) == 0;\n\
    \t}\n\t// \u76F4\u7DDA\u3068\u76F4\u7DDA\u306E\u4EA4\u5DEE\u5224\u5B9A\n\tinline\
    \ bool intersect(const Line& l1, const Line& l2) {\n\t\treturn not parallel(l1,\
    \ l2);\n\t}\n\t// \u7DDA\u5206\u3068\u76F4\u7DDA\u306E\u4EA4\u5DEE\u5224\u5B9A\
    \n\tinline bool intersect(const Segment& s, const Line& l) {\n\t\tconstexpr int\
    \ plus = CCW_COUNTER_CLOCKWISE | CCW_ONLINE_BACK;\n\t\tconstexpr int minus = CCW_CLOCKWISE\
    \ | CCW_ONLINE_FRONT;\n\t\tint f[2] = {ccw(l.a, l.b, s.a), ccw(l.a, l.b, s.b)};\n\
    \t\tfor(int i = 0; i < 2; ++i) {\n\t\t\tf[i] = (f[i] & plus) ? +1 : ((f[i] & minus)\
    \ ? -1 : 0);\n\t\t}\n\t\treturn (f[0] * f[1] <= 0);\n\t}\n\t// \u7DDA\u5206\u3068\
    \u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\n\tinline bool intersect(const Segment&\
    \ s1, const Segment& s2) {\n\t\tconstexpr int plus = CCW_COUNTER_CLOCKWISE | CCW_ONLINE_BACK;\n\
    \t\tconstexpr int minus = CCW_CLOCKWISE | CCW_ONLINE_FRONT;\n\t\tint f[4] = {ccw(s1.a,\
    \ s1.b, s2.a), ccw(s1.a, s1.b, s2.b), ccw(s2.a, s2.b, s1.a), ccw(s2.a, s2.b, s1.b)};\n\
    \t\tfor(int i = 0; i < 4; ++i) {\n\t\t\tf[i] = (f[i] & plus) ? +1 : ((f[i] & minus)\
    \ ? -1 : 0);\n\t\t}\n\t\treturn (f[0] * f[1] <= 0) and (f[2] * f[3] <= 0);\n\t\
    }\n\t// \u76F4\u7DDA\u3068\u76F4\u7DDA\u306E\u4EA4\u70B9\uFF08\u8981\uFF1A\u4EA4\
    \u5DEE\u5224\u5B9A\uFF09\n\tinline Point crossPoint(const Line& l1, const Line&\
    \ l2) {\n\t\tassert(intersect(l1, l2));\n\t\tPoint a = l1.b - l1.a;\n\t\tPoint\
    \ b = l2.b - l2.a;\n\t\treturn l1.a + a * cross(b, l2.a - l1.a) / cross(b, a);\n\
    \t}\n\t// \u7DDA\u5206\u3068\u7DDA\u5206\u306E\u4EA4\u70B9\uFF08\u8981\uFF1A\u4EA4\
    \u5DEE\u5224\u5B9A\uFF09\n\tinline Point crossPoint(const Segment& s1, const Segment&\
    \ s2) {\n\t\tassert(intersect(s1, s2));\n\t\treturn crossPoint((Line)s1, (Line)s2);\n\
    \t}\n\t// \u5186\u3068\u5186\u306E\u4EA4\u70B9\n\tvector<Point> crossPoint(const\
    \ Circle& c1, const Circle& c2) {\n\t\tconst Real dist = abs(c1.p - c2.p);\n\t\
    \tvector<Point> ret;\n\t\tif(dist > c1.r + c2.r) return ret;\n\t\tif(dist < abs(c1.r\
    \ - c2.r)) return ret;\n\t\tconst Real rc = (dist * dist + c1.r * c1.r - c2.r\
    \ * c2.r) / (2 * dist);\n\t\tconst Real rs = sqrt(c1.r * c1.r - rc * rc);\n\t\t\
    const Point vec = (c2.p - c1.p) / dist;\n\t\tret.emplace_back(c1.p + vec * Point(rc,\
    \ rs));\n\t\tret.emplace_back(c1.p + vec * Point(rc, -rs));\n\t\treturn ret;\n\
    \t}\n\t// \u70B9\u3068\u70B9\u306E\u8DDD\u96E2\n\tinline Real distance(const Point&\
    \ a, const Point& b) {\n\t\treturn abs(a - b);\n\t}\n\t// \u70B9\u3068\u76F4\u7DDA\
    \u306E\u8DDD\u96E2\n\tinline Real distance(const Point& p, const Line& l) {\n\t\
    \treturn abs(p - projection(p, l));\n\t}\n\t// \u70B9\u3068\u7DDA\u5206\u306E\u8DDD\
    \u96E2\n\tinline Real distance(const Point& p, const Segment& s) {\n\t\tconst\
    \ Point pro = projection(p, s);\n\t\tconst Line l(p, pro);\n\t\tif(intersect(s,\
    \ l)) return distance(p, pro);\n\t\treturn min(distance(p, s.a), distance(p, s.b));\n\
    \t}\n\t// \u7DDA\u5206\u3068\u76F4\u7DDA\u306E\u8DDD\u96E2\n\tinline Real distance(const\
    \ Segment& s, const Line& l) {\n\t\tif(intersect(s, l)) return 0.0;\n\t\tReal\
    \ ret = distance(s.a, l);\n\t\tret = min(ret, distance(s.b, l));\n\t\treturn ret;\n\
    \t}\n\t// \u7DDA\u5206\u3068\u7DDA\u5206\u306E\u8DDD\u96E2\n\tinline Real distance(const\
    \ Segment& s1, const Segment& s2) {\n\t\tif(intersect(s1, s2)) return 0.0;\n\t\
    \tReal ret = distance(s1.a, s2);\n\t\tret = min(ret, distance(s1.b, s2));\n\t\t\
    ret = min(ret, distance(s2.a, s1));\n\t\tret = min(ret, distance(s2.b, s1));\n\
    \t\treturn ret;\n\t}\n\t// \u9762\u7A4D\n\tinline Real area(const vector<Point>&\
    \ p) {\n\t\tint n = p.size();\n\t\tReal ret = 0;\n\t\tfor(int i = 1; i <= n; ++i)\
    \ {\n\t\t\tret += cross(p[i - 1], p[i % n]);\n\t\t}\n\t\treturn abs(ret / 2);\n\
    \t}\n\t// \u51F8\u6027\u5224\u5B9A\uFF08if rev false : \u53CD\u6642\u8A08\u56DE\
    \u308A\uFF09\n\tinline bool convexity(const vector<Point>& p, const bool rev =\
    \ false) {\n\t\tint n = p.size();\n\t\tint ret = 0;\n\t\tfor(int i = 1; i <= n;\
    \ ++i) {\n\t\t\tret |= ccw(p[(i - 1) % n], p[i % n], p[(i + 1) % n]);\n\t\t}\n\
    \t\tif(rev) {\n\t\t\tret &= CCW_COUNTER_CLOCKWISE; \n\t\t} else {\n\t\t\tret &=\
    \ CCW_CLOCKWISE;\n\t\t}\n\t\treturn ret == 0;\n\t}\n\t// \u51F8\u5305\uFF08Monotone\
    \ chain\uFF09\n\tvector<Point> convexHull(vector<Point>& p) {\n\t\tconst int n\
    \ = p.size();\n\t\tsort(p.begin(), p.end(), [](Point& l, Point& r) {\n\t\t\treturn\
    \ (sgn(r.imag(), l.imag()) != 0) ? (sgn(l.imag(), r.imag()) < 0) : (sgn(l.real(),\
    \ r.real()) < 0);\n\t\t});\n\t\tvector<Point> ch(2 * n);\n\t\tconstexpr int mask\
    \ = CCW_CLOCKWISE | CCW_ON_SEGMENT;\n\t\tint k = 0;\n\t\tfor(int i = 0; i < n;\
    \ ch[k++] = p[i++]) {\n\t\t\twhile(k >= 2 and ccw(ch[k - 2], ch[k - 1], p[i])\
    \ & mask) {\n\t\t\t\t--k;\n\t\t\t}\n\t\t}\n\t\tfor(int i = n - 2, t = k + 1; i\
    \ >= 0; ch[k++] = p[i--]) {\n\t\t\twhile(k >= t and ccw(ch[k - 2], ch[k - 1],\
    \ p[i]) & mask) {\n\t\t\t\t--k;\n\t\t\t}\n\t\t}\n\t\tch.resize(k - 1);\n\t\treturn\
    \ ch;\n\t}\n\tinline istream& operator>>(istream& is, Point& p) {\n\t\tReal x,\
    \ y;\n\t\tis >> x >> y;\n\t\tp = Point(x, y);\n\t\treturn is;\n\t}\n\tinline ostream&\
    \ operator<<(ostream& os, const Point &p) {\n\t\treturn os << fixed << setprecision(15)\
    \ << p.real() << \" \" << p.imag();\n\t}\n}\n// END CUT HERE\n#line 7 \"test/aoj/CGL_2_D.test.cpp\"\
    \n\nusing namespace geometry;\nint main() {\n\tint q; cin >> q;\n\twhile(q--)\
    \ {\n\t\tPoint p[4];\n\t\tfor(int i = 0; i < 4; ++i) cin >> p[i];\n\t\tSegment\
    \ s1(p[0], p[1]);\n\t\tSegment s2(p[2], p[3]);\n\t\tcout << fixed << setprecision(15)\
    \ << distance(s1, s2) << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_D\"\
    \n#define ERROR \"1e-8\"\n#include<bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../../Geometry/template.cpp\"\n\nusing namespace geometry;\nint main() {\n\
    \tint q; cin >> q;\n\twhile(q--) {\n\t\tPoint p[4];\n\t\tfor(int i = 0; i < 4;\
    \ ++i) cin >> p[i];\n\t\tSegment s1(p[0], p[1]);\n\t\tSegment s2(p[2], p[3]);\n\
    \t\tcout << fixed << setprecision(15) << distance(s1, s2) << '\\n';\n\t}\n\treturn\
    \ 0;\n}\n"
  dependsOn:
  - Geometry/template.cpp
  isVerificationFile: true
  path: test/aoj/CGL_2_D.test.cpp
  requiredBy: []
  timestamp: '2020-07-03 22:28:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_2_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_2_D.test.cpp
- /verify/test/aoj/CGL_2_D.test.cpp.html
title: test/aoj/CGL_2_D.test.cpp
---
