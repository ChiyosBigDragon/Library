---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/LowestCommonAncestor.cpp
    title: GraphTheory/LowestCommonAncestor.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo/LowestCommonAncestor.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 2 \"GraphTheory/LowestCommonAncestor.cpp\"\nusing namespace std;\n\
    \n// BEGIN CUT HERE\nstruct LowestCommonAncestor {\n\tconst int DEPTH_MAX = 30;\n\
    \tconst int V;\n\tconst int root;\n\tvector<vector<int>> edge;\n\tvector<int>\
    \ depth;\n\tvector<vector<int>> par;\n\tLowestCommonAncestor(const int V, const\
    \ int root = 0) : V(V), root(root), edge(vector<vector<int>>(V, vector<int>())),\
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
    // END CUT HERE\n#line 6 \"test/yosupo/LowestCommonAncestor.test.cpp\"\n\nint\
    \ main() {\n\tint n, q; cin >> n >> q;\n\tLowestCommonAncestor lca(n);\n\tfor(int\
    \ i = 1; i <= n - 1; ++i) {\n\t\tint p; cin >> p;\n\t\tlca.addEdge(i, p);\n\t\
    }\n\tlca.build();\n\twhile(q--) {\n\t\tint u, v; cin >> u >> v;\n\t\tcout << lca.get(u,\
    \ v) << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../GraphTheory/LowestCommonAncestor.cpp\"\
    \n\nint main() {\n\tint n, q; cin >> n >> q;\n\tLowestCommonAncestor lca(n);\n\
    \tfor(int i = 1; i <= n - 1; ++i) {\n\t\tint p; cin >> p;\n\t\tlca.addEdge(i,\
    \ p);\n\t}\n\tlca.build();\n\twhile(q--) {\n\t\tint u, v; cin >> u >> v;\n\t\t\
    cout << lca.get(u, v) << '\\n';\n\t}\n\treturn 0;\n}"
  dependsOn:
  - GraphTheory/LowestCommonAncestor.cpp
  isVerificationFile: true
  path: test/yosupo/LowestCommonAncestor.test.cpp
  requiredBy: []
  timestamp: '2020-03-11 17:25:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/LowestCommonAncestor.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/LowestCommonAncestor.test.cpp
- /verify/test/yosupo/LowestCommonAncestor.test.cpp.html
title: test/yosupo/LowestCommonAncestor.test.cpp
---
