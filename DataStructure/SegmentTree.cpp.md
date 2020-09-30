---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/PointAddRangeSum.test.cpp
    title: test/yosupo/PointAddRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/StaticRMQ.test.cpp
    title: test/yosupo/StaticRMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/StaticRangeSum.test.cpp
    title: test/yosupo/StaticRangeSum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"DataStructure/SegmentTree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// BEGIN CUT HERE\n/**\n * @brief \u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\n * @tparam S \u30E2\u30CE\u30A4\u30C9\n * @tparam F \u4E8C\u9805\
    \u6F14\u7B97 (S, S) -> S \n * @tparam e \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\
    \u5143\n */\ntemplate<class S, auto F, S e>\nstruct SegmentTree {\npublic:\n\t\
    /**\n\t * @brief \u5358\u4F4D\u5143\u3067\u521D\u671F\u5316\n\t * @param _N \u30B5\
    \u30A4\u30BA\n\t */\n\tSegmentTree(size_t _N) : SegmentTree(vector<S>(_N, e))\
    \ {}\n\t/**\n\t * @brief \u4E0E\u914D\u5217\u3067\u521D\u671F\u5316\n\t * @param\
    \ _v \u914D\u5217\n\t */\n\tSegmentTree(const vector<S>& _v) {\n\t\tN = pow2(_v.size());\n\
    \t\tv = vector<S>(N << 1, e);\n\t\tfor(int i = 0; i < _v.size(); ++i) {\n\t\t\t\
    v[N + i] = _v[i];\n\t\t}\n\t\tfor(int i = N - 1; i >= 1; --i) {\n\t\t\tupdate(i);\n\
    \t\t}\n\t}\n\t/**\n\t * @brief 1\u70B9\u66F4\u65B0\n\t */\n\tvoid set(size_t idx,\
    \ const S val) {\n\t\tassert(idx < N);\n\t\tidx += N;\n\t\tv[idx] = val;\n\t\t\
    while(idx > 1) {\n\t\t\tidx >>= 1;\n\t\t\tupdate(idx);\n\t\t}\n\t}\n\t/**\n\t\
    \ * @brief \u533A\u9593\u53D6\u5F97[l, r)\n\t */\n\tS get(size_t l, size_t r)\
    \ {\n\t\tassert(l < r and r <= N);\n\t\tS valL = e;\n\t\tS valR = e;\n\t\tfor(l\
    \ += N, r += N; l < r; l >>= 1, r >>= 1) {\n\t\t\tvalL = (l & 1) ? F(valL, v[l++])\
    \ : valL;\n\t\t\tvalR = (r & 1) ? F(v[--r], valR) : valR;\n\t\t}\n\t\treturn F(valL,\
    \ valR);\n\t}\n\t/**\n\t * @brief 1\u70B9\u53D6\u5F97\n\t */\n\tS get(const size_t\
    \ idx) {\n\t\tassert(idx < N);\n\t\treturn v[N + idx];\n\t}\n\t/**\n\t * @brief\
    \ 1\u70B9\u53D6\u5F97\n\t */\n\tS operator[](const size_t idx) {\n\t\tassert(idx\
    \ < N);\n\t\treturn v[N + idx];\n\t}\nprivate:\n\tsize_t N;\n\tvector<S> v;\n\t\
    /**\n\t * @return n <= k \u306A\u308B\u6700\u5C0F\u306E2\u3079\u304D k\n\t */\n\
    \tsize_t pow2(size_t n) {\n\t\tsize_t sz = 1;\n\t\twhile(sz < n) {\n\t\t\tsz <<=\
    \ 1;\n\t\t}\n\t\treturn sz;\n\t}\n\t/**\n\t * @brief v[idx]\u306E\u66F4\u65B0\n\
    \t */\n\tvoid update(size_t idx) {\n\t\tv[idx] = F(v[idx << 1], v[(idx << 1) |\
    \ 1]);\n\t}\n};\n// END CUT HERE\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// BEGIN CUT HERE\n/**\n\
    \ * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @tparam S \u30E2\u30CE\u30A4\
    \u30C9\n * @tparam F \u4E8C\u9805\u6F14\u7B97 (S, S) -> S \n * @tparam e \u30E2\
    \u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\n */\ntemplate<class S, auto F, S e>\n\
    struct SegmentTree {\npublic:\n\t/**\n\t * @brief \u5358\u4F4D\u5143\u3067\u521D\
    \u671F\u5316\n\t * @param _N \u30B5\u30A4\u30BA\n\t */\n\tSegmentTree(size_t _N)\
    \ : SegmentTree(vector<S>(_N, e)) {}\n\t/**\n\t * @brief \u4E0E\u914D\u5217\u3067\
    \u521D\u671F\u5316\n\t * @param _v \u914D\u5217\n\t */\n\tSegmentTree(const vector<S>&\
    \ _v) {\n\t\tN = pow2(_v.size());\n\t\tv = vector<S>(N << 1, e);\n\t\tfor(int\
    \ i = 0; i < _v.size(); ++i) {\n\t\t\tv[N + i] = _v[i];\n\t\t}\n\t\tfor(int i\
    \ = N - 1; i >= 1; --i) {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\t/**\n\t * @brief 1\u70B9\
    \u66F4\u65B0\n\t */\n\tvoid set(size_t idx, const S val) {\n\t\tassert(idx < N);\n\
    \t\tidx += N;\n\t\tv[idx] = val;\n\t\twhile(idx > 1) {\n\t\t\tidx >>= 1;\n\t\t\
    \tupdate(idx);\n\t\t}\n\t}\n\t/**\n\t * @brief \u533A\u9593\u53D6\u5F97[l, r)\n\
    \t */\n\tS get(size_t l, size_t r) {\n\t\tassert(l < r and r <= N);\n\t\tS valL\
    \ = e;\n\t\tS valR = e;\n\t\tfor(l += N, r += N; l < r; l >>= 1, r >>= 1) {\n\t\
    \t\tvalL = (l & 1) ? F(valL, v[l++]) : valL;\n\t\t\tvalR = (r & 1) ? F(v[--r],\
    \ valR) : valR;\n\t\t}\n\t\treturn F(valL, valR);\n\t}\n\t/**\n\t * @brief 1\u70B9\
    \u53D6\u5F97\n\t */\n\tS get(const size_t idx) {\n\t\tassert(idx < N);\n\t\treturn\
    \ v[N + idx];\n\t}\n\t/**\n\t * @brief 1\u70B9\u53D6\u5F97\n\t */\n\tS operator[](const\
    \ size_t idx) {\n\t\tassert(idx < N);\n\t\treturn v[N + idx];\n\t}\nprivate:\n\
    \tsize_t N;\n\tvector<S> v;\n\t/**\n\t * @return n <= k \u306A\u308B\u6700\u5C0F\
    \u306E2\u3079\u304D k\n\t */\n\tsize_t pow2(size_t n) {\n\t\tsize_t sz = 1;\n\t\
    \twhile(sz < n) {\n\t\t\tsz <<= 1;\n\t\t}\n\t\treturn sz;\n\t}\n\t/**\n\t * @brief\
    \ v[idx]\u306E\u66F4\u65B0\n\t */\n\tvoid update(size_t idx) {\n\t\tv[idx] = F(v[idx\
    \ << 1], v[(idx << 1) | 1]);\n\t}\n};\n// END CUT HERE"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/SegmentTree.cpp
  requiredBy: []
  timestamp: '2020-09-30 18:45:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_A.test.cpp
  - test/aoj/DSL_2_B.test.cpp
  - test/yosupo/PointAddRangeSum.test.cpp
  - test/yosupo/StaticRangeSum.test.cpp
  - test/yosupo/StaticRMQ.test.cpp
documentation_of: DataStructure/SegmentTree.cpp
layout: document
redirect_from:
- /library/DataStructure/SegmentTree.cpp
- /library/DataStructure/SegmentTree.cpp.html
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
