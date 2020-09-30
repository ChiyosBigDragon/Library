---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/DFSsaiki.cpp\"\n// \u6DF1\u3055\u512A\u5148\u63A2\u7D22\
    (\u518D\u5E30)\r\n// \u8F9E\u66F8\u9806\u6700\u5C0F\u7D4C\u8DEF\u3092\u6C42\u3081\
    \u308B\r\n// \u8A08\u7B97\u91CFO(E)\r\n\r\n#include <bits/stdc++.h>\r\n#define\
    \ rep(i,n) for(int i=0;i<n;i++)\r\nusing namespace std;\r\nconst int INF=INT_MAX,MOD=1e9+7;\r\
    \n\r\nint n,m,ans=0;\r\nint a[10][10]={};\r\nbool visited[10];\r\n\r\nint dfs(int\
    \ now){\r\n\tvisited[now]=1;\r\n\tbool all=1;\r\n\trep(i,n){\r\n\t\tif(!visited[i])\
    \ all=0;\r\n\t}\r\n\tif(all) return ++ans;\r\n\trep(i,n){\r\n\t\tif(visited[i])\
    \ continue;\r\n\t\tif(!a[now][i]) continue;\r\n\t\tdfs(i);\r\n\t\tvisited[i]=0;\r\
    \n\t}\r\n\treturn ans;\r\n}\r\n\r\nint main(){\r\n\tcin>>n>>m;\r\n\trep(i,m){\r\
    \n\t\tint b,c; cin>>b>>c;\r\n\t\ta[b-1][c-1]=a[c-1][b-1]=1;\r\n\t}\r\n\trep(i,n)\
    \ visited[i]=0;\r\n\tcout<<dfs(0)<<endl;\r\n\treturn 0;\r\n}\r\n"
  code: "// \u6DF1\u3055\u512A\u5148\u63A2\u7D22(\u518D\u5E30)\r\n// \u8F9E\u66F8\u9806\
    \u6700\u5C0F\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\r\n// \u8A08\u7B97\u91CFO(E)\r\
    \n\r\n#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\nusing\
    \ namespace std;\r\nconst int INF=INT_MAX,MOD=1e9+7;\r\n\r\nint n,m,ans=0;\r\n\
    int a[10][10]={};\r\nbool visited[10];\r\n\r\nint dfs(int now){\r\n\tvisited[now]=1;\r\
    \n\tbool all=1;\r\n\trep(i,n){\r\n\t\tif(!visited[i]) all=0;\r\n\t}\r\n\tif(all)\
    \ return ++ans;\r\n\trep(i,n){\r\n\t\tif(visited[i]) continue;\r\n\t\tif(!a[now][i])\
    \ continue;\r\n\t\tdfs(i);\r\n\t\tvisited[i]=0;\r\n\t}\r\n\treturn ans;\r\n}\r\
    \n\r\nint main(){\r\n\tcin>>n>>m;\r\n\trep(i,m){\r\n\t\tint b,c; cin>>b>>c;\r\n\
    \t\ta[b-1][c-1]=a[c-1][b-1]=1;\r\n\t}\r\n\trep(i,n) visited[i]=0;\r\n\tcout<<dfs(0)<<endl;\r\
    \n\treturn 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/DFSsaiki.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/DFSsaiki.cpp
layout: document
redirect_from:
- /library/tmp/DFSsaiki.cpp
- /library/tmp/DFSsaiki.cpp.html
title: tmp/DFSsaiki.cpp
---
