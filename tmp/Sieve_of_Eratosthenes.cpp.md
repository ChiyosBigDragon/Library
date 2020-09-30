---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/Sieve_of_Eratosthenes.cpp\"\n// \u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9\r\n// \u7D20\u6570\u3092\u5217\u6319\r\n// \u8A08\
    \u7B97\u91CFO(NloglogN)\r\n\r\n#include <bits/stdc++.h>\r\n#define rep(i,n) for(int\
    \ i=0;i<n;i++)\r\nusing namespace std;\r\nconst int INF=INT_MAX,MOD=1e9+7;\r\n\
    \r\n//n\u307E\u3067\u306E\u7D20\u6570\u3092\u5217\u6319\r\nvoid Sieve_of_Eratosthenes(int\
    \ n){\r\n\tn++;\r\n    bool list[n]; rep(i,n) list[i]=1; //\u5168\u6570\u306B\u30D5\
    \u30E9\u30B0\r\n\t//2\u306E\u500D\u6570,3\u306E\u500D\u6570\u2026\u3068\u524A\u3063\
    \u3066\u3044\u304F\r\n    for(int i=2;i*i<n;i++){\r\n        if(list[i]){\r\n\
    \            for(int j=2;i*j<n;j++) list[i*j]=0;\r\n        }\r\n    }\r\n\t//\u30D5\
    \u30E9\u30B0\u304C\u7ACB\u3063\u3066\u3044\u308C\u3070\u7D20\u6570\r\n    for(int\
    \ i=2;i<n;i++){\r\n        if(list[i]) cout<<i<<endl;\r\n    }\r\n}\r\n\r\n//\
    \ int main(){\r\n//  \tSieve_of_Eratosthenes(100);\r\n// }\r\n"
  code: "// \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\r\n// \u7D20\u6570\
    \u3092\u5217\u6319\r\n// \u8A08\u7B97\u91CFO(NloglogN)\r\n\r\n#include <bits/stdc++.h>\r\
    \n#define rep(i,n) for(int i=0;i<n;i++)\r\nusing namespace std;\r\nconst int INF=INT_MAX,MOD=1e9+7;\r\
    \n\r\n//n\u307E\u3067\u306E\u7D20\u6570\u3092\u5217\u6319\r\nvoid Sieve_of_Eratosthenes(int\
    \ n){\r\n\tn++;\r\n    bool list[n]; rep(i,n) list[i]=1; //\u5168\u6570\u306B\u30D5\
    \u30E9\u30B0\r\n\t//2\u306E\u500D\u6570,3\u306E\u500D\u6570\u2026\u3068\u524A\u3063\
    \u3066\u3044\u304F\r\n    for(int i=2;i*i<n;i++){\r\n        if(list[i]){\r\n\
    \            for(int j=2;i*j<n;j++) list[i*j]=0;\r\n        }\r\n    }\r\n\t//\u30D5\
    \u30E9\u30B0\u304C\u7ACB\u3063\u3066\u3044\u308C\u3070\u7D20\u6570\r\n    for(int\
    \ i=2;i<n;i++){\r\n        if(list[i]) cout<<i<<endl;\r\n    }\r\n}\r\n\r\n//\
    \ int main(){\r\n//  \tSieve_of_Eratosthenes(100);\r\n// }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/Sieve_of_Eratosthenes.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/Sieve_of_Eratosthenes.cpp
layout: document
redirect_from:
- /library/tmp/Sieve_of_Eratosthenes.cpp
- /library/tmp/Sieve_of_Eratosthenes.cpp.html
title: tmp/Sieve_of_Eratosthenes.cpp
---
