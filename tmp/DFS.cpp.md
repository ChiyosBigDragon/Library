---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/DFS.cpp\"\n// \u6DF1\u3055\u512A\u5148\u63A2\u7D22\r\
    \n// \u8F9E\u66F8\u9806\u6700\u5C0F\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\r\n//\
    \ \u8A08\u7B97\u91CFO(E)\r\n\r\n#include <bits/stdc++.h>\r\n#define rep(i,n) for(int\
    \ i=0;i<n;i++)\r\nusing namespace std;\r\nconst int INF=1<<29;\r\n\r\nint main(){\r\
    \n    //\u521D\u671F\u5316\r\n    int dx[4]={0,1,0,-1};\r\n    int dy[4]={1,0,-1,0};\r\
    \n    stack<pair<int,int>> st;\r\n    int h,w,sy,sx,gy,gx; //\u76E4\u9762,\u30B9\
    \u30BF\u30FC\u30C8,\u30B4\u30FC\u30EB\r\n    cin>>h>>w>>sy>>sx>>gy>>gx;\r\n  \
    \  //sy--; sx--; gy--; gx--;\r\n    char c[h][w]; int d[h][w]; //d[i][j]:=(j,i)\u307E\
    \u3067\u306E\u6700\u77ED\u7D4C\u8DEF\r\n    rep(i,h){\r\n        rep(j,w){\r\n\
    \            cin>>c[i][j]; d[i][j]=INF;\r\n        }\r\n    }\r\n    d[sy][sx]=0;\r\
    \n    st.push(make_pair(sy,sx));\r\n\r\n    //\u5B9F\u884C\r\n    while(st.size()){\r\
    \n        pair<int,int> p=st.top(); //\u30B9\u30BF\u30C3\u30AF\u306E\u6700\u4E0A\
    \u3092\u53D6\u308A\u51FA\u3059\r\n        st.pop(); //\u53D6\u308A\u51FA\u3057\
    \u305F\u3089\u524A\u9664\r\n        int prev=d[p.first][p.second]; //\u4E00\u624B\
    \u524D\u306E\u624B\u6570prev\r\n        rep(i,4){ //4\u65B9\u5411\u63A2\u7D22\r\
    \n            int cy=p.first+dy[i];\r\n            int cx=p.second+dx[i];\r\n\
    \            if(0<=cy&&cy<h&&0<=cx&&cx<w){ //\u7BC4\u56F2\u5916\u53D6\u5F97\u30AD\
    \u30B1\u30F3\r\n                if(c[cy][cx]=='.' and d[cy][cx]==INF){ //\u901A\
    \u884C\u53EF\u80FD\u304B\u3064\u672A\u5230\u9054\r\n                    d[cy][cx]=prev+1;\r\
    \n                    st.push(make_pair(cy,cx)); //\u7A81\u3063\u8FBC\u3080\r\n\
    \                }\r\n            }\r\n        }\r\n    }\r\n    cout<<d[gy][gx]<<endl;\r\
    \n    return 0;\r\n}\r\n"
  code: "// \u6DF1\u3055\u512A\u5148\u63A2\u7D22\r\n// \u8F9E\u66F8\u9806\u6700\u5C0F\
    \u7D4C\u8DEF\u3092\u6C42\u3081\u308B\r\n// \u8A08\u7B97\u91CFO(E)\r\n\r\n#include\
    \ <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\nusing namespace\
    \ std;\r\nconst int INF=1<<29;\r\n\r\nint main(){\r\n    //\u521D\u671F\u5316\r\
    \n    int dx[4]={0,1,0,-1};\r\n    int dy[4]={1,0,-1,0};\r\n    stack<pair<int,int>>\
    \ st;\r\n    int h,w,sy,sx,gy,gx; //\u76E4\u9762,\u30B9\u30BF\u30FC\u30C8,\u30B4\
    \u30FC\u30EB\r\n    cin>>h>>w>>sy>>sx>>gy>>gx;\r\n    //sy--; sx--; gy--; gx--;\r\
    \n    char c[h][w]; int d[h][w]; //d[i][j]:=(j,i)\u307E\u3067\u306E\u6700\u77ED\
    \u7D4C\u8DEF\r\n    rep(i,h){\r\n        rep(j,w){\r\n            cin>>c[i][j];\
    \ d[i][j]=INF;\r\n        }\r\n    }\r\n    d[sy][sx]=0;\r\n    st.push(make_pair(sy,sx));\r\
    \n\r\n    //\u5B9F\u884C\r\n    while(st.size()){\r\n        pair<int,int> p=st.top();\
    \ //\u30B9\u30BF\u30C3\u30AF\u306E\u6700\u4E0A\u3092\u53D6\u308A\u51FA\u3059\r\
    \n        st.pop(); //\u53D6\u308A\u51FA\u3057\u305F\u3089\u524A\u9664\r\n   \
    \     int prev=d[p.first][p.second]; //\u4E00\u624B\u524D\u306E\u624B\u6570prev\r\
    \n        rep(i,4){ //4\u65B9\u5411\u63A2\u7D22\r\n            int cy=p.first+dy[i];\r\
    \n            int cx=p.second+dx[i];\r\n            if(0<=cy&&cy<h&&0<=cx&&cx<w){\
    \ //\u7BC4\u56F2\u5916\u53D6\u5F97\u30AD\u30B1\u30F3\r\n                if(c[cy][cx]=='.'\
    \ and d[cy][cx]==INF){ //\u901A\u884C\u53EF\u80FD\u304B\u3064\u672A\u5230\u9054\
    \r\n                    d[cy][cx]=prev+1;\r\n                    st.push(make_pair(cy,cx));\
    \ //\u7A81\u3063\u8FBC\u3080\r\n                }\r\n            }\r\n       \
    \ }\r\n    }\r\n    cout<<d[gy][gx]<<endl;\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/DFS.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/DFS.cpp
layout: document
redirect_from:
- /library/tmp/DFS.cpp
- /library/tmp/DFS.cpp.html
title: tmp/DFS.cpp
---
