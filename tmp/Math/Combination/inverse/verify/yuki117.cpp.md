---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/Math/Combination/inverse/verify/yuki117.cpp\"\nint main(){\r\
    \n    const int MOD=1e9+7;\r\n    Combination com(MOD);\r\n    int t; cin>>t;\r\
    \n    while(t--){\r\n        string s; cin>>s;\r\n        int n,k,tmp=0;\r\n \
    \       for(int i=2;i<(int)s.size();i++){\r\n            if(s[i]==')'){\r\n  \
    \              k=tmp;\r\n            }else if(s[i]==','){\r\n                n=tmp;\r\
    \n                tmp=0;\r\n            }else{\r\n                tmp*=10;\r\n\
    \                tmp+=s[i]-'0';\r\n            }\r\n        }\r\n        if(s[0]=='C')\
    \ cout<<com.C(n,k)<<endl;\r\n        if(s[0]=='P') cout<<com.P(n,k)<<endl;\r\n\
    \        if(s[0]=='H') cout<<com.H(n,k)<<endl;\r\n    }\r\n    return 0;\r\n}\r\
    \n"
  code: "int main(){\r\n    const int MOD=1e9+7;\r\n    Combination com(MOD);\r\n\
    \    int t; cin>>t;\r\n    while(t--){\r\n        string s; cin>>s;\r\n      \
    \  int n,k,tmp=0;\r\n        for(int i=2;i<(int)s.size();i++){\r\n           \
    \ if(s[i]==')'){\r\n                k=tmp;\r\n            }else if(s[i]==','){\r\
    \n                n=tmp;\r\n                tmp=0;\r\n            }else{\r\n \
    \               tmp*=10;\r\n                tmp+=s[i]-'0';\r\n            }\r\n\
    \        }\r\n        if(s[0]=='C') cout<<com.C(n,k)<<endl;\r\n        if(s[0]=='P')\
    \ cout<<com.P(n,k)<<endl;\r\n        if(s[0]=='H') cout<<com.H(n,k)<<endl;\r\n\
    \    }\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/Math/Combination/inverse/verify/yuki117.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/Math/Combination/inverse/verify/yuki117.cpp
layout: document
redirect_from:
- /library/tmp/Math/Combination/inverse/verify/yuki117.cpp
- /library/tmp/Math/Combination/inverse/verify/yuki117.cpp.html
title: tmp/Math/Combination/inverse/verify/yuki117.cpp
---
