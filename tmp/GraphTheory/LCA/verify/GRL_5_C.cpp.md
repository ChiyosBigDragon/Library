---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/GraphTheory/LCA/verify/GRL_5_C.cpp\"\nint main(){\r\n\
    \    int n; cin>>n;\r\n    vector<vector<int>> g(n+1);\r\n    for(int i=0;i<n;i++){\r\
    \n        int k; cin>>k;\r\n        while(k--){\r\n            int c; cin>>c;\r\
    \n            g[i].push_back(c);\r\n            g[c].push_back(i);\r\n       \
    \ }\r\n    }\r\n    LCA lca(n,0,g);\r\n    int q; cin>>q;\r\n    while(q--){\r\
    \n        int u,v; cin>>u>>v;\r\n        cout<<lca.get(u,v)<<endl;\r\n    }\r\n\
    \    return 0;\r\n}\r\n"
  code: "int main(){\r\n    int n; cin>>n;\r\n    vector<vector<int>> g(n+1);\r\n\
    \    for(int i=0;i<n;i++){\r\n        int k; cin>>k;\r\n        while(k--){\r\n\
    \            int c; cin>>c;\r\n            g[i].push_back(c);\r\n            g[c].push_back(i);\r\
    \n        }\r\n    }\r\n    LCA lca(n,0,g);\r\n    int q; cin>>q;\r\n    while(q--){\r\
    \n        int u,v; cin>>u>>v;\r\n        cout<<lca.get(u,v)<<endl;\r\n    }\r\n\
    \    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/GraphTheory/LCA/verify/GRL_5_C.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/GraphTheory/LCA/verify/GRL_5_C.cpp
layout: document
redirect_from:
- /library/tmp/GraphTheory/LCA/verify/GRL_5_C.cpp
- /library/tmp/GraphTheory/LCA/verify/GRL_5_C.cpp.html
title: tmp/GraphTheory/LCA/verify/GRL_5_C.cpp
---
