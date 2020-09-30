---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/UnionFind.test.cpp
    title: test/yosupo/UnionFind.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/UnionFind.cpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n\r\n// BEGIN CUT HERE\r\nstruct UnionFind {\r\n\tconst\
    \ int V;\r\n\t// par[x] := x\u306Eroot\r\n\tvector<int> par;\r\n\t// sz[x] :=\
    \ x\u3092\u542B\u3080\u96C6\u5408\u306E\u30B5\u30A4\u30BA\r\n\tvector<int> sz;\r\
    \n\tUnionFind(const int V) : V(V), par(vector<int>(V)), sz(vector<int>(V, 1))\
    \ {\r\n\t\tiota(par.begin(), par.end(), 0);\r\n\t}\r\n\t// x\u3068y\u3092\u7D50\
    \u5408\r\n\tbool unite(int x, int y) {\r\n\t\tx = root(x);\r\n\t\ty = root(y);\r\
    \n\t\tif(same(x, y)) {\r\n\t\t\treturn false;\r\n\t\t}\r\n\t\tif(y < x) {\r\n\t\
    \t\tswap(x, y);\r\n\t\t}\r\n\t\tpar[y] = x;\r\n\t\tsz[x] += sz[y];\r\n\t\treturn\
    \ true;\r\n\t}\r\n\t// x\u306E\u96C6\u5408ID\r\n\tint root(const int x) {\r\n\t\
    \tif(par[x] == x) {\r\n\t\t\treturn x;\r\n\t\t}\r\n\t\treturn (par[x] = root(par[x]));\r\
    \n\t}\r\n\t// x\u3068y\u304C\u540C\u3058\u96C6\u5408\u304B\r\n\tbool same(const\
    \ int x, const int y) {\r\n\t\treturn (root(x) == root(y));\r\n\t}\r\n\t// x\u304C\
    \u5C5E\u3059\u308B\u96C6\u5408\u306E\u30B5\u30A4\u30BA\r\n\tint size(const int\
    \ x) {\r\n\t\treturn sz[root(x)];\r\n\t}\r\n};\r\n// END CUT HERE\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n// BEGIN CUT HERE\r\
    \nstruct UnionFind {\r\n\tconst int V;\r\n\t// par[x] := x\u306Eroot\r\n\tvector<int>\
    \ par;\r\n\t// sz[x] := x\u3092\u542B\u3080\u96C6\u5408\u306E\u30B5\u30A4\u30BA\
    \r\n\tvector<int> sz;\r\n\tUnionFind(const int V) : V(V), par(vector<int>(V)),\
    \ sz(vector<int>(V, 1)) {\r\n\t\tiota(par.begin(), par.end(), 0);\r\n\t}\r\n\t\
    // x\u3068y\u3092\u7D50\u5408\r\n\tbool unite(int x, int y) {\r\n\t\tx = root(x);\r\
    \n\t\ty = root(y);\r\n\t\tif(same(x, y)) {\r\n\t\t\treturn false;\r\n\t\t}\r\n\
    \t\tif(y < x) {\r\n\t\t\tswap(x, y);\r\n\t\t}\r\n\t\tpar[y] = x;\r\n\t\tsz[x]\
    \ += sz[y];\r\n\t\treturn true;\r\n\t}\r\n\t// x\u306E\u96C6\u5408ID\r\n\tint\
    \ root(const int x) {\r\n\t\tif(par[x] == x) {\r\n\t\t\treturn x;\r\n\t\t}\r\n\
    \t\treturn (par[x] = root(par[x]));\r\n\t}\r\n\t// x\u3068y\u304C\u540C\u3058\u96C6\
    \u5408\u304B\r\n\tbool same(const int x, const int y) {\r\n\t\treturn (root(x)\
    \ == root(y));\r\n\t}\r\n\t// x\u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u30B5\
    \u30A4\u30BA\r\n\tint size(const int x) {\r\n\t\treturn sz[root(x)];\r\n\t}\r\n\
    };\r\n// END CUT HERE"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/UnionFind.cpp
  requiredBy: []
  timestamp: '2020-03-10 14:39:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/UnionFind.test.cpp
documentation_of: DataStructure/UnionFind.cpp
layout: document
redirect_from:
- /library/DataStructure/UnionFind.cpp
- /library/DataStructure/UnionFind.cpp.html
title: DataStructure/UnionFind.cpp
---
