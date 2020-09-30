---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/Bellman_Ford.cpp\"\n// \u5DE5\u4E8B\u4E2D\r\n\r\n//\
    \ Bellman_Ford\u6CD5\r\n// \u59CB\u70B9\u7D42\u70B9\u9593\u306E\u6700\u77ED\u8DDD\
    \u96E2\u3092\u6C42\u3081\u308B(\u8CA0\u7D4C\u8DEF\u8FBC\u307F)\r\n// \u898B\u3064\
    \u304B\u3089\u306A\u3044\u3068\u304D\u306FINF\r\n// \u9589\u8DEF\u304C\u3042\u308B\
    \u3068\u304D\u306FNEGATIVE CYCLE\u3092\u51FA\u529B\r\n// \u8A08\u7B97\u91CFO(VE)\r\
    \n\r\n#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\nusing\
    \ namespace std;\r\nconst int INF=1e9,MOD=1e9+7; // \u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u3057\u306A\u3044\u3088\u3046\u306BINF\u3092\u3068\u308B\r\n\r\n\r\
    \nstruct edge{\r\n\tint from,to,cost;\r\n};\r\nint V,E;   // \u9802\u70B9\u6570\
    V,\u8FBAE\r\nint start; // \u59CB\u70B9\r\n\r\nvector<int> d; // d[i]:=\u59CB\u70B9\
    \u304B\u3089\u70B9i\u307E\u3067\u306E\u8DDD\u96E2\r\nedge e[2000];\r\n\r\nbool\
    \ Bellman_Ford(int start){\r\n    d=vector<int>(V,INF);     // \u5168\u70B9\u3092\
    INF\u3067\u521D\u671F\u5316\r\n    d[start]=0;               // start\u3068\u306E\
    \u8DDD\u96E20\r\n    for(int i=0;i<V;i++){\r\n\t\tbool update=false;\r\n     \
    \   for(int j=0;j<E;j++){\r\n            if(d[e[j].from]!=INF&&d[e[j].to]>d[e[j].from]+e[j].cost){\r\
    \n                d[e[j].to]=d[e[j].from]+e[j].cost;\r\n                    update=true;\r\
    \n            }\r\n        }\r\n\t\tif(!update) break;\r\n\t\tif(i==V-1&&update){\r\
    \n\t\t\treturn false;\r\n\t\t}\r\n    }\r\n    return true;\r\n}\r\n\r\nint main(){\r\
    \n\tcin>>V>>E>>start;\r\n\t// V*V\u306Egraph\u3092INF\u3067\u521D\u671F\u5316\r\
    \n    rep(i,E){\r\n        cin>>e[i].from>>e[i].to>>e[i].cost;\r\n    }\r\n\t\
    if(!Bellman_Ford(start)){\r\n\t\tcout<<\"NEGATIVE CYCLE\"<<endl;\r\n\t}else{\r\
    \n\t\trep(i,V){\r\n\t        if(d[i]==INF) cout<<\"INF\"<<endl;\r\n\t        else\
    \ cout<<d[i]<<endl;\r\n\t    }\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  code: "// \u5DE5\u4E8B\u4E2D\r\n\r\n// Bellman_Ford\u6CD5\r\n// \u59CB\u70B9\u7D42\
    \u70B9\u9593\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B(\u8CA0\u7D4C\
    \u8DEF\u8FBC\u307F)\r\n// \u898B\u3064\u304B\u3089\u306A\u3044\u3068\u304D\u306F\
    INF\r\n// \u9589\u8DEF\u304C\u3042\u308B\u3068\u304D\u306FNEGATIVE CYCLE\u3092\
    \u51FA\u529B\r\n// \u8A08\u7B97\u91CFO(VE)\r\n\r\n#include <bits/stdc++.h>\r\n\
    #define rep(i,n) for(int i=0;i<n;i++)\r\nusing namespace std;\r\nconst int INF=1e9,MOD=1e9+7;\
    \ // \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u3088\u3046\u306B\
    INF\u3092\u3068\u308B\r\n\r\n\r\nstruct edge{\r\n\tint from,to,cost;\r\n};\r\n\
    int V,E;   // \u9802\u70B9\u6570V,\u8FBAE\r\nint start; // \u59CB\u70B9\r\n\r\n\
    vector<int> d; // d[i]:=\u59CB\u70B9\u304B\u3089\u70B9i\u307E\u3067\u306E\u8DDD\
    \u96E2\r\nedge e[2000];\r\n\r\nbool Bellman_Ford(int start){\r\n    d=vector<int>(V,INF);\
    \     // \u5168\u70B9\u3092INF\u3067\u521D\u671F\u5316\r\n    d[start]=0;    \
    \           // start\u3068\u306E\u8DDD\u96E20\r\n    for(int i=0;i<V;i++){\r\n\
    \t\tbool update=false;\r\n        for(int j=0;j<E;j++){\r\n            if(d[e[j].from]!=INF&&d[e[j].to]>d[e[j].from]+e[j].cost){\r\
    \n                d[e[j].to]=d[e[j].from]+e[j].cost;\r\n                    update=true;\r\
    \n            }\r\n        }\r\n\t\tif(!update) break;\r\n\t\tif(i==V-1&&update){\r\
    \n\t\t\treturn false;\r\n\t\t}\r\n    }\r\n    return true;\r\n}\r\n\r\nint main(){\r\
    \n\tcin>>V>>E>>start;\r\n\t// V*V\u306Egraph\u3092INF\u3067\u521D\u671F\u5316\r\
    \n    rep(i,E){\r\n        cin>>e[i].from>>e[i].to>>e[i].cost;\r\n    }\r\n\t\
    if(!Bellman_Ford(start)){\r\n\t\tcout<<\"NEGATIVE CYCLE\"<<endl;\r\n\t}else{\r\
    \n\t\trep(i,V){\r\n\t        if(d[i]==INF) cout<<\"INF\"<<endl;\r\n\t        else\
    \ cout<<d[i]<<endl;\r\n\t    }\r\n\t}\r\n\treturn 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/Bellman_Ford.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/Bellman_Ford.cpp
layout: document
redirect_from:
- /library/tmp/Bellman_Ford.cpp
- /library/tmp/Bellman_Ford.cpp.html
title: tmp/Bellman_Ford.cpp
---
