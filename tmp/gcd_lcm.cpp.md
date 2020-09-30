---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/gcd_lcm.cpp\"\n// \u6700\u5927\u516C\u7D04\u6570\r\n\
    \r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\ninline long long mod(long\
    \ long n,long long m){return(n%m+m)%m;}\r\n\r\nlong long gcd(long long x,long\
    \ long y){\r\n    return y>0?gcd(y,x%y):x;\r\n}\r\nlong long lcm(long long x,long\
    \ long y){\r\n    return x/gcd(x,y)*y;\r\n}\r\n// gcd(a,b)\u3068ax+by=gcd(a,b)\u3092\
    \u6E80\u305F\u3059(x,y)\r\nlong long ex_gcd(long long a,long long b,long long\
    \ &x,long long &y){\r\n    if(b==0){\r\n        // gcd(a,b)x+0y=gcd(a,b)\r\n \
    \       x=1,y=0;\r\n        return a;\r\n    }\r\n    long long d=ex_gcd(b,a%b,y,x);\r\
    \n    y-=a/b*x;\r\n    return d;\r\n}\r\n// x\u2261{b}(mod{m})\u3092\u6E80\u305F\
    \u3059x(mod(lcm{m}))\r\nlong long CRT(vector<long long> b,vector<long long> m){\r\
    \n    // x\u22610(mod1)\u306F\u5168\u3066\u306E\u6574\u6570\r\n    long long ret=0,M=1;\r\
    \n    for(int i=0;i<(int)b.size();i++){\r\n        long long x,y;\r\n        long\
    \ long d=ex_gcd(M,m[i],x,y);\r\n        if((b[i]-ret)%d) return -1;\r\n      \
    \  // \u6700\u5F8C\u306BM\u3067\u5272\u308B\u306E\u3067\u5171\u901A\u3057\u306A\
    \u3044\u3082\u306E\u3067\u5270\u4F59\r\n        ret+=(b[i]-ret)/d*x%(m[i]/d)*M;\r\
    \n        M*=m[i]/d;\r\n    }\r\n    return mod(ret,M);\r\n}\r\nint main(){\r\n\
    \    int x,y; cin>>x>>y;\r\n    cout<<gcd(x,y)<<endl;\r\n    return 0;\r\n}\r\n"
  code: "// \u6700\u5927\u516C\u7D04\u6570\r\n\r\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\ninline long long mod(long long n,long long m){return(n%m+m)%m;}\r\
    \n\r\nlong long gcd(long long x,long long y){\r\n    return y>0?gcd(y,x%y):x;\r\
    \n}\r\nlong long lcm(long long x,long long y){\r\n    return x/gcd(x,y)*y;\r\n\
    }\r\n// gcd(a,b)\u3068ax+by=gcd(a,b)\u3092\u6E80\u305F\u3059(x,y)\r\nlong long\
    \ ex_gcd(long long a,long long b,long long &x,long long &y){\r\n    if(b==0){\r\
    \n        // gcd(a,b)x+0y=gcd(a,b)\r\n        x=1,y=0;\r\n        return a;\r\n\
    \    }\r\n    long long d=ex_gcd(b,a%b,y,x);\r\n    y-=a/b*x;\r\n    return d;\r\
    \n}\r\n// x\u2261{b}(mod{m})\u3092\u6E80\u305F\u3059x(mod(lcm{m}))\r\nlong long\
    \ CRT(vector<long long> b,vector<long long> m){\r\n    // x\u22610(mod1)\u306F\
    \u5168\u3066\u306E\u6574\u6570\r\n    long long ret=0,M=1;\r\n    for(int i=0;i<(int)b.size();i++){\r\
    \n        long long x,y;\r\n        long long d=ex_gcd(M,m[i],x,y);\r\n      \
    \  if((b[i]-ret)%d) return -1;\r\n        // \u6700\u5F8C\u306BM\u3067\u5272\u308B\
    \u306E\u3067\u5171\u901A\u3057\u306A\u3044\u3082\u306E\u3067\u5270\u4F59\r\n \
    \       ret+=(b[i]-ret)/d*x%(m[i]/d)*M;\r\n        M*=m[i]/d;\r\n    }\r\n   \
    \ return mod(ret,M);\r\n}\r\nint main(){\r\n    int x,y; cin>>x>>y;\r\n    cout<<gcd(x,y)<<endl;\r\
    \n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/gcd_lcm.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/gcd_lcm.cpp
layout: document
redirect_from:
- /library/tmp/gcd_lcm.cpp
- /library/tmp/gcd_lcm.cpp.html
title: tmp/gcd_lcm.cpp
---
