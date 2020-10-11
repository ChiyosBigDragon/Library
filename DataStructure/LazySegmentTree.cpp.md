---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.test.cpp
    title: test/aoj/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.test.cpp
    title: test/aoj/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"DataStructure/LazySegmentTree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// BEGIN CUT HERE\n/**\n * @brief \u9045\u5EF6\u8A55\u4FA1\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @tparam S \u8981\u7D20\u30E2\u30CE\u30A4\
    \u30C9\n * @tparam T \u4F5C\u7528\u7D20\u30E2\u30CE\u30A4\u30C9\n */\ntemplate<class\
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
    \ << 1, te);\n\t\tfor(size_t i = 0; i < v.size(); ++i) {\n\t\t\tval[N + i] = v[i];\n\
    \t\t}\n\t\tfor(size_t i = N - 1; i >= 1; --i) {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\
    \t/**\n\t * @brief 1\u70B9\u66F4\u65B0\n\t */\n\tvoid set(size_t idx, const S&\
    \ _val) {\n\t\tassert(idx < N);\n\t\tidx += N;\n\t\tfor(size_t i = height; i >=\
    \ 1; --i) {\n\t\t\tapply(idx >> i, lazy[idx >> i]);\n\t\t}\n\t\tval[idx] = _val;\n\
    \t\twhile(idx > 1) {\n\t\t\tidx >>= 1;\n\t\t\tupdate(idx);\n\t\t}\n\t}\n\t/**\n\
    \t * @brief \u533A\u9593\u53D6\u5F97[l, r)\n\t */\n\tS get(size_t l, size_t r)\
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
    lazy[idx] = te;\n\t\t}\n\t}\n};\n// END CUT HERE\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// BEGIN CUT HERE\n/**\n\
    \ * @brief \u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @tparam\
    \ S \u8981\u7D20\u30E2\u30CE\u30A4\u30C9\n * @tparam T \u4F5C\u7528\u7D20\u30E2\
    \u30CE\u30A4\u30C9\n */\ntemplate<class S, class T>\nstruct LazySegmentTree {\n\
    public:\n\t/**\n\t * @brief \u5358\u4F4D\u5143\u3067\u521D\u671F\u5316\n\t * @param\
    \ N \u30B5\u30A4\u30BA\n\t * @param F \u4E8C\u9805\u6F14\u7B97 (S, S) -> S\n\t\
    \ * @param G \u4E8C\u9805\u6F14\u7B97 (S, T) -> S\n\t * @param H \u4E8C\u9805\u6F14\
    \u7B97 (T, T) -> T\n\t * @param se \u8981\u7D20\u30E2\u30CE\u30A4\u30C9\u306E\u5358\
    \u4F4D\u5143\n\t * @param te \u4F5C\u7528\u7D20\u30E2\u30CE\u30A4\u30C9\u306E\u5358\
    \u4F4D\u5143\n\t */\n\tLazySegmentTree(const size_t N, const function<S(S, S)>&\
    \ F, const function<S(S, T)>& G, const function<T(T, T)>& H, const S& se, const\
    \ T& te) : LazySegmentTree(vector<S>(N, se), F, G, H, se, te) {}\n\t/**\n\t *\
    \ @brief \u4E0E\u914D\u5217\u3067\u521D\u671F\u5316\n\t * @param v \u914D\u5217\
    \n\t * @param F \u4E8C\u9805\u6F14\u7B97 (S, S) -> S\n\t * @param G \u4E8C\u9805\
    \u6F14\u7B97 (S, T) -> S\n\t * @param H \u4E8C\u9805\u6F14\u7B97 (T, T) -> T\n\
    \t * @param se \u8981\u7D20\u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n\t\
    \ * @param te \u4F5C\u7528\u7D20\u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\
    \n\t */\n\tLazySegmentTree(const vector<S>& v, const function<S(S, S)>& F, const\
    \ function<S(S, T)>& G, const function<T(T, T)>& H, const S& se, const T& te)\
    \ : F(F), G(G), H(H), se(se), te(te) {\n\t\theight = pow2(v.size());\n\t\tN =\
    \ 1 << height;\n\t\tval = vector<S>(N << 1, se);\n\t\tlazy = vector<T>(N << 1,\
    \ te);\n\t\tfor(size_t i = 0; i < v.size(); ++i) {\n\t\t\tval[N + i] = v[i];\n\
    \t\t}\n\t\tfor(size_t i = N - 1; i >= 1; --i) {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\
    \t/**\n\t * @brief 1\u70B9\u66F4\u65B0\n\t */\n\tvoid set(size_t idx, const S&\
    \ _val) {\n\t\tassert(idx < N);\n\t\tidx += N;\n\t\tfor(size_t i = height; i >=\
    \ 1; --i) {\n\t\t\tapply(idx >> i, lazy[idx >> i]);\n\t\t}\n\t\tval[idx] = _val;\n\
    \t\twhile(idx > 1) {\n\t\t\tidx >>= 1;\n\t\t\tupdate(idx);\n\t\t}\n\t}\n\t/**\n\
    \t * @brief \u533A\u9593\u53D6\u5F97[l, r)\n\t */\n\tS get(size_t l, size_t r)\
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
    lazy[idx] = te;\n\t\t}\n\t}\n};\n// END CUT HERE\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/LazySegmentTree.cpp
  requiredBy: []
  timestamp: '2020-10-04 03:22:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_E.test.cpp
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/DSL_2_D.test.cpp
  - test/aoj/DSL_2_G.test.cpp
documentation_of: DataStructure/LazySegmentTree.cpp
layout: document
redirect_from:
- /library/DataStructure/LazySegmentTree.cpp
- /library/DataStructure/LazySegmentTree.cpp.html
title: "\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
