---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: GraphTheory/StronglyConnectedComponents.cpp
    title: GraphTheory/StronglyConnectedComponents.cpp
  - icon: ':heavy_check_mark:'
    path: GraphTheory/TwoSatisfiability.cpp
    title: GraphTheory/TwoSatisfiability.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/yosupo/TwoSatisfiability.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/two_sat\"\n#include<bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 2 \"GraphTheory/TwoSatisfiability.cpp\"\nusing namespace\
    \ std;\r\n\r\n#line 2 \"GraphTheory/StronglyConnectedComponents.cpp\"\nusing namespace\
    \ std;\n\n// BEGIN CUT HERE\nstruct StronglyConnectedComponents {\n\tconst int\
    \ V;\n\tvector<vector<int>> G, revG;\n\tvector<int> id;\n\tStronglyConnectedComponents(const\
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
    \ num, used);\n\t\t\t}\n\t\t}\n\t}\n};\n// END CUT HERE\n#line 5 \"GraphTheory/TwoSatisfiability.cpp\"\
    \n\r\n// BEGIN CUT HERE\r\nstruct TwoSatisfiability {\r\n\tconst int V;\r\n\t\
    // pos[x] := x\u306E\u771F\u507D\u5024\r\n\tvector<bool> pos;\r\n\tStronglyConnectedComponents\
    \ scc;\r\n\tTwoSatisfiability(const int V) : V(V), pos(vector<bool>(2 * V)), scc(StronglyConnectedComponents(2\
    \ * V)) {}\r\n\t// A -> B <=> not B -> not A\r\n\tinline void addIF(int A, const\
    \ bool Apos, int B, const bool Bpos) {\r\n\t\tif(not Apos) A = NOT(A);\r\n\t\t\
    if(not Bpos) B = NOT(B);\r\n\t\tscc.addEdge(A, B); // A -> B\r\n\t\tscc.addEdge(NOT(B),\
    \ NOT(A)); // not B -> not A\r\n\t}\r\n\t// A <=> (not A -> A)\r\n\tvoid addUNARY(const\
    \ int A, const bool Apos) {\r\n\t\taddIF(A, not Apos, A, Apos); // not A -> A\r\
    \n\t}\r\n\t// A or B <=> not A -> B\r\n\tvoid addOR(const int A, const bool Apos,\
    \ const int B, const bool Bpos) {\r\n\t\taddIF(A, not Apos, B, Bpos); // not A\
    \ -> B\r\n\t}\r\n\t// not(A and B) => A -> not B\r\n\tvoid addNAND(const int A,\
    \ const bool Apos, const int B, const bool Bpos) {\r\n\t\taddIF(A, Apos, B, not\
    \ Bpos); // A -> not B\r\n\t}\r\n\t// A xor B <=> not(A and B) and not(not A and\
    \ not B)\r\n\tvoid addXOR(const int A, const bool Apos, const int B, const bool\
    \ Bpos) {\r\n\t\taddNAND(A, Apos, B, Bpos); // not(A and B)\r\n\t\taddNAND(A,\
    \ not Apos, B, not Bpos); // not(not A and not B)\r\n\t}\r\n\t// not(A xor B)\
    \ <=> A xor not B\r\n\tvoid addXNOR(const int A, const bool Apos, const int B,\
    \ const bool Bpos) {\r\n\t\taddXOR(A, Apos, B, not Bpos); // A xor not B\r\n\t\
    }\r\n\tbool solve() {\r\n\t\tscc.build();\r\n\t\tfor(int i = 0; i < V; ++i) {\r\
    \n\t\t\tif(scc.get(i) == scc.get(i + V)) {\r\n\t\t\t\treturn false;\r\n\t\t\t\
    }\r\n\t\t\tpos[i] = (scc.get(i) > scc.get(i + V));\r\n\t\t}\r\n\t\treturn true;\r\
    \n\t}\r\n\tbool get(int x) {\r\n\t\treturn pos[x];\r\n\t}\r\n\tprivate:\r\n\t\
    constexpr int NOT(const int A) const {\r\n\t\treturn (A + V) % (2 * V);\r\n\t\
    }\r\n};\r\n// END CUT HERE\n#line 6 \"test/yosupo/TwoSatisfiability.test.cpp\"\
    \n\nint main() {\n\tstring p, cnf; cin >> p >> cnf;\n\tint n, m; cin >> n >> m;\n\
    \tTwoSatisfiability sat(n);\n\tfor(int i = 0; i < m; ++i) {\n\t\tint a, b, _0;\
    \ cin >> a >> b >> _0;\n\t\tconst bool apos = a > 0;\n\t\tconst bool bpos = b\
    \ > 0;\n\t\ta = abs(a);\n\t\tb = abs(b);\n\t\t--a, --b;\n\t\tsat.addOR(a, apos,\
    \ b, bpos);\n\t}\n\tif(not sat.solve()) {\n\t\tcout << \"s UNSATISFIABLE\" <<\
    \ '\\n';\n\t\treturn 0;\n\t}\n\tcout << \"s SATISFIABLE\" << '\\n';\n\tcout <<\
    \ \"v \";\n\tfor(int i = 0; i < n; ++i) {\n\t\tcout << (sat.get(i) ? i + 1 : -(i\
    \ + 1)) << \" \";\n\t}\n\tcout << 0 << '\\n';\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../GraphTheory/TwoSatisfiability.cpp\"\n\
    \nint main() {\n\tstring p, cnf; cin >> p >> cnf;\n\tint n, m; cin >> n >> m;\n\
    \tTwoSatisfiability sat(n);\n\tfor(int i = 0; i < m; ++i) {\n\t\tint a, b, _0;\
    \ cin >> a >> b >> _0;\n\t\tconst bool apos = a > 0;\n\t\tconst bool bpos = b\
    \ > 0;\n\t\ta = abs(a);\n\t\tb = abs(b);\n\t\t--a, --b;\n\t\tsat.addOR(a, apos,\
    \ b, bpos);\n\t}\n\tif(not sat.solve()) {\n\t\tcout << \"s UNSATISFIABLE\" <<\
    \ '\\n';\n\t\treturn 0;\n\t}\n\tcout << \"s SATISFIABLE\" << '\\n';\n\tcout <<\
    \ \"v \";\n\tfor(int i = 0; i < n; ++i) {\n\t\tcout << (sat.get(i) ? i + 1 : -(i\
    \ + 1)) << \" \";\n\t}\n\tcout << 0 << '\\n';\n\treturn 0;\n}"
  dependsOn:
  - GraphTheory/TwoSatisfiability.cpp
  - GraphTheory/StronglyConnectedComponents.cpp
  isVerificationFile: true
  path: test/yosupo/TwoSatisfiability.test.cpp
  requiredBy: []
  timestamp: '2020-03-09 22:24:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/TwoSatisfiability.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/TwoSatisfiability.test.cpp
- /verify/test/yosupo/TwoSatisfiability.test.cpp.html
title: test/yosupo/TwoSatisfiability.test.cpp
---
