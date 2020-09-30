---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://beta.atcoder.jp/contests/abc106/tasks/abc106_d
  bundledCode: "#line 1 \"tmp/imos2d0.cpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\ntemplate<class T>\r\nstruct imos2d{\r\n    vector<vector<T>> board;\r\
    \n    imos2d(int w,int h)\r\n        :board(w+2,vector<int>(h+2,0))\r\n    {}\r\
    \n    // \u77E9\u5F62\u52A0\u7B97\r\n    void add(pair<int,int> xy1,pair<int,int>\
    \ xy2,T z){\r\n        int x1=xy1.first,y1=xy1.second;\r\n        int x2=xy2.first,y2=xy2.second;\r\
    \n        board[x1][y1]+=z;\r\n        board[x1][y2+1]-=z;\r\n        board[x2+1][y1]-=z;\r\
    \n        board[x2+1][y2+1]+=z;\r\n    }\r\n    // \u7D2F\u7A4D\u548C\r\n    void\
    \ build(){\r\n        for(int x=1;x<(int)board.size();x++){\r\n            for(int\
    \ y=1;y<(int)board[0].size();y++){\r\n                board[x][y]+=board[x][y-1];\r\
    \n            }\r\n        }\r\n        for(int x=1;x<(int)board.size();x++){\r\
    \n            for(int y=1;y<(int)board[0].size();y++){\r\n                board[x][y]+=board[x-1][y];\r\
    \n            }\r\n        }\r\n    }\r\n    // \u5024\u53D6\u5F97\r\n    T get(int\
    \ x,int y){\r\n        return board[x][y];\r\n    }\r\n    // debug\r\n    void\
    \ debug(){\r\n        for(int x=1;x<(int)board.size()-1;x++){\r\n            for(int\
    \ y=1;y<(int)board[0].size()-1;y++){\r\n                cout<<board[x][y]<<\"\
    \ \";\r\n            }\r\n            cout<<endl;\r\n        }\r\n    }\r\n};\r\
    \n// verify\r\n// https://beta.atcoder.jp/contests/abc106/tasks/abc106_d\r\nint\
    \ main(){\r\n    int n,m,q; cin>>n>>m>>q;\r\n    imos2d<int> imos(n,n);\r\n  \
    \  while(m--){\r\n        int l,r; cin>>l>>r;\r\n        imos.add({1,r},{l,n},1);\r\
    \n    }\r\n    imos.build();\r\n    while(q--){\r\n        int l,r; cin>>l>>r;\r\
    \n        cout<<imos.get(l,r)<<endl;\r\n    }\r\n    return 0;\r\n}\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\ntemplate<class T>\r\
    \nstruct imos2d{\r\n    vector<vector<T>> board;\r\n    imos2d(int w,int h)\r\n\
    \        :board(w+2,vector<int>(h+2,0))\r\n    {}\r\n    // \u77E9\u5F62\u52A0\
    \u7B97\r\n    void add(pair<int,int> xy1,pair<int,int> xy2,T z){\r\n        int\
    \ x1=xy1.first,y1=xy1.second;\r\n        int x2=xy2.first,y2=xy2.second;\r\n \
    \       board[x1][y1]+=z;\r\n        board[x1][y2+1]-=z;\r\n        board[x2+1][y1]-=z;\r\
    \n        board[x2+1][y2+1]+=z;\r\n    }\r\n    // \u7D2F\u7A4D\u548C\r\n    void\
    \ build(){\r\n        for(int x=1;x<(int)board.size();x++){\r\n            for(int\
    \ y=1;y<(int)board[0].size();y++){\r\n                board[x][y]+=board[x][y-1];\r\
    \n            }\r\n        }\r\n        for(int x=1;x<(int)board.size();x++){\r\
    \n            for(int y=1;y<(int)board[0].size();y++){\r\n                board[x][y]+=board[x-1][y];\r\
    \n            }\r\n        }\r\n    }\r\n    // \u5024\u53D6\u5F97\r\n    T get(int\
    \ x,int y){\r\n        return board[x][y];\r\n    }\r\n    // debug\r\n    void\
    \ debug(){\r\n        for(int x=1;x<(int)board.size()-1;x++){\r\n            for(int\
    \ y=1;y<(int)board[0].size()-1;y++){\r\n                cout<<board[x][y]<<\"\
    \ \";\r\n            }\r\n            cout<<endl;\r\n        }\r\n    }\r\n};\r\
    \n// verify\r\n// https://beta.atcoder.jp/contests/abc106/tasks/abc106_d\r\nint\
    \ main(){\r\n    int n,m,q; cin>>n>>m>>q;\r\n    imos2d<int> imos(n,n);\r\n  \
    \  while(m--){\r\n        int l,r; cin>>l>>r;\r\n        imos.add({1,r},{l,n},1);\r\
    \n    }\r\n    imos.build();\r\n    while(q--){\r\n        int l,r; cin>>l>>r;\r\
    \n        cout<<imos.get(l,r)<<endl;\r\n    }\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/imos2d0.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/imos2d0.cpp
layout: document
redirect_from:
- /library/tmp/imos2d0.cpp
- /library/tmp/imos2d0.cpp.html
title: tmp/imos2d0.cpp
---
