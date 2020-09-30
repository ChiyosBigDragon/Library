---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc012/tasks/abc012_4
  bundledCode: "#line 1 \"tmp/WarshallFloyd.cpp\"\n// Warshall_Floyd\u6CD5\r\n// 2\u70B9\
    \u9593\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\r\n// \u8A08\u7B97\
    \u91CFO(V^3)\r\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n//\
    \ \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u3088\u3046\u306B\
    INF\u3092\u3068\u308B\r\nconst int INF=1e9;\r\nconst long long LINF=1e15;\r\n\r\
    \ntemplate<class T>\r\nstruct WarshallFloyd{\r\n    // \u9802\u70B9\u6570(1-indexed)\r\
    \n    const int V;\r\n    // d[from][to]:=2\u70B9\u9593\u306E\u6700\u77ED\u8DDD\
    \u96E2\r\n    vector<vector<T>> d;\r\n    WarshallFloyd(const int V):\r\n    \
    \    V(V)\r\n        {\r\n            d=vector<vector<T>>(V+1,vector<T>(V+1,INF));\r\
    \n        }\r\n    void build(){\r\n        for(int i=0;i<=V;i++){           \
    \    //\u7D4C\u7531\u70B9i\r\n            for(int j=0;j<=V;j++){           //\u59CB\
    \u70B9j\r\n                for(int k=0;k<=V;k++){       //\u7D42\u70B9k\r\n  \
    \  \t\t\t\td[j][k]=min(d[j][k],d[j][i]+d[i][k]);\r\n                }\r\n    \
    \        }\r\n    \t}\r\n    }\r\n};\r\n// verify\r\n// https://atcoder.jp/contests/abc012/tasks/abc012_4\r\
    \nint main(){\r\n    int n,m; cin>>n>>m;\r\n    WarshallFloyd<long long> wf(n);\r\
    \n    while(m--){\r\n        int a,b,t; cin>>a>>b>>t;\r\n        wf.d[a][b]=t;\r\
    \n        wf.d[b][a]=t;\r\n    }\r\n    wf.build();\r\n    long long ans=LINF;\r\
    \n    for(int i=1;i<=n;i++){\r\n        long long tmp=0;\r\n        for(int j=1;j<=n;j++){\r\
    \n            if(i==j) continue;\r\n            tmp=max(tmp,wf.d[i][j]);\r\n \
    \       }\r\n        ans=min(ans,tmp);\r\n    }\r\n    cout<<ans<<endl;\r\n  \
    \  return 0;\r\n}\r\n"
  code: "// Warshall_Floyd\u6CD5\r\n// 2\u70B9\u9593\u306E\u6700\u77ED\u8DDD\u96E2\
    \u3092\u6C42\u3081\u308B\r\n// \u8A08\u7B97\u91CFO(V^3)\r\n\r\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n\r\n// \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\
    \u306A\u3044\u3088\u3046\u306BINF\u3092\u3068\u308B\r\nconst int INF=1e9;\r\n\
    const long long LINF=1e15;\r\n\r\ntemplate<class T>\r\nstruct WarshallFloyd{\r\
    \n    // \u9802\u70B9\u6570(1-indexed)\r\n    const int V;\r\n    // d[from][to]:=2\u70B9\
    \u9593\u306E\u6700\u77ED\u8DDD\u96E2\r\n    vector<vector<T>> d;\r\n    WarshallFloyd(const\
    \ int V):\r\n        V(V)\r\n        {\r\n            d=vector<vector<T>>(V+1,vector<T>(V+1,INF));\r\
    \n        }\r\n    void build(){\r\n        for(int i=0;i<=V;i++){           \
    \    //\u7D4C\u7531\u70B9i\r\n            for(int j=0;j<=V;j++){           //\u59CB\
    \u70B9j\r\n                for(int k=0;k<=V;k++){       //\u7D42\u70B9k\r\n  \
    \  \t\t\t\td[j][k]=min(d[j][k],d[j][i]+d[i][k]);\r\n                }\r\n    \
    \        }\r\n    \t}\r\n    }\r\n};\r\n// verify\r\n// https://atcoder.jp/contests/abc012/tasks/abc012_4\r\
    \nint main(){\r\n    int n,m; cin>>n>>m;\r\n    WarshallFloyd<long long> wf(n);\r\
    \n    while(m--){\r\n        int a,b,t; cin>>a>>b>>t;\r\n        wf.d[a][b]=t;\r\
    \n        wf.d[b][a]=t;\r\n    }\r\n    wf.build();\r\n    long long ans=LINF;\r\
    \n    for(int i=1;i<=n;i++){\r\n        long long tmp=0;\r\n        for(int j=1;j<=n;j++){\r\
    \n            if(i==j) continue;\r\n            tmp=max(tmp,wf.d[i][j]);\r\n \
    \       }\r\n        ans=min(ans,tmp);\r\n    }\r\n    cout<<ans<<endl;\r\n  \
    \  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/WarshallFloyd.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/WarshallFloyd.cpp
layout: document
redirect_from:
- /library/tmp/WarshallFloyd.cpp
- /library/tmp/WarshallFloyd.cpp.html
title: tmp/WarshallFloyd.cpp
---
