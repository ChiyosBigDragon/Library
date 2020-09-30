---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/modPow.cpp\"\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\
    \u6CD5\r\n// \u7D2F\u4E57\u306E\u9AD8\u901F\u5316\r\n// \u8A08\u7B97\u91CFO(logN)\r\
    \n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\nconst int MOD=1e9+7;\r\
    \n\r\n//a^n\u3092\u6C42\u3081\u308B\r\nlong long modpow(long long a,long long\
    \ n){\r\n    long long x=1;\r\n    while(n>0){\r\n        //n\u306E2\u9032\u6570\
    \u8868\u8A18\u306E\u53F3\u7AEF\u304C1\r\n        if(n&1){\r\n            x=x*a%MOD;\r\
    \n        }\r\n        a=a*a%MOD;\r\n        n>>=1; //n\u3092\u53F3\u306B1bit\u305A\
    \u3089\u3059\r\n    }\r\n    return x;\r\n}\r\n\r\nint main(){\r\n    int a,n;\
    \ cin>>a>>n;\r\n    cout<<modpow(a,n)<<endl;\r\n    return 0;\r\n}\r\n"
  code: "// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\r\n// \u7D2F\u4E57\u306E\u9AD8\
    \u901F\u5316\r\n// \u8A08\u7B97\u91CFO(logN)\r\n\r\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\nconst int MOD=1e9+7;\r\n\r\n//a^n\u3092\u6C42\u3081\u308B\
    \r\nlong long modpow(long long a,long long n){\r\n    long long x=1;\r\n    while(n>0){\r\
    \n        //n\u306E2\u9032\u6570\u8868\u8A18\u306E\u53F3\u7AEF\u304C1\r\n    \
    \    if(n&1){\r\n            x=x*a%MOD;\r\n        }\r\n        a=a*a%MOD;\r\n\
    \        n>>=1; //n\u3092\u53F3\u306B1bit\u305A\u3089\u3059\r\n    }\r\n    return\
    \ x;\r\n}\r\n\r\nint main(){\r\n    int a,n; cin>>a>>n;\r\n    cout<<modpow(a,n)<<endl;\r\
    \n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/modPow.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/modPow.cpp
layout: document
redirect_from:
- /library/tmp/modPow.cpp
- /library/tmp/modPow.cpp.html
title: tmp/modPow.cpp
---
