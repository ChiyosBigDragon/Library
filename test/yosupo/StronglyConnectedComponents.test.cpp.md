---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/StronglyConnectedComponents.cpp
    title: GraphTheory/StronglyConnectedComponents.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/yosupo/StronglyConnectedComponents.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 2 \"GraphTheory/StronglyConnectedComponents.cpp\"\n\
    using namespace std;\n\n// BEGIN CUT HERE\nstruct StronglyConnectedComponents\
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
    \ num, used);\n\t\t\t}\n\t\t}\n\t}\n};\n// END CUT HERE\n#line 6 \"test/yosupo/StronglyConnectedComponents.test.cpp\"\
    \n\nint main() {\n\tint n, m; cin >> n >> m;\n\tStronglyConnectedComponents scc(n);\n\
    \tfor(int i = 0; i < m; ++i) {\n\t\tint a, b; cin >> a >> b;\n\t\tscc.addEdge(a,\
    \ b);\n\t}\n\tscc.build();\n\tvector<int> ans[n];\n\tint k = 0;\n\tfor(int i =\
    \ 0; i < n; ++i) {\n\t\tconst int idx = scc.get(i);\n\t\tans[idx].push_back(i);\n\
    \t\tk = max(k, idx + 1);\n\t}\n\tcout << k << '\\n';\n\tfor(int i = 0; i < k;\
    \ ++i) {\n\t\tcout << ans[i].size();\n\t\tfor(const int j : ans[i]) {\n\t\t\t\
    cout << \" \" << j;\n\t\t}\n\t\tcout << '\\n';\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../GraphTheory/StronglyConnectedComponents.cpp\"\
    \n\nint main() {\n\tint n, m; cin >> n >> m;\n\tStronglyConnectedComponents scc(n);\n\
    \tfor(int i = 0; i < m; ++i) {\n\t\tint a, b; cin >> a >> b;\n\t\tscc.addEdge(a,\
    \ b);\n\t}\n\tscc.build();\n\tvector<int> ans[n];\n\tint k = 0;\n\tfor(int i =\
    \ 0; i < n; ++i) {\n\t\tconst int idx = scc.get(i);\n\t\tans[idx].push_back(i);\n\
    \t\tk = max(k, idx + 1);\n\t}\n\tcout << k << '\\n';\n\tfor(int i = 0; i < k;\
    \ ++i) {\n\t\tcout << ans[i].size();\n\t\tfor(const int j : ans[i]) {\n\t\t\t\
    cout << \" \" << j;\n\t\t}\n\t\tcout << '\\n';\n\t}\n\treturn 0;\n}"
  dependsOn:
  - GraphTheory/StronglyConnectedComponents.cpp
  isVerificationFile: true
  path: test/yosupo/StronglyConnectedComponents.test.cpp
  requiredBy: []
  timestamp: '2020-03-09 20:54:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/StronglyConnectedComponents.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/StronglyConnectedComponents.test.cpp
- /verify/test/yosupo/StronglyConnectedComponents.test.cpp.html
title: test/yosupo/StronglyConnectedComponents.test.cpp
---
