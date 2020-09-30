---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B
  bundledCode: "#line 1 \"tmp/Dijkstra.cpp\"\n// Dijkstra\u6CD5(\u679D\u5208\u308A\
    \u3042\u308A)\r\n// \u59CB\u70B9\u304B\u3089\u5168\u70B9\u9593\u306E\u6700\u77ED\
    \u8DDD\u96E2\u3092\u6C42\u3081\u308B\r\n// \u898B\u3064\u304B\u3089\u306A\u3044\
    \u3068\u304D\u306FINF\r\n// \u8A08\u7B97\u91CFO((E+V)logE)\r\n// verify\r\n//\
    \ http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B\r\n\r\n\
    #include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\nusing namespace\
    \ std;\r\nconst int INF=1145141919,MOD=1e9+7;\r\nconst long long LINF=8931145141919364364,LMOD=998244353;\r\
    \n\r\nconst int VMAX=100010;\r\nint V,E,start,goal;\r\nvector<pair<long long,int>>\
    \ edge[VMAX];\r\nlong long dist[VMAX];\r\nbool used[VMAX];\r\n\r\nvoid dijkstra(){\r\
    \n    // \u8DDD\u96E2\u3092LINF\u3067\u521D\u671F\u5316\r\n    rep(to,VMAX) dist[to]=LINF;\r\
    \n    // \u59CB\u70B9\u306F0\r\n    dist[start]=0;\r\n    // \u30D5\u30E9\u30B0\
    \u3092\u4E0B\u3052\u308B\r\n    rep(v,VMAX) used[v]=false;\r\n    // \u512A\u5148\
    \u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC:[\u8DDD\u96E2,\u9802\u70B9]\u2190\u8DDD\u96E2\
    \u306E\u6607\u9806\r\n    priority_queue<pair<long long,int>,vector<pair<long\
    \ long,int>>,greater<pair<long long,int>>> q;\r\n    // \u8DDD\u96E20,\u59CB\u70B9\
    \r\n    q.push({0,start});\r\n    // dijkstra\r\n    while(q.size()){\r\n    \
    \    // \u53D6\u308A\u51FA\u3057\u3066d=\u8DDD\u96E2,v=\u9802\u70B9\r\n      \
    \  pair<long long,int> p=q.top(); q.pop();\r\n        long long d=p.first;\r\n\
    \        int from=p.second;\r\n        if(used[from]) continue;\r\n        used[from]=true;\r\
    \n        // \u9802\u70B9\u304B\u3089\u51FA\u308B\u8FBA\u3059\u3079\u3066\u306B\
    \u3064\u3044\u3066\r\n        for(auto e:edge[from]){\r\n            long long\
    \ cost=e.first,to=e.second;\r\n            // \u77ED\u7E2E\u3067\u304D\u308B\u3068\
    \u304D\r\n            if(d+cost<dist[to]){\r\n                dist[to]=d+cost;\r\
    \n                q.push({dist[to],to});\r\n            }\r\n        }\r\n   \
    \ }\r\n}\r\n\r\nint main(){\r\n    cin>>V>>E>>start>>goal;\r\n    rep(i,E){\r\n\
    \        int from,to,distance;\r\n        cin>>from>>to>>distance;\r\n       \
    \ edge[from].push_back({distance,to});\r\n        edge[to].push_back({distance,from});\r\
    \n    }\r\n    dijkstra();\r\n    cout<<dist[goal]<<endl;\r\n    return 0;\r\n\
    }\r\n"
  code: "// Dijkstra\u6CD5(\u679D\u5208\u308A\u3042\u308A)\r\n// \u59CB\u70B9\u304B\
    \u3089\u5168\u70B9\u9593\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\
    \r\n// \u898B\u3064\u304B\u3089\u306A\u3044\u3068\u304D\u306FINF\r\n// \u8A08\u7B97\
    \u91CFO((E+V)logE)\r\n// verify\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B\r\
    \n\r\n#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\nusing\
    \ namespace std;\r\nconst int INF=1145141919,MOD=1e9+7;\r\nconst long long LINF=8931145141919364364,LMOD=998244353;\r\
    \n\r\nconst int VMAX=100010;\r\nint V,E,start,goal;\r\nvector<pair<long long,int>>\
    \ edge[VMAX];\r\nlong long dist[VMAX];\r\nbool used[VMAX];\r\n\r\nvoid dijkstra(){\r\
    \n    // \u8DDD\u96E2\u3092LINF\u3067\u521D\u671F\u5316\r\n    rep(to,VMAX) dist[to]=LINF;\r\
    \n    // \u59CB\u70B9\u306F0\r\n    dist[start]=0;\r\n    // \u30D5\u30E9\u30B0\
    \u3092\u4E0B\u3052\u308B\r\n    rep(v,VMAX) used[v]=false;\r\n    // \u512A\u5148\
    \u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC:[\u8DDD\u96E2,\u9802\u70B9]\u2190\u8DDD\u96E2\
    \u306E\u6607\u9806\r\n    priority_queue<pair<long long,int>,vector<pair<long\
    \ long,int>>,greater<pair<long long,int>>> q;\r\n    // \u8DDD\u96E20,\u59CB\u70B9\
    \r\n    q.push({0,start});\r\n    // dijkstra\r\n    while(q.size()){\r\n    \
    \    // \u53D6\u308A\u51FA\u3057\u3066d=\u8DDD\u96E2,v=\u9802\u70B9\r\n      \
    \  pair<long long,int> p=q.top(); q.pop();\r\n        long long d=p.first;\r\n\
    \        int from=p.second;\r\n        if(used[from]) continue;\r\n        used[from]=true;\r\
    \n        // \u9802\u70B9\u304B\u3089\u51FA\u308B\u8FBA\u3059\u3079\u3066\u306B\
    \u3064\u3044\u3066\r\n        for(auto e:edge[from]){\r\n            long long\
    \ cost=e.first,to=e.second;\r\n            // \u77ED\u7E2E\u3067\u304D\u308B\u3068\
    \u304D\r\n            if(d+cost<dist[to]){\r\n                dist[to]=d+cost;\r\
    \n                q.push({dist[to],to});\r\n            }\r\n        }\r\n   \
    \ }\r\n}\r\n\r\nint main(){\r\n    cin>>V>>E>>start>>goal;\r\n    rep(i,E){\r\n\
    \        int from,to,distance;\r\n        cin>>from>>to>>distance;\r\n       \
    \ edge[from].push_back({distance,to});\r\n        edge[to].push_back({distance,from});\r\
    \n    }\r\n    dijkstra();\r\n    cout<<dist[goal]<<endl;\r\n    return 0;\r\n\
    }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/Dijkstra.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/Dijkstra.cpp
layout: document
redirect_from:
- /library/tmp/Dijkstra.cpp
- /library/tmp/Dijkstra.cpp.html
title: tmp/Dijkstra.cpp
---
