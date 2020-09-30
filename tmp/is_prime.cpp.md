---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/is_prime.cpp\"\n// \u7D20\u6570\u5224\u5B9A\r\n\r\n\
    #include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\nusing namespace\
    \ std;\r\nconst int INF=INT_MAX,MOD=1e9+7;\r\n\r\nbool is_prime(int n){\r\n  \
    \  if(n<2) return 0; //\u7D20\u6570\u306F2\u4EE5\u4E0A\r\n\tif(n==2 || n==3) return\
    \ 1; //2,3\u306F\u7D20\u6570\r\n    if(n%2==0 || n%3==0) return 0; //2,3\u306E\
    \u500D\u6570\u3092\u6D88\u53BB\r\n    //\u4EE5\u964D\u7D20\u6570\u306F6k\xB11\u306B\
    \u3057\u304B\u306A\u3044\r\n    if(n%6!=1 && n%6!=5) return 0;\r\n    for(int\
    \ i=5;i*i<=n;i+=6){\r\n        if(n%i==0) return 0; //6k-1\r\n        if(n%(i+2)==0)\
    \ return 0; //6k+1\r\n    }\r\n    return 1;\r\n}\r\n"
  code: "// \u7D20\u6570\u5224\u5B9A\r\n\r\n#include <bits/stdc++.h>\r\n#define rep(i,n)\
    \ for(int i=0;i<n;i++)\r\nusing namespace std;\r\nconst int INF=INT_MAX,MOD=1e9+7;\r\
    \n\r\nbool is_prime(int n){\r\n    if(n<2) return 0; //\u7D20\u6570\u306F2\u4EE5\
    \u4E0A\r\n\tif(n==2 || n==3) return 1; //2,3\u306F\u7D20\u6570\r\n    if(n%2==0\
    \ || n%3==0) return 0; //2,3\u306E\u500D\u6570\u3092\u6D88\u53BB\r\n    //\u4EE5\
    \u964D\u7D20\u6570\u306F6k\xB11\u306B\u3057\u304B\u306A\u3044\r\n    if(n%6!=1\
    \ && n%6!=5) return 0;\r\n    for(int i=5;i*i<=n;i+=6){\r\n        if(n%i==0)\
    \ return 0; //6k-1\r\n        if(n%(i+2)==0) return 0; //6k+1\r\n    }\r\n   \
    \ return 1;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/is_prime.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/is_prime.cpp
layout: document
redirect_from:
- /library/tmp/is_prime.cpp
- /library/tmp/is_prime.cpp.html
title: tmp/is_prime.cpp
---
