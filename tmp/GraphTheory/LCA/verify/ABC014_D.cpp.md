---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/GraphTheory/LCA/verify/ABC014_D.cpp\"\nint main(){\r\
    \n    int n; cin>>n;\r\n    vector<vector<int>> g(n+1);\r\n    for(int i=0;i<n-1;i++){\r\
    \n        int x,y; cin>>x>>y;\r\n        g[x].push_back(y);\r\n        g[y].push_back(x);\r\
    \n    }\r\n    LCA lca(n,1,g);\r\n    int q; cin>>q;\r\n    while(q--){\r\n  \
    \      int a,b; cin>>a>>b;\r\n        int ad=lca.depthOrder[lca.nodeFirstID[a]];\r\
    \n        int bd=lca.depthOrder[lca.nodeFirstID[b]];\r\n        int cd=lca.depthOrder[lca.nodeFirstID[lca.get(a,b)]];\r\
    \n        cout<<abs(ad-cd)+abs(bd-cd)+1<<endl;\r\n    }\r\n    return 0;\r\n}\r\
    \n"
  code: "int main(){\r\n    int n; cin>>n;\r\n    vector<vector<int>> g(n+1);\r\n\
    \    for(int i=0;i<n-1;i++){\r\n        int x,y; cin>>x>>y;\r\n        g[x].push_back(y);\r\
    \n        g[y].push_back(x);\r\n    }\r\n    LCA lca(n,1,g);\r\n    int q; cin>>q;\r\
    \n    while(q--){\r\n        int a,b; cin>>a>>b;\r\n        int ad=lca.depthOrder[lca.nodeFirstID[a]];\r\
    \n        int bd=lca.depthOrder[lca.nodeFirstID[b]];\r\n        int cd=lca.depthOrder[lca.nodeFirstID[lca.get(a,b)]];\r\
    \n        cout<<abs(ad-cd)+abs(bd-cd)+1<<endl;\r\n    }\r\n    return 0;\r\n}\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/GraphTheory/LCA/verify/ABC014_D.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/GraphTheory/LCA/verify/ABC014_D.cpp
layout: document
redirect_from:
- /library/tmp/GraphTheory/LCA/verify/ABC014_D.cpp
- /library/tmp/GraphTheory/LCA/verify/ABC014_D.cpp.html
title: tmp/GraphTheory/LCA/verify/ABC014_D.cpp
---
