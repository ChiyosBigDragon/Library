---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/Dijkstra(Route).cpp\"\n// Dijkstra\u6CD5(\u679D\u5208\
    \u308A\u3042\u308A)(\u7121\u5411\u6728\u7D4C\u8DEF\u63A2\u7D22)\r\n// \u300C\u7D42\
    \u70B9\u300D\u304B\u3089\u5168\u70B9\u9593\u306E\u6700\u77ED\u8DDD\u96E2\u3092\
    \u6C42\u3081\u308B\r\n// \u6700\u77ED\u7D4C\u8DEF\u3092\u8F9E\u66F8\u9806\u6700\
    \u5C0F\u3067\u8868\u793A\r\n// \u8A08\u7B97\u91CFO((E+V)logE)\r\n\r\n#include\
    \ <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\nusing namespace\
    \ std;\r\nconst int INF=INT_MAX;\r\n\r\nconst int VMAX=300;\r\nint V,E,start,goal;\r\
    \nint board[VMAX][VMAX];\r\nint dist[VMAX];\r\nbool used[VMAX];\r\nvector<int>\
    \ route;\r\n\r\nvoid Dijkstra(){\r\n    // \u8DDD\u96E2\u3092INF\u3067\u521D\u671F\
    \u5316\r\n    rep(to,VMAX) dist[to]=INF;\r\n    // \u59CB\u70B9\u306F0\r\n   \
    \ dist[goal]=0;\r\n    // \u30D5\u30E9\u30B0\u3092\u4E0B\u3052\u308B\r\n    rep(v,VMAX)\
    \ used[v]=false;\r\n    // \u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC:[\u8DDD\
    \u96E2,\u9802\u70B9]\u2190\u8DDD\u96E2\u306E\u6607\u9806\r\n    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>\
    \ q;\r\n    // \u8DDD\u96E20,\u59CB\u70B9\r\n    q.push(make_pair(0,goal));\r\n\
    \    // dijkstra\r\n    while(q.size()){\r\n        // \u53D6\u308A\u51FA\u3057\
    \u3066d=\u8DDD\u96E2,v=\u9802\u70B9\r\n        pair<int,int> p=q.top(); q.pop();\r\
    \n        int d=p.first,v=p.second;\r\n        if(used[v]) continue;\r\n     \
    \   used[v]=true;\r\n        // \u9802\u70B9\u304B\u3089\u51FA\u308B\u8FBA\u3059\
    \u3079\u3066\u306B\u3064\u3044\u3066\r\n        for(int to=0;to<V;to++){\r\n \
    \           // \u8FBA\u304C\u5B58\u5728\u3057\u3066\u77ED\u7E2E\u3067\u304D\u308B\
    \u3068\u304D\r\n            if(board[v][to]>0 && d+board[v][to]<dist[to]){\r\n\
    \                dist[to]=d+board[v][to];\r\n                q.push(make_pair(dist[to],to));\r\
    \n            }\r\n        }\r\n    }\r\n}\r\n\r\nvoid Route(int from){\r\n  \
    \  route.push_back(from);\r\n    if(from==goal) return;\r\n    rep(to,V){\r\n\
    \        if(board[from][to]>0){\r\n            // \u6700\u77ED\u8DDD\u96E2\u304B\
    \u3089\u9006\u7B97\u3059\u308B\r\n            if(dist[from]==dist[to]+board[from][to]){\r\
    \n                Route(to);\r\n                return;\r\n            }\r\n \
    \       }\r\n    }\r\n}\r\n\r\nint main(){\r\n    rep(i,VMAX)rep(j,VMAX) board[i][j]=-1;\r\
    \n    cin>>V>>E>>start>>goal;\r\n    rep(i,E){\r\n        int from,to,distance;\r\
    \n        cin>>from>>to>>distance;\r\n        board[from][to]=board[to][from]=distance;\r\
    \n    }\r\n    Dijkstra();\r\n    Route(start);\r\n    for(auto i:route) cout<<i<<(i!=goal?\"\
    \ \":\"\");\r\n    cout<<endl;\r\n    return 0;\r\n}\r\n"
  code: "// Dijkstra\u6CD5(\u679D\u5208\u308A\u3042\u308A)(\u7121\u5411\u6728\u7D4C\
    \u8DEF\u63A2\u7D22)\r\n// \u300C\u7D42\u70B9\u300D\u304B\u3089\u5168\u70B9\u9593\
    \u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\r\n// \u6700\u77ED\u7D4C\
    \u8DEF\u3092\u8F9E\u66F8\u9806\u6700\u5C0F\u3067\u8868\u793A\r\n// \u8A08\u7B97\
    \u91CFO((E+V)logE)\r\n\r\n#include <bits/stdc++.h>\r\n#define rep(i,n) for(int\
    \ i=0;i<n;i++)\r\nusing namespace std;\r\nconst int INF=INT_MAX;\r\n\r\nconst\
    \ int VMAX=300;\r\nint V,E,start,goal;\r\nint board[VMAX][VMAX];\r\nint dist[VMAX];\r\
    \nbool used[VMAX];\r\nvector<int> route;\r\n\r\nvoid Dijkstra(){\r\n    // \u8DDD\
    \u96E2\u3092INF\u3067\u521D\u671F\u5316\r\n    rep(to,VMAX) dist[to]=INF;\r\n\
    \    // \u59CB\u70B9\u306F0\r\n    dist[goal]=0;\r\n    // \u30D5\u30E9\u30B0\u3092\
    \u4E0B\u3052\u308B\r\n    rep(v,VMAX) used[v]=false;\r\n    // \u512A\u5148\u5EA6\
    \u4ED8\u304D\u30AD\u30E5\u30FC:[\u8DDD\u96E2,\u9802\u70B9]\u2190\u8DDD\u96E2\u306E\
    \u6607\u9806\r\n    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>\
    \ q;\r\n    // \u8DDD\u96E20,\u59CB\u70B9\r\n    q.push(make_pair(0,goal));\r\n\
    \    // dijkstra\r\n    while(q.size()){\r\n        // \u53D6\u308A\u51FA\u3057\
    \u3066d=\u8DDD\u96E2,v=\u9802\u70B9\r\n        pair<int,int> p=q.top(); q.pop();\r\
    \n        int d=p.first,v=p.second;\r\n        if(used[v]) continue;\r\n     \
    \   used[v]=true;\r\n        // \u9802\u70B9\u304B\u3089\u51FA\u308B\u8FBA\u3059\
    \u3079\u3066\u306B\u3064\u3044\u3066\r\n        for(int to=0;to<V;to++){\r\n \
    \           // \u8FBA\u304C\u5B58\u5728\u3057\u3066\u77ED\u7E2E\u3067\u304D\u308B\
    \u3068\u304D\r\n            if(board[v][to]>0 && d+board[v][to]<dist[to]){\r\n\
    \                dist[to]=d+board[v][to];\r\n                q.push(make_pair(dist[to],to));\r\
    \n            }\r\n        }\r\n    }\r\n}\r\n\r\nvoid Route(int from){\r\n  \
    \  route.push_back(from);\r\n    if(from==goal) return;\r\n    rep(to,V){\r\n\
    \        if(board[from][to]>0){\r\n            // \u6700\u77ED\u8DDD\u96E2\u304B\
    \u3089\u9006\u7B97\u3059\u308B\r\n            if(dist[from]==dist[to]+board[from][to]){\r\
    \n                Route(to);\r\n                return;\r\n            }\r\n \
    \       }\r\n    }\r\n}\r\n\r\nint main(){\r\n    rep(i,VMAX)rep(j,VMAX) board[i][j]=-1;\r\
    \n    cin>>V>>E>>start>>goal;\r\n    rep(i,E){\r\n        int from,to,distance;\r\
    \n        cin>>from>>to>>distance;\r\n        board[from][to]=board[to][from]=distance;\r\
    \n    }\r\n    Dijkstra();\r\n    Route(start);\r\n    for(auto i:route) cout<<i<<(i!=goal?\"\
    \ \":\"\");\r\n    cout<<endl;\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/Dijkstra(Route).cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/Dijkstra(Route).cpp
layout: document
redirect_from:
- /library/tmp/Dijkstra(Route).cpp
- /library/tmp/Dijkstra(Route).cpp.html
title: tmp/Dijkstra(Route).cpp
---
