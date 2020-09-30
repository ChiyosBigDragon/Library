---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/LowestCommonAncestor.test.cpp
    title: test/yosupo/LowestCommonAncestor.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"GraphTheory/LowestCommonAncestor.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// BEGIN CUT HERE\nstruct LowestCommonAncestor {\n\tconst\
    \ int DEPTH_MAX = 30;\n\tconst int V;\n\tconst int root;\n\tvector<vector<int>>\
    \ edge;\n\tvector<int> depth;\n\tvector<vector<int>> par;\n\tLowestCommonAncestor(const\
    \ int V, const int root = 0) : V(V), root(root), edge(vector<vector<int>>(V, vector<int>())),\
    \ depth(vector<int>(V)), par(vector<vector<int>>(V, vector<int>(DEPTH_MAX, root)))\
    \ {}\n\tLowestCommonAncestor(const int V, const vector<vector<int>>& edge, const\
    \ int root = 0) : V(V), edge(edge), root(root), depth(vector<int>(V)), par(vector<vector<int>>(V,\
    \ vector<int>(DEPTH_MAX, root))) {\n\t\tbuild();\n\t}\n\tvoid addEdge(const int\
    \ from, const int to) {\n\t\tedge[from].push_back(to);\n\t\tedge[to].push_back(from);\n\
    \t}\n\tvoid build() {\n\t\tdfs(root, root, 0);\n\t\tdoubling();\n\t}\n\t// l\u3068\
    r\u306E\u5171\u901A\u7956\u5148\n\tint get(int l, int r) {\n\t\tif(depth[l] <\
    \ depth[r]) swap(l, r);\n\t\tint diff = depth[l] - depth[r];\n\t\tfor(int i =\
    \ 0; i < DEPTH_MAX; ++i) {\n\t\t\tif(diff >> i & 1) {\n\t\t\t\tl = par[l][i];\n\
    \t\t\t}\n\t\t}\n\t\tif(l == r) {\n\t\t\treturn l;\n\t\t}\n\t\tfor(int i = DEPTH_MAX\
    \ - 1; i >= 0; --i) {\n\t\t\tif(par[l][i] != par[r][i]) {\n\t\t\t\tl = par[l][i];\n\
    \t\t\t\tr = par[r][i];\n\t\t\t}\n\t\t}\n\t\treturn par[l][0];\n\t}\n\t\n\tprivate:\n\
    \tvoid dfs(const int from, const int _par, const int d) {\n\t\tdepth[from] = d;\n\
    \t\tpar[from][0] = _par;\n\t\tfor(const int to : edge[from]) {\n\t\t\tif(to ==\
    \ _par) continue;\n\t\t\tdfs(to, from, d + 1);\n\t\t}\n\t}\n\tvoid doubling()\
    \ {\n\t\tfor(int j = 1; j < DEPTH_MAX; ++j) {\n\t\t\tfor(int i = 0; i < V; ++i)\
    \ {\n\t\t\t\tpar[i][j] = par[par[i][j - 1]][j - 1];\n\t\t\t}\n\t\t}\n\t}\n};\n\
    // END CUT HERE\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// BEGIN CUT HERE\nstruct\
    \ LowestCommonAncestor {\n\tconst int DEPTH_MAX = 30;\n\tconst int V;\n\tconst\
    \ int root;\n\tvector<vector<int>> edge;\n\tvector<int> depth;\n\tvector<vector<int>>\
    \ par;\n\tLowestCommonAncestor(const int V, const int root = 0) : V(V), root(root),\
    \ edge(vector<vector<int>>(V, vector<int>())), depth(vector<int>(V)), par(vector<vector<int>>(V,\
    \ vector<int>(DEPTH_MAX, root))) {}\n\tLowestCommonAncestor(const int V, const\
    \ vector<vector<int>>& edge, const int root = 0) : V(V), edge(edge), root(root),\
    \ depth(vector<int>(V)), par(vector<vector<int>>(V, vector<int>(DEPTH_MAX, root)))\
    \ {\n\t\tbuild();\n\t}\n\tvoid addEdge(const int from, const int to) {\n\t\tedge[from].push_back(to);\n\
    \t\tedge[to].push_back(from);\n\t}\n\tvoid build() {\n\t\tdfs(root, root, 0);\n\
    \t\tdoubling();\n\t}\n\t// l\u3068r\u306E\u5171\u901A\u7956\u5148\n\tint get(int\
    \ l, int r) {\n\t\tif(depth[l] < depth[r]) swap(l, r);\n\t\tint diff = depth[l]\
    \ - depth[r];\n\t\tfor(int i = 0; i < DEPTH_MAX; ++i) {\n\t\t\tif(diff >> i &\
    \ 1) {\n\t\t\t\tl = par[l][i];\n\t\t\t}\n\t\t}\n\t\tif(l == r) {\n\t\t\treturn\
    \ l;\n\t\t}\n\t\tfor(int i = DEPTH_MAX - 1; i >= 0; --i) {\n\t\t\tif(par[l][i]\
    \ != par[r][i]) {\n\t\t\t\tl = par[l][i];\n\t\t\t\tr = par[r][i];\n\t\t\t}\n\t\
    \t}\n\t\treturn par[l][0];\n\t}\n\t\n\tprivate:\n\tvoid dfs(const int from, const\
    \ int _par, const int d) {\n\t\tdepth[from] = d;\n\t\tpar[from][0] = _par;\n\t\
    \tfor(const int to : edge[from]) {\n\t\t\tif(to == _par) continue;\n\t\t\tdfs(to,\
    \ from, d + 1);\n\t\t}\n\t}\n\tvoid doubling() {\n\t\tfor(int j = 1; j < DEPTH_MAX;\
    \ ++j) {\n\t\t\tfor(int i = 0; i < V; ++i) {\n\t\t\t\tpar[i][j] = par[par[i][j\
    \ - 1]][j - 1];\n\t\t\t}\n\t\t}\n\t}\n};\n// END CUT HERE\n"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/LowestCommonAncestor.cpp
  requiredBy: []
  timestamp: '2020-03-10 14:31:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/LowestCommonAncestor.test.cpp
documentation_of: GraphTheory/LowestCommonAncestor.cpp
layout: document
redirect_from:
- /library/GraphTheory/LowestCommonAncestor.cpp
- /library/GraphTheory/LowestCommonAncestor.cpp.html
title: GraphTheory/LowestCommonAncestor.cpp
---
