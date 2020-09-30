---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/leap_year.cpp\"\n#include <bits/stdc++.h>\r\n#define\
    \ rep(i,n) for(int i=0;i<n;i++)\r\nusing namespace std;\r\nconst int INF=INT_MAX,MOD=1e9+7;\r\
    \n\r\nbool leap_year(int n){\r\n    if(n%400==0) return true;\r\n    if(n%100==0)\
    \ return false;\r\n    if(n%4==0) return true;\r\n    return false;\r\n}\r\n\r\
    \nint main(){\r\n    for(int i=1500;i<=2000;i++){\r\n        if(leap_year(i))\
    \ cout<<i<<endl;\r\n    }\r\n    return 0;\r\n}\r\n"
  code: "#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\nusing\
    \ namespace std;\r\nconst int INF=INT_MAX,MOD=1e9+7;\r\n\r\nbool leap_year(int\
    \ n){\r\n    if(n%400==0) return true;\r\n    if(n%100==0) return false;\r\n \
    \   if(n%4==0) return true;\r\n    return false;\r\n}\r\n\r\nint main(){\r\n \
    \   for(int i=1500;i<=2000;i++){\r\n        if(leap_year(i)) cout<<i<<endl;\r\n\
    \    }\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/leap_year.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/leap_year.cpp
layout: document
redirect_from:
- /library/tmp/leap_year.cpp
- /library/tmp/leap_year.cpp.html
title: tmp/leap_year.cpp
---
