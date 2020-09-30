---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/Math/Combination/inverse/combination copy.cpp\"\n#include\
    \ <bits/stdc++.h>\r\nusing namespace std;\r\n\r\nstruct Combination{\r\n    const\
    \ int MAX=5000010;\r\n    const int MOD;\r\n    vector<long long> FAC;\r\n   \
    \ vector<long long> INV;\r\n    vector<long long> FAC_INV;\r\n    Combination(const\
    \ int MOD):\r\n        MOD(MOD)\r\n        {\r\n            FAC=vector<long long>(MAX);\r\
    \n            INV=vector<long long>(MAX);\r\n            FAC_INV=vector<long long>(MAX);\r\
    \n            FAC[0]=INV[1]=FAC_INV[0]=1;\r\n            for(int i=1;i<MAX;i++){\r\
    \n                FAC[i]=FAC[i-1]*i%MOD;\r\n                if(i>1) INV[i]=MOD-INV[MOD%i]*(MOD/i)%MOD;\r\
    \n                FAC_INV[i]=FAC_INV[i-1]*INV[i]%MOD;\r\n            }\r\n   \
    \     }\r\n    int C(int n,int r){\r\n        if(n<0||r<0||n<r) return 0;\r\n\
    \        return FAC[n]*FAC_INV[r]%MOD*FAC_INV[n-r]%MOD;\r\n    }\r\n    int P(int\
    \ n,int r){\r\n        if(n<0||r<0||n<r) return 0;\r\n        return FAC[n]*FAC_INV[n-r]%MOD;\r\
    \n    }\r\n    int H(int n,int r){\r\n        if(r==0) return 1;\r\n        return\
    \ C(n+r-1,r);\r\n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\nstruct Combination{\r\
    \n    const int MAX=5000010;\r\n    const int MOD;\r\n    vector<long long> FAC;\r\
    \n    vector<long long> INV;\r\n    vector<long long> FAC_INV;\r\n    Combination(const\
    \ int MOD):\r\n        MOD(MOD)\r\n        {\r\n            FAC=vector<long long>(MAX);\r\
    \n            INV=vector<long long>(MAX);\r\n            FAC_INV=vector<long long>(MAX);\r\
    \n            FAC[0]=INV[1]=FAC_INV[0]=1;\r\n            for(int i=1;i<MAX;i++){\r\
    \n                FAC[i]=FAC[i-1]*i%MOD;\r\n                if(i>1) INV[i]=MOD-INV[MOD%i]*(MOD/i)%MOD;\r\
    \n                FAC_INV[i]=FAC_INV[i-1]*INV[i]%MOD;\r\n            }\r\n   \
    \     }\r\n    int C(int n,int r){\r\n        if(n<0||r<0||n<r) return 0;\r\n\
    \        return FAC[n]*FAC_INV[r]%MOD*FAC_INV[n-r]%MOD;\r\n    }\r\n    int P(int\
    \ n,int r){\r\n        if(n<0||r<0||n<r) return 0;\r\n        return FAC[n]*FAC_INV[n-r]%MOD;\r\
    \n    }\r\n    int H(int n,int r){\r\n        if(r==0) return 1;\r\n        return\
    \ C(n+r-1,r);\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/Math/Combination/inverse/combination copy.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/Math/Combination/inverse/combination copy.cpp
layout: document
redirect_from:
- /library/tmp/Math/Combination/inverse/combination copy.cpp
- /library/tmp/Math/Combination/inverse/combination copy.cpp.html
title: tmp/Math/Combination/inverse/combination copy.cpp
---
