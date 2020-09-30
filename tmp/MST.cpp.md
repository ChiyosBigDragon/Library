---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
  bundledCode: "#line 1 \"tmp/MST.cpp\"\n// \u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\
    \u30B9\u30C8(\u30D7\u30EA\u30E0\u6CD5)\r\n// verify\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp\r\
    \n\r\n#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\nusing\
    \ namespace std;\r\n\r\nconst int VMAX=10010;\r\nint V,E;\r\nvector<vector<pair<int,int>>>\
    \ edge;\r\nbool used[VMAX];\r\nlong long MST(int start){\r\n    if(V==1) return\
    \ 0;\r\n    rep(i,VMAX) used[i]=0;\r\n    // {cost,{from,to}}\r\n    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>\
    \ pq;\r\n    for(auto e:edge[start]){\r\n        pq.push({e.second,{start,e.first}});\r\
    \n    }\r\n    long long ret=0;\r\n    int cnt=1;\r\n    while(pq.size()||cnt<V){\r\
    \n        auto e=pq.top(); pq.pop();\r\n        int cost=e.first,from=e.second.first,to=e.second.second;\r\
    \n        used[from]=1;\r\n        if(!used[to]){\r\n            ret+=cost;\r\n\
    \            used[to]=1;\r\n            cnt++;\r\n            for(auto e:edge[to]){\r\
    \n                pq.push({e.second,{to,e.first}});\r\n            }\r\n     \
    \   }\r\n    }\r\n    return (cnt==V?ret:-1);\r\n}\r\nint main(){\r\n    cin>>V>>E;\r\
    \n    edge.resize(V);\r\n    int start;\r\n    rep(i,E){\r\n        int from,to,cost;\
    \ cin>>from>>to>>cost;\r\n        start=from;\r\n        edge[from].push_back({to,cost});\r\
    \n        edge[to].push_back({from,cost});\r\n    }\r\n    cout<<MST(start)<<endl;\r\
    \n    return 0;\r\n}\r\n"
  code: "// \u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8(\u30D7\u30EA\u30E0\
    \u6CD5)\r\n// verify\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp\r\
    \n\r\n#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\nusing\
    \ namespace std;\r\n\r\nconst int VMAX=10010;\r\nint V,E;\r\nvector<vector<pair<int,int>>>\
    \ edge;\r\nbool used[VMAX];\r\nlong long MST(int start){\r\n    if(V==1) return\
    \ 0;\r\n    rep(i,VMAX) used[i]=0;\r\n    // {cost,{from,to}}\r\n    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>\
    \ pq;\r\n    for(auto e:edge[start]){\r\n        pq.push({e.second,{start,e.first}});\r\
    \n    }\r\n    long long ret=0;\r\n    int cnt=1;\r\n    while(pq.size()||cnt<V){\r\
    \n        auto e=pq.top(); pq.pop();\r\n        int cost=e.first,from=e.second.first,to=e.second.second;\r\
    \n        used[from]=1;\r\n        if(!used[to]){\r\n            ret+=cost;\r\n\
    \            used[to]=1;\r\n            cnt++;\r\n            for(auto e:edge[to]){\r\
    \n                pq.push({e.second,{to,e.first}});\r\n            }\r\n     \
    \   }\r\n    }\r\n    return (cnt==V?ret:-1);\r\n}\r\nint main(){\r\n    cin>>V>>E;\r\
    \n    edge.resize(V);\r\n    int start;\r\n    rep(i,E){\r\n        int from,to,cost;\
    \ cin>>from>>to>>cost;\r\n        start=from;\r\n        edge[from].push_back({to,cost});\r\
    \n        edge[to].push_back({from,cost});\r\n    }\r\n    cout<<MST(start)<<endl;\r\
    \n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/MST.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/MST.cpp
layout: document
redirect_from:
- /library/tmp/MST.cpp
- /library/tmp/MST.cpp.html
title: tmp/MST.cpp
---
