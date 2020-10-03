---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/LazySegmentTree.cpp
    title: "\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
  bundledCode: "#line 1 \"test/aoj/DSL_2_E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"DataStructure/LazySegmentTree.cpp\"\
    \nusing namespace std;\n\n// BEGIN CUT HERE\n/**\n * @brief \u9045\u5EF6\u8A55\
    \u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @tparam S \u8981\u7D20\u30E2\u30CE\
    \u30A4\u30C9\n * @tparam T \u4F5C\u7528\u7D20\u30E2\u30CE\u30A4\u30C9\n */\ntemplate<class\
    \ S, class T>\nstruct LazySegmentTree {\npublic:\n\t/**\n\t * @brief \u5358\u4F4D\
    \u5143\u3067\u521D\u671F\u5316\n\t * @param N \u30B5\u30A4\u30BA\n\t * @param\
    \ F \u4E8C\u9805\u6F14\u7B97 (S, S) -> S\n\t * @param G \u4E8C\u9805\u6F14\u7B97\
    \ (S, T) -> S\n\t * @param H \u4E8C\u9805\u6F14\u7B97 (T, T) -> T\n\t * @param\
    \ se \u8981\u7D20\u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n\t * @param\
    \ te \u4F5C\u7528\u7D20\u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n\t */\n\
    \tLazySegmentTree(const size_t N, const function<S(S, S)>& F, const function<S(S,\
    \ T)>& G, const function<T(T, T)>& H, const S& se, const T& te) : LazySegmentTree(vector<S>(N,\
    \ se), F, G, H, se, te) {}\n\t/**\n\t * @brief \u4E0E\u914D\u5217\u3067\u521D\u671F\
    \u5316\n\t * @param v \u914D\u5217\n\t * @param F \u4E8C\u9805\u6F14\u7B97 (S,\
    \ S) -> S\n\t * @param G \u4E8C\u9805\u6F14\u7B97 (S, T) -> S\n\t * @param H \u4E8C\
    \u9805\u6F14\u7B97 (T, T) -> T\n\t * @param se \u8981\u7D20\u30E2\u30CE\u30A4\u30C9\
    \u306E\u5358\u4F4D\u5143\n\t * @param te \u4F5C\u7528\u7D20\u30E2\u30CE\u30A4\u30C9\
    \u306E\u5358\u4F4D\u5143\n\t */\n\tLazySegmentTree(const vector<S>& v, const function<S(S,\
    \ S)>& F, const function<S(S, T)>& G, const function<T(T, T)>& H, const S& se,\
    \ const T& te) : F(F), G(G), H(H), se(se), te(te) {\n\t\theight = pow2(v.size());\n\
    \t\tN = 1 << height;\n\t\tval = vector<S>(N << 1, se);\n\t\tlazy = vector<T>(N\
    \ << 1, te);\n\t\tfor(int i = 0; i < v.size(); ++i) {\n\t\t\tval[N + i] = v[i];\n\
    \t\t}\n\t\tfor(int i = N - 1; i >= 1; --i) {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\t\
    /**\n\t * @brief 1\u70B9\u66F4\u65B0\n\t */\n\tvoid set(size_t idx, const S& _val)\
    \ {\n\t\tassert(idx < N);\n\t\tidx += N;\n\t\tfor(size_t i = height; i >= 1; --i)\
    \ {\n\t\t\tapply(idx >> i, lazy[idx >> i]);\n\t\t}\n\t\tval[idx] = _val;\n\t\t\
    while(idx > 1) {\n\t\t\tidx >>= 1;\n\t\t\tupdate(idx);\n\t\t}\n\t}\n\t/**\n\t\
    \ * @brief \u533A\u9593\u53D6\u5F97[l, r)\n\t */\n\tS get(size_t l, size_t r)\
    \ {\n\t\tassert(l < r and r <= N);\n\t\tl += N;\n\t\tr += N;\n\t\tfor(size_t i\
    \ = height; i >= 1; --i) {\n\t\t\tif((l >> i) << i != l) apply(l >> i, lazy[l\
    \ >> i]);\n\t\t\tif((r >> i) << i != r) apply((r - 1) >> i, lazy[(r - 1) >> i]);\n\
    \t\t}\n\t\tS valL = se;\n\t\tS valR = se;\n\t\tfor(; l < r; l >>= 1, r >>= 1)\
    \ {\n\t\t\tif(l & 1) {\n\t\t\t\tvalL = F(valL, val[l++]);\n\t\t\t}\n\t\t\tif(r\
    \ & 1) {\n\t\t\t\tvalR = F(val[--r], valR);\n\t\t\t}\n\t\t}\n\t\treturn F(valL,\
    \ valR);\n\t}\n\t/**\n\t * @brief \u533A\u9593\u4F5C\u7528[l, r)\n\t */\n\tvoid\
    \ apply(size_t l, size_t r, const T& _val) {\n\t\tassert(l < r and r <= N);\n\t\
    \tl += N;\n\t\tr += N;\n\t\tfor(size_t i = height; i >= 1; --i) {\n\t\t\tif((l\
    \ >> i) << i != l) apply(l >> i, lazy[l >> i]);\n\t\t\tif((r >> i) << i != r)\
    \ apply((r - 1) >> i, lazy[(r - 1) >> i]);\n\t\t}\n\t\tfor(size_t _l = l, _r =\
    \ r; _l < _r; _l >>= 1, _r >>= 1) {\n\t\t\tif(_l & 1) {\n\t\t\t\tval[_l] = G(val[_l],\
    \ _val);\n\t\t\t\tlazy[_l] = H(lazy[_l], _val);\n\t\t\t\t++_l;\n\t\t\t}\n\t\t\t\
    if(_r & 1) {\n\t\t\t\t--_r;\n\t\t\t\tval[_r] = G(val[_r], _val);\n\t\t\t\tlazy[_r]\
    \ = H(lazy[_r], _val);\n\t\t\t}\n\t\t}\n\t\tfor(size_t i = 1; i <= height; ++i)\
    \ {\n\t\t\tif((l >> i) << i != l) update(l >> i);\n\t\t\tif((r >> i) << i != r)\
    \ update((r - 1) >> i);\n\t\t}\n\t}\n\t/**\n\t * @brief 1\u70B9\u53D6\u5F97\n\t\
    \ */\n\tS get(size_t idx) {\n\t\tassert(idx < N);\n\t\tidx += N;\n\t\tfor(size_t\
    \ i = height; i >= 1; --i) {\n\t\t\tapply(idx >> i, lazy[idx >> i]);\n\t\t}\n\t\
    \treturn val[idx];\n\t}\n\t/**\n\t * @brief 1\u70B9\u53D6\u5F97\n\t */\n\tS operator[](const\
    \ size_t idx) {\n\t\tassert(idx < N);\n\t\treturn get(idx);\n\t}\nprivate:\n\t\
    const function<S(S, S)> F;\n\tconst function<S(S, T)> G;\n\tconst function<T(T,\
    \ T)> H;\n\tconst S se;\n\tconst T te;\n\tsize_t N;\n\tsize_t height;\n\tvector<S>\
    \ val;\n\tvector<T> lazy;\n\t/**\n\t * @return n <= 2^k \u306A\u308B\u6700\u5C0F\
    \u306E k\n\t */\n\tsize_t pow2(const size_t n) {\n\t\tsize_t k = 0;\n\t\twhile((1\
    \ << k) < n) {\n\t\t\t++k;\n\t\t}\n\t\treturn k;\n\t}\n\t/**\n\t * @brief val[idx]\u306E\
    \u66F4\u65B0\n\t */\n\tvoid update(const size_t idx) {\n\t\tval[idx] = F(val[idx\
    \ << 1], val[(idx << 1) | 1]);\n\t}\n\t/**\n\t * @brief val[idx]\u304B\u3089\u306E\
    \u4F1D\u64AD\n\t */\n\tvoid apply(const size_t idx, const T& _val) {\n\t\tif(lazy[idx]\
    \ != te) {\n\t\t\tval[idx << 1] = G(val[idx << 1], _val);\n\t\t\tval[(idx << 1)\
    \ | 1] = G(val[(idx << 1) | 1], _val);\n\t\t\tlazy[idx << 1] = H(lazy[idx << 1],\
    \ _val);\n\t\t\tlazy[(idx << 1) | 1] = H(lazy[(idx << 1) | 1], _val);\n\t\t\t\
    lazy[idx] = te;\n\t\t}\n\t}\n};\n// END CUT HERE\n#line 6 \"test/aoj/DSL_2_E.test.cpp\"\
    \n\nauto f = [](int l, int r) {\n\treturn l;\n};\nauto g = [](int l, int r) {\n\
    \treturn l + r;\n};\nauto h = [](int l, int r) {\n\treturn l + r;\n};\nconstexpr\
    \ int se = 0;\nconstexpr int te = 0;\n\nint main() {\n\tint n, q; cin >> n >>\
    \ q;\n\tLazySegmentTree<int, int> seg(n, f, g, h, se, te);\n\twhile(q--) {\n\t\
    \tint t; cin >> t;\n\t\tif(t == 0) {\n\t\t\tint l, r, x; cin >> l >> r >> x;\n\
    \t\t\tseg.apply(l - 1, r, x);\n\t\t}\n\t\tif(t == 1) {\n\t\t\tint i; cin >> i;\n\
    \t\t\tcout << seg.get(i - 1) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\n#include \"../../DataStructure/LazySegmentTree.cpp\"\
    \n\nauto f = [](int l, int r) {\n\treturn l;\n};\nauto g = [](int l, int r) {\n\
    \treturn l + r;\n};\nauto h = [](int l, int r) {\n\treturn l + r;\n};\nconstexpr\
    \ int se = 0;\nconstexpr int te = 0;\n\nint main() {\n\tint n, q; cin >> n >>\
    \ q;\n\tLazySegmentTree<int, int> seg(n, f, g, h, se, te);\n\twhile(q--) {\n\t\
    \tint t; cin >> t;\n\t\tif(t == 0) {\n\t\t\tint l, r, x; cin >> l >> r >> x;\n\
    \t\t\tseg.apply(l - 1, r, x);\n\t\t}\n\t\tif(t == 1) {\n\t\t\tint i; cin >> i;\n\
    \t\t\tcout << seg.get(i - 1) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - DataStructure/LazySegmentTree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_E.test.cpp
  requiredBy: []
  timestamp: '2020-10-03 16:59:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_E.test.cpp
- /verify/test/aoj/DSL_2_E.test.cpp.html
title: test/aoj/DSL_2_E.test.cpp
---
