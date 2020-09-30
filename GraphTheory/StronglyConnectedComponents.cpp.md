---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/TwoSatisfiability.cpp
    title: GraphTheory/TwoSatisfiability.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/StronglyConnectedComponents.test.cpp
    title: test/yosupo/StronglyConnectedComponents.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/TwoSatisfiability.test.cpp
    title: test/yosupo/TwoSatisfiability.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"GraphTheory/StronglyConnectedComponents.cpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n// BEGIN CUT HERE\nstruct StronglyConnectedComponents\
    \ {\n\tconst int V;\n\tvector<vector<int>> G, revG;\n\tvector<int> id;\n\tStronglyConnectedComponents(const\
    \ int V) : V(V), G(vector<vector<int>>(V, vector<int>())), revG(vector<vector<int>>(V,\
    \ vector<int>())), id(vector<int>(V)) {}\n\t// \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\
    \n\tvoid addEdge(const int from, const int to) {\n\t\tG[from].push_back(to);\n\
    \t\trevG[to].push_back(from);\n\t}\n\t// SCC\n\tvoid build() {\n\t\tvector<bool>\
    \ used(V, false);\n\t\tstack<int> st;\n\t\tfor(int from = 0; from < V; ++from)\
    \ {\n\t\t\tif(not used[from]) {\n\t\t\t\tdfs(from, used, st);\n\t\t\t}\n\t\t}\n\
    \t\tint num = 0;\n\t\twhile(not st.empty()) {\n\t\t\tconst int from = st.top();\n\
    \t\t\tst.pop();\n\t\t\tif(used[from]) {\n\t\t\t\trevdfs(from, num, used);\n\t\t\
    \t\t++num;\n\t\t\t}\n\t\t}\n\t}\n\t// x\u306E\u5C5E\u3059\u308B\u96C6\u5408ID\n\
    \tint get(const int x) const {\n\t\treturn id[x];\n\t}\n\n\tprivate:\n\tvoid dfs(const\
    \ int from, vector<bool>& used, stack<int>& st) {\n\t\tused[from] = true;\n\t\t\
    for(const int to : G[from]) {\n\t\t\tif(not used[to]) {\n\t\t\t\tdfs(to, used,\
    \ st);\n\t\t\t}\n\t\t}\n\t\tst.push(from);\n\t}\n\tvoid revdfs(const int from,\
    \ int num, vector<bool>& used) {\n\t\tused[from] = false;\n\t\tid[from] = num;\n\
    \t\tfor(const int to : revG[from]) {\n\t\t\tif(used[to]) {\n\t\t\t\trevdfs(to,\
    \ num, used);\n\t\t\t}\n\t\t}\n\t}\n};\n// END CUT HERE\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// BEGIN CUT HERE\nstruct\
    \ StronglyConnectedComponents {\n\tconst int V;\n\tvector<vector<int>> G, revG;\n\
    \tvector<int> id;\n\tStronglyConnectedComponents(const int V) : V(V), G(vector<vector<int>>(V,\
    \ vector<int>())), revG(vector<vector<int>>(V, vector<int>())), id(vector<int>(V))\
    \ {}\n\t// \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\n\tvoid addEdge(const int from,\
    \ const int to) {\n\t\tG[from].push_back(to);\n\t\trevG[to].push_back(from);\n\
    \t}\n\t// SCC\n\tvoid build() {\n\t\tvector<bool> used(V, false);\n\t\tstack<int>\
    \ st;\n\t\tfor(int from = 0; from < V; ++from) {\n\t\t\tif(not used[from]) {\n\
    \t\t\t\tdfs(from, used, st);\n\t\t\t}\n\t\t}\n\t\tint num = 0;\n\t\twhile(not\
    \ st.empty()) {\n\t\t\tconst int from = st.top();\n\t\t\tst.pop();\n\t\t\tif(used[from])\
    \ {\n\t\t\t\trevdfs(from, num, used);\n\t\t\t\t++num;\n\t\t\t}\n\t\t}\n\t}\n\t\
    // x\u306E\u5C5E\u3059\u308B\u96C6\u5408ID\n\tint get(const int x) const {\n\t\
    \treturn id[x];\n\t}\n\n\tprivate:\n\tvoid dfs(const int from, vector<bool>& used,\
    \ stack<int>& st) {\n\t\tused[from] = true;\n\t\tfor(const int to : G[from]) {\n\
    \t\t\tif(not used[to]) {\n\t\t\t\tdfs(to, used, st);\n\t\t\t}\n\t\t}\n\t\tst.push(from);\n\
    \t}\n\tvoid revdfs(const int from, int num, vector<bool>& used) {\n\t\tused[from]\
    \ = false;\n\t\tid[from] = num;\n\t\tfor(const int to : revG[from]) {\n\t\t\t\
    if(used[to]) {\n\t\t\t\trevdfs(to, num, used);\n\t\t\t}\n\t\t}\n\t}\n};\n// END\
    \ CUT HERE"
  dependsOn: []
  isVerificationFile: false
  path: GraphTheory/StronglyConnectedComponents.cpp
  requiredBy:
  - GraphTheory/TwoSatisfiability.cpp
  timestamp: '2020-03-09 20:54:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/StronglyConnectedComponents.test.cpp
  - test/yosupo/TwoSatisfiability.test.cpp
documentation_of: GraphTheory/StronglyConnectedComponents.cpp
layout: document
redirect_from:
- /library/GraphTheory/StronglyConnectedComponents.cpp
- /library/GraphTheory/StronglyConnectedComponents.cpp.html
title: GraphTheory/StronglyConnectedComponents.cpp
---
