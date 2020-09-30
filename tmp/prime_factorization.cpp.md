---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/prime_factorization.cpp\"\n#include <bits/stdc++.h>\r\
    \n#define rep(i,n) for(int i=0;i<n;i++)\r\nusing namespace std;\r\nconst int INF=INT_MAX,MOD=1e9+7;\r\
    \n\r\nmap<long long,int> mp;\r\nvector<long long> prime_factorization(long long\
    \ n){\r\n    vector<long long> v;\r\n    if(n==1) v.push_back(1);\r\n    long\
    \ long i=2;\r\n    while(n>1){\r\n        if(n<i*i){\r\n            v.push_back(n);\r\
    \n            mp[n]++;\r\n            return v;\r\n        }\r\n        if(n%i==0){\r\
    \n            n/=i;\r\n            v.push_back(i);\r\n            mp[i]++;\r\n\
    \        }else{\r\n            i++;\r\n        }\r\n    }\r\n    return v;\r\n\
    }\r\n\r\nint main(){\r\n    int n=1000000;\r\n    vector<long long> v=prime_factorization(n);\r\
    \n    for(auto i:v) cout<<i<<\" \";\r\n    return 0;\r\n}\r\n"
  code: "#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\nusing\
    \ namespace std;\r\nconst int INF=INT_MAX,MOD=1e9+7;\r\n\r\nmap<long long,int>\
    \ mp;\r\nvector<long long> prime_factorization(long long n){\r\n    vector<long\
    \ long> v;\r\n    if(n==1) v.push_back(1);\r\n    long long i=2;\r\n    while(n>1){\r\
    \n        if(n<i*i){\r\n            v.push_back(n);\r\n            mp[n]++;\r\n\
    \            return v;\r\n        }\r\n        if(n%i==0){\r\n            n/=i;\r\
    \n            v.push_back(i);\r\n            mp[i]++;\r\n        }else{\r\n  \
    \          i++;\r\n        }\r\n    }\r\n    return v;\r\n}\r\n\r\nint main(){\r\
    \n    int n=1000000;\r\n    vector<long long> v=prime_factorization(n);\r\n  \
    \  for(auto i:v) cout<<i<<\" \";\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/prime_factorization.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/prime_factorization.cpp
layout: document
redirect_from:
- /library/tmp/prime_factorization.cpp
- /library/tmp/prime_factorization.cpp.html
title: tmp/prime_factorization.cpp
---
