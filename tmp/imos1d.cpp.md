---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/imos1d.cpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\ntemplate<class T>\r\nstruct imos1d{\r\n    vector<T> board;\r\n\
    \    imos1d(int n)\r\n        :board(n+2)\r\n    {}\r\n    // \u77E9\u5F62\u52A0\
    \u7B97\r\n    void add(pair<int,int> lr,T z){\r\n        int l=lr.first,r=lr.second;\r\
    \n        board[l]+=z;\r\n        board[r+1]-=z;\r\n    }\r\n    // \u7D2F\u7A4D\
    \u548C\r\n    void build(){\r\n        for(int i=1;i<(int)board.size();i++){\r\
    \n            board[i]+=board[i-1];\r\n        }\r\n    }\r\n    // \u5024\u53D6\
    \u5F97\r\n    T get(int i){\r\n        return board[i];\r\n    }\r\n    // debug\r\
    \n    void debug(){\r\n        for(int i=1;i<(int)board.size()-1;i++){\r\n   \
    \         cout<<board[i]<<\" \";\r\n        }\r\n        cout<<endl;\r\n    }\r\
    \n};\r\n// verify\r\nint main(){\r\n    return 0;\r\n}\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\ntemplate<class T>\r\
    \nstruct imos1d{\r\n    vector<T> board;\r\n    imos1d(int n)\r\n        :board(n+2)\r\
    \n    {}\r\n    // \u77E9\u5F62\u52A0\u7B97\r\n    void add(pair<int,int> lr,T\
    \ z){\r\n        int l=lr.first,r=lr.second;\r\n        board[l]+=z;\r\n     \
    \   board[r+1]-=z;\r\n    }\r\n    // \u7D2F\u7A4D\u548C\r\n    void build(){\r\
    \n        for(int i=1;i<(int)board.size();i++){\r\n            board[i]+=board[i-1];\r\
    \n        }\r\n    }\r\n    // \u5024\u53D6\u5F97\r\n    T get(int i){\r\n   \
    \     return board[i];\r\n    }\r\n    // debug\r\n    void debug(){\r\n     \
    \   for(int i=1;i<(int)board.size()-1;i++){\r\n            cout<<board[i]<<\"\
    \ \";\r\n        }\r\n        cout<<endl;\r\n    }\r\n};\r\n// verify\r\nint main(){\r\
    \n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/imos1d.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/imos1d.cpp
layout: document
redirect_from:
- /library/tmp/imos1d.cpp
- /library/tmp/imos1d.cpp.html
title: tmp/imos1d.cpp
---
