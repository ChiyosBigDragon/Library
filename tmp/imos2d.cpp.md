---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc005/tasks/abc005_4
    - https://beta.atcoder.jp/contests/abc106/tasks/abc106_d
  bundledCode: "#line 1 \"tmp/imos2d.cpp\"\n// \u77E9\u5F62\u6307\u5B9A\u306B\u306F\
    {\u5DE6\u4E0A},{\u53F3\u4E0B}\r\n\r\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\ntemplate<class T>\r\nstruct imos2d{\r\n    vector<vector<T>> board;\r\
    \n    imos2d(int w,int h)\r\n        :board(w+2,vector<int>(h+2,0))\r\n    {}\r\
    \n    // 1\u70B9\u52A0\u7B97\r\n    void add(pair<int,int> yx,T z){\r\n      \
    \  int y=yx.first,x=yx.second;\r\n        board[y][x]+=z;\r\n    }\r\n    // \u77E9\
    \u5F62\u52A0\u7B97\r\n    void addrec(pair<int,int> yx1,pair<int,int> yx2,T z){\r\
    \n        int y1=yx1.first,x1=yx1.second;\r\n        int y2=yx2.first,x2=yx2.second;\r\
    \n        board[y1][x1]+=z;\r\n        board[y1][x2+1]-=z;\r\n        board[y2+1][x1]-=z;\r\
    \n        board[y2+1][x2+1]+=z;\r\n    }\r\n    // \u7D2F\u7A4D\u548C\r\n    void\
    \ build(){\r\n        for(int y=1;y<(int)board.size();y++){\r\n            for(int\
    \ x=1;x<(int)board[0].size();x++){\r\n                board[y][x]+=board[y][x-1];\r\
    \n            }\r\n        }\r\n        for(int y=1;y<(int)board.size();y++){\r\
    \n            for(int x=1;x<(int)board[0].size();x++){\r\n                board[y][x]+=board[y-1][x];\r\
    \n            }\r\n        }\r\n    }\r\n    // 1\u70B9\u53D6\u5F97\r\n    T get(pair<int,int>\
    \ yx){\r\n        int y=yx.first,x=yx.second;\r\n        return board[y][x];\r\
    \n    }\r\n    // \u77E9\u5F62\u53D6\u5F97\r\n    T getrec(pair<int,int> yx1,pair<int,int>\
    \ yx2){\r\n        int y1=yx1.first,x1=yx1.second;\r\n        int y2=yx2.first,x2=yx2.second;\r\
    \n        return board[y2][x2]-board[y2][x1-1]-board[y1-1][x2]+board[y1-1][x1-1];\r\
    \n    }\r\n    // debug\r\n    void debug(){\r\n        for(int y=1;y<(int)board.size()-1;y++){\r\
    \n            for(int x=1;x<(int)board[0].size()-1;x++){\r\n                cout<<board[y][x]<<\"\
    \ \";\r\n            }\r\n            cout<<endl;\r\n        }\r\n    }\r\n};\r\
    \n// verify\r\n// https://beta.atcoder.jp/contests/abc106/tasks/abc106_d\r\nint\
    \ main(){\r\n    int n,m,q; cin>>n>>m>>q;\r\n    imos2d<int> imos(n,n);\r\n  \
    \  while(m--){\r\n        int l,r; cin>>l>>r;\r\n        imos.addrec({1,r},{l,n},1);\r\
    \n    }\r\n    imos.build();\r\n    while(q--){\r\n        int l,r; cin>>l>>r;\r\
    \n        cout<<imos.get({l,r})<<endl;\r\n    }\r\n    return 0;\r\n}\r\n// https://atcoder.jp/contests/abc005/tasks/abc005_4\r\
    \n// int main(){\r\n//     int n; cin>>n;\r\n//     imos2d<int> imos(n,n);\r\n\
    //     for(int y=1;y<=n;y++){\r\n//         for(int x=1;x<=n;x++){\r\n//     \
    \        int d; cin>>d;\r\n//             imos.add({y,x},d);\r\n//         }\r\
    \n//     }\r\n//     imos.build();\r\n//     int ans[n*n+1]={};\r\n//     for(int\
    \ p=1;p<=n*n;p++){\r\n//         ans[p]=ans[p-1];\r\n//         for(int w=1;w<=p;w++){\r\
    \n//             int h=p/w;\r\n//             for(int ky=1;ky+h-1<=n;ky++){\r\n\
    //                 for(int kx=1;kx+w-1<=n;kx++){\r\n//                     ans[p]=max(ans[p],imos.getrec({ky,kx},{ky+h-1,kx+w-1}));\r\
    \n//                 }\r\n//             }\r\n//         }\r\n//     }\r\n// \
    \    int q; cin>>q;\r\n//     while(q--){\r\n//         int p; cin>>p;\r\n// \
    \        cout<<ans[p]<<endl;\r\n//     }\r\n//     return 0;\r\n// }\r\n"
  code: "// \u77E9\u5F62\u6307\u5B9A\u306B\u306F{\u5DE6\u4E0A},{\u53F3\u4E0B}\r\n\r\
    \n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\ntemplate<class T>\r\n\
    struct imos2d{\r\n    vector<vector<T>> board;\r\n    imos2d(int w,int h)\r\n\
    \        :board(w+2,vector<int>(h+2,0))\r\n    {}\r\n    // 1\u70B9\u52A0\u7B97\
    \r\n    void add(pair<int,int> yx,T z){\r\n        int y=yx.first,x=yx.second;\r\
    \n        board[y][x]+=z;\r\n    }\r\n    // \u77E9\u5F62\u52A0\u7B97\r\n    void\
    \ addrec(pair<int,int> yx1,pair<int,int> yx2,T z){\r\n        int y1=yx1.first,x1=yx1.second;\r\
    \n        int y2=yx2.first,x2=yx2.second;\r\n        board[y1][x1]+=z;\r\n   \
    \     board[y1][x2+1]-=z;\r\n        board[y2+1][x1]-=z;\r\n        board[y2+1][x2+1]+=z;\r\
    \n    }\r\n    // \u7D2F\u7A4D\u548C\r\n    void build(){\r\n        for(int y=1;y<(int)board.size();y++){\r\
    \n            for(int x=1;x<(int)board[0].size();x++){\r\n                board[y][x]+=board[y][x-1];\r\
    \n            }\r\n        }\r\n        for(int y=1;y<(int)board.size();y++){\r\
    \n            for(int x=1;x<(int)board[0].size();x++){\r\n                board[y][x]+=board[y-1][x];\r\
    \n            }\r\n        }\r\n    }\r\n    // 1\u70B9\u53D6\u5F97\r\n    T get(pair<int,int>\
    \ yx){\r\n        int y=yx.first,x=yx.second;\r\n        return board[y][x];\r\
    \n    }\r\n    // \u77E9\u5F62\u53D6\u5F97\r\n    T getrec(pair<int,int> yx1,pair<int,int>\
    \ yx2){\r\n        int y1=yx1.first,x1=yx1.second;\r\n        int y2=yx2.first,x2=yx2.second;\r\
    \n        return board[y2][x2]-board[y2][x1-1]-board[y1-1][x2]+board[y1-1][x1-1];\r\
    \n    }\r\n    // debug\r\n    void debug(){\r\n        for(int y=1;y<(int)board.size()-1;y++){\r\
    \n            for(int x=1;x<(int)board[0].size()-1;x++){\r\n                cout<<board[y][x]<<\"\
    \ \";\r\n            }\r\n            cout<<endl;\r\n        }\r\n    }\r\n};\r\
    \n// verify\r\n// https://beta.atcoder.jp/contests/abc106/tasks/abc106_d\r\nint\
    \ main(){\r\n    int n,m,q; cin>>n>>m>>q;\r\n    imos2d<int> imos(n,n);\r\n  \
    \  while(m--){\r\n        int l,r; cin>>l>>r;\r\n        imos.addrec({1,r},{l,n},1);\r\
    \n    }\r\n    imos.build();\r\n    while(q--){\r\n        int l,r; cin>>l>>r;\r\
    \n        cout<<imos.get({l,r})<<endl;\r\n    }\r\n    return 0;\r\n}\r\n// https://atcoder.jp/contests/abc005/tasks/abc005_4\r\
    \n// int main(){\r\n//     int n; cin>>n;\r\n//     imos2d<int> imos(n,n);\r\n\
    //     for(int y=1;y<=n;y++){\r\n//         for(int x=1;x<=n;x++){\r\n//     \
    \        int d; cin>>d;\r\n//             imos.add({y,x},d);\r\n//         }\r\
    \n//     }\r\n//     imos.build();\r\n//     int ans[n*n+1]={};\r\n//     for(int\
    \ p=1;p<=n*n;p++){\r\n//         ans[p]=ans[p-1];\r\n//         for(int w=1;w<=p;w++){\r\
    \n//             int h=p/w;\r\n//             for(int ky=1;ky+h-1<=n;ky++){\r\n\
    //                 for(int kx=1;kx+w-1<=n;kx++){\r\n//                     ans[p]=max(ans[p],imos.getrec({ky,kx},{ky+h-1,kx+w-1}));\r\
    \n//                 }\r\n//             }\r\n//         }\r\n//     }\r\n// \
    \    int q; cin>>q;\r\n//     while(q--){\r\n//         int p; cin>>p;\r\n// \
    \        cout<<ans[p]<<endl;\r\n//     }\r\n//     return 0;\r\n// }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/imos2d.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/imos2d.cpp
layout: document
redirect_from:
- /library/tmp/imos2d.cpp
- /library/tmp/imos2d.cpp.html
title: tmp/imos2d.cpp
---
