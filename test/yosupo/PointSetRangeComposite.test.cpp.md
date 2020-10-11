---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/SegmentTree.cpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: Math/ModInt.cpp
    title: x ^ n
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo/PointSetRangeComposite.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"Math/ModInt.cpp\"\nusing namespace std;\r\n\r\
    \n// BEGIN CUT HERE\r\n/**\r\n * @tparam MOD\r\n */\r\ntemplate<int_fast64_t MOD>\r\
    \nstruct ModInt {\r\npublic:\r\n\tint_fast64_t x;\r\n\tModInt() : x(0) {}\r\n\t\
    ModInt(int_fast64_t x) : x(x >= 0 ? x % MOD : (MOD - (-x) % MOD) % MOD) {}\r\n\
    \tconstexpr ModInt operator-() const {\r\n\t\treturn ModInt(-x);\r\n\t}\r\n\t\
    constexpr ModInt& operator+=(const ModInt& rhs) {\r\n\t\tx += rhs.x;\r\n\t\tif(x\
    \ >= MOD) {\r\n\t\t\tx -= MOD;\r\n\t\t}\r\n\t\treturn (*this);\r\n\t}\r\n\tconstexpr\
    \ ModInt operator+(const ModInt& rhs) const {\r\n\t\treturn ModInt(*this) += rhs;\r\
    \n\t}\r\n\tconstexpr ModInt& operator-=(const ModInt& rhs) {\r\n\t\tx += MOD -\
    \ rhs.x;\r\n\t\tif(x >= MOD) {\r\n\t\t\tx -= MOD;\r\n\t\t}\r\n\t\treturn (*this);\r\
    \n\t}\r\n\tconstexpr ModInt operator-(const ModInt& rhs) const {\r\n\t\treturn\
    \ ModInt(*this) -= rhs;\r\n\t}\r\n\tconstexpr ModInt& operator*=(const ModInt&\
    \ rhs) {\r\n\t\tx *= rhs.x;\r\n\t\tif(x >= MOD) {\r\n\t\t\tx %= MOD;\r\n\t\t}\r\
    \n\t\treturn (*this);\r\n\t}\r\n\tconstexpr ModInt operator*(const ModInt& rhs)\
    \ const {\r\n\t\treturn ModInt(*this) *= rhs;\r\n\t}\r\n\tconstexpr ModInt& operator/=(const\
    \ ModInt &rhs) {\r\n\t\t(*this) *= rhs.inverse();\r\n\t\treturn (*this);\r\n\t\
    }\r\n\tconstexpr ModInt operator/(const ModInt& rhs) const {\r\n\t\treturn ModInt(*this)\
    \ /= rhs;\r\n\t}\r\n\tconstexpr bool operator==(const ModInt& rhs) {\r\n\t\treturn\
    \ x == rhs.x;\r\n\t}\r\n\tconstexpr bool operator!=(const ModInt& rhs) {\r\n\t\
    \treturn x != rhs.x;\r\n\t}\r\n\t/**\r\n\t * @brief x ^ n\r\n\t */\r\n\tconstexpr\
    \ ModInt pow(int_fast64_t n) const {\r\n\t\tint_fast64_t tmp = x;\r\n\t\tint_fast64_t\
    \ ret = 1;\r\n\t\twhile(n > 0){\r\n\t\t\tif(n & 1) {\r\n\t\t\t\tret = ret * tmp\
    \ % MOD;\r\n\t\t\t}\r\n\t\t\ttmp = tmp * tmp % MOD;\r\n\t\t\tn >>= static_cast<int_fast64_t>(1);\r\
    \n\t\t}\r\n\t\treturn ModInt(ret);\r\n\t}\r\n\t/**\r\n\t * @brief 1 / x\r\n\t\
    \ */\r\n\tconstexpr ModInt inverse() const {\r\n\t\tint_fast64_t a = x, b = MOD,\
    \ s = 1, t = 0;\r\n\t\twhile(b > 0) {\r\n\t\t\tint_fast64_t u = a / b;\r\n\t\t\
    \ta -= u * b;\r\n\t\t\ts -= u * t;\r\n\t\t\tswap(a, b);\r\n\t\t\tswap(s, t);\r\
    \n\t\t}\r\n\t\treturn ModInt(s);\r\n\t}\r\n\tfriend istream& operator>>(istream&\
    \ lhs, ModInt<MOD>& rhs) {\r\n\t\tint_fast64_t x;\r\n\t\tlhs >> x;\r\n\t\trhs\
    \ = ModInt<MOD>(x);\r\n\t\treturn lhs;\r\n\t}\r\n\tfriend ostream& operator<<(ostream&\
    \ lhs, const ModInt<MOD>& rhs) {\r\n\t\treturn lhs << rhs.x;\r\n\t}\r\n};\r\n\
    // END CUT HERE\n#line 2 \"DataStructure/SegmentTree.cpp\"\nusing namespace std;\n\
    \n// BEGIN CUT HERE\n/**\n * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @tparam\
    \ S \u8981\u7D20\u30E2\u30CE\u30A4\u30C9\n */\ntemplate<class S>\nstruct SegmentTree\
    \ {\npublic:\n\t/**\n\t * @brief \u5358\u4F4D\u5143\u3067\u521D\u671F\u5316\n\t\
    \ * @param N \u30B5\u30A4\u30BA\n\t * @param F \u4E8C\u9805\u6F14\u7B97 (S, S)\
    \ -> S \n \t * @param e \u8981\u7D20\u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\
    \u5143\n\t */\n\tSegmentTree(const size_t N, const function<S(S, S)>& F, const\
    \ S& e) : SegmentTree(vector<S>(N, e), F, e) {}\n\t/**\n\t * @brief \u4E0E\u914D\
    \u5217\u3067\u521D\u671F\u5316\n\t * @param v \u914D\u5217\n\t * @param F \u4E8C\
    \u9805\u6F14\u7B97 (S, S) -> S \n \t * @param e \u8981\u7D20\u30E2\u30CE\u30A4\
    \u30C9\u306E\u5358\u4F4D\u5143\n\t */\n\tSegmentTree(const vector<S>& v, const\
    \ function<S(S, S)>& F, const S& e) : F(F), e(e) {\n\t\tN = 1 << pow2(v.size());\n\
    \t\tval = vector<S>(N << 1, e);\n\t\tfor(size_t i = 0; i < v.size(); ++i) {\n\t\
    \t\tval[N + i] = v[i];\n\t\t}\n\t\tfor(size_t i = N - 1; i >= 1; --i) {\n\t\t\t\
    update(i);\n\t\t}\n\t}\n\t/**\n\t * @brief 1\u70B9\u66F4\u65B0\n\t */\n\tvoid\
    \ set(size_t idx, const S& _val) {\n\t\tassert(idx < N);\n\t\tidx += N;\n\t\t\
    val[idx] = _val;\n\t\twhile(idx > 1) {\n\t\t\tidx >>= 1;\n\t\t\tupdate(idx);\n\
    \t\t}\n\t}\n\t/**\n\t * @brief \u533A\u9593\u53D6\u5F97[l, r)\n\t */\n\tS get(size_t\
    \ l, size_t r) {\n\t\tassert(l < r and r <= N);\n\t\tS valL = e;\n\t\tS valR =\
    \ e;\n\t\tfor(l += N, r += N; l < r; l >>= 1, r >>= 1) {\n\t\t\tif(l & 1) {\n\t\
    \t\t\tvalL = F(valL, val[l++]);\n\t\t\t}\n\t\t\tif(r & 1) {\n\t\t\t\tvalR = F(val[--r],\
    \ valR);\n\t\t\t}\n\t\t}\n\t\treturn F(valL, valR);\n\t}\n\t/**\n\t * @brief 1\u70B9\
    \u53D6\u5F97\n\t */\n\tS get(const size_t idx) {\n\t\tassert(idx < N);\n\t\treturn\
    \ val[N + idx];\n\t}\n\t/**\n\t * @brief 1\u70B9\u53D6\u5F97\n\t */\n\tS operator[](const\
    \ size_t idx) {\n\t\tassert(idx < N);\n\t\treturn val[N + idx];\n\t}\nprivate:\n\
    \tconst function<S(S, S)> F;\n\tconst S e;\n\tsize_t N;\n\tvector<S> val;\n\t\
    /**\n\t * @return n <= 2^k \u306A\u308B\u6700\u5C0F\u306E k\n\t */\n\tsize_t pow2(const\
    \ size_t n) {\n\t\tsize_t k = 0;\n\t\twhile((1 << k) < n) {\n\t\t\t++k;\n\t\t\
    }\n\t\treturn k;\n\t}\n\t/**\n\t * @brief v[idx]\u306E\u66F4\u65B0\n\t */\n\t\
    void update(size_t idx) {\n\t\tval[idx] = F(val[idx << 1], val[(idx << 1) | 1]);\n\
    \t}\n};\n// END CUT HERE\n#line 7 \"test/yosupo/PointSetRangeComposite.test.cpp\"\
    \n\nconstexpr int MOD = 998244353;\nusing mint = ModInt<MOD>;\nstruct S {\n\t\
    mint a;\n\tmint b;\n};\nauto f = [](S l, S r) {\n\treturn S{l.a * r.a, l.b * r.a\
    \ + r.b};\n};\nconst S e{1, 0};\n\nint main() {\n\tint n, q; cin >> n >> q;\n\t\
    vector<S> v(n);\n\tfor(int i = 0; i < n; ++i) {\n\t\tint a, b; cin >> a >> b;\n\
    \t\tv[i] = S{a, b};\n\t}\n\tSegmentTree<S> seg(v, f, e);\n\twhile(q--) {\n\t\t\
    int t; cin >> t;\n\t\tif(t == 0) {\n\t\t\tint p, c, d; cin >> p >> c >> d;\n\t\
    \t\tseg.set(p, S{c, d});\n\t\t}\n\t\tif(t == 1) {\n\t\t\tint l, r, x; cin >> l\
    \ >> r >> x;\n\t\t\tS s = seg.get(l, r);\n\t\t\tcout << s.a * x + s.b << '\\n';\n\
    \t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#include \"../../Math/ModInt.cpp\"\
    \n#include \"../../DataStructure/SegmentTree.cpp\"\n\nconstexpr int MOD = 998244353;\n\
    using mint = ModInt<MOD>;\nstruct S {\n\tmint a;\n\tmint b;\n};\nauto f = [](S\
    \ l, S r) {\n\treturn S{l.a * r.a, l.b * r.a + r.b};\n};\nconst S e{1, 0};\n\n\
    int main() {\n\tint n, q; cin >> n >> q;\n\tvector<S> v(n);\n\tfor(int i = 0;\
    \ i < n; ++i) {\n\t\tint a, b; cin >> a >> b;\n\t\tv[i] = S{a, b};\n\t}\n\tSegmentTree<S>\
    \ seg(v, f, e);\n\twhile(q--) {\n\t\tint t; cin >> t;\n\t\tif(t == 0) {\n\t\t\t\
    int p, c, d; cin >> p >> c >> d;\n\t\t\tseg.set(p, S{c, d});\n\t\t}\n\t\tif(t\
    \ == 1) {\n\t\t\tint l, r, x; cin >> l >> r >> x;\n\t\t\tS s = seg.get(l, r);\n\
    \t\t\tcout << s.a * x + s.b << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - Math/ModInt.cpp
  - DataStructure/SegmentTree.cpp
  isVerificationFile: true
  path: test/yosupo/PointSetRangeComposite.test.cpp
  requiredBy: []
  timestamp: '2020-10-11 19:09:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/PointSetRangeComposite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/PointSetRangeComposite.test.cpp
- /verify/test/yosupo/PointSetRangeComposite.test.cpp.html
title: test/yosupo/PointSetRangeComposite.test.cpp
---
