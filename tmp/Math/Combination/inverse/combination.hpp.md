---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/Math/Combination/inverse/combination.hpp\"\n#include\
    \ <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n// BEGIN CUT HERE\r\ntemplate<size_t\
    \ MAX>\r\nstruct Combination {\r\n\tconstexpr int MAX = 5000010;\r\n\tconst int\
    \ MOD;\r\n\tvector<long long> FAC;\r\n\tvector<long long> INV;\r\n\tvector<long\
    \ long> FAC_INV;\r\n\tCombination(const int MOD):\r\n\t\tMOD(MOD)\r\n\t\t{\r\n\
    \t\t\tFAC=vector<long long>(MAX);\r\n\t\t\tINV=vector<long long>(MAX);\r\n\t\t\
    \tFAC_INV=vector<long long>(MAX);\r\n\t\t\tFAC[0]=INV[1]=FAC_INV[0]=1;\r\n\t\t\
    \tfor(int i=1;i<MAX;i++){\r\n\t\t\t\tFAC[i]=FAC[i-1]*i%MOD;\r\n\t\t\t\tif(i>1)\
    \ INV[i]=MOD-INV[MOD%i]*(MOD/i)%MOD;\r\n\t\t\t\tFAC_INV[i]=FAC_INV[i-1]*INV[i]%MOD;\r\
    \n\t\t\t}\r\n\t\t}\r\n\tint C(int n,int r){\r\n\t\tif(n<0||r<0||n<r) return 0;\r\
    \n\t\treturn FAC[n]*FAC_INV[r]%MOD*FAC_INV[n-r]%MOD;\r\n\t}\r\n\tint P(int n,int\
    \ r){\r\n\t\tif(n<0||r<0||n<r) return 0;\r\n\t\treturn FAC[n]*FAC_INV[n-r]%MOD;\r\
    \n\t}\r\n\tint H(int n,int r){\r\n\t\tif(r==0) return 1;\r\n\t\treturn C(n+r-1,r);\r\
    \n\t}\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n// BEGIN CUT HERE\r\
    \ntemplate<size_t MAX>\r\nstruct Combination {\r\n\tconstexpr int MAX = 5000010;\r\
    \n\tconst int MOD;\r\n\tvector<long long> FAC;\r\n\tvector<long long> INV;\r\n\
    \tvector<long long> FAC_INV;\r\n\tCombination(const int MOD):\r\n\t\tMOD(MOD)\r\
    \n\t\t{\r\n\t\t\tFAC=vector<long long>(MAX);\r\n\t\t\tINV=vector<long long>(MAX);\r\
    \n\t\t\tFAC_INV=vector<long long>(MAX);\r\n\t\t\tFAC[0]=INV[1]=FAC_INV[0]=1;\r\
    \n\t\t\tfor(int i=1;i<MAX;i++){\r\n\t\t\t\tFAC[i]=FAC[i-1]*i%MOD;\r\n\t\t\t\t\
    if(i>1) INV[i]=MOD-INV[MOD%i]*(MOD/i)%MOD;\r\n\t\t\t\tFAC_INV[i]=FAC_INV[i-1]*INV[i]%MOD;\r\
    \n\t\t\t}\r\n\t\t}\r\n\tint C(int n,int r){\r\n\t\tif(n<0||r<0||n<r) return 0;\r\
    \n\t\treturn FAC[n]*FAC_INV[r]%MOD*FAC_INV[n-r]%MOD;\r\n\t}\r\n\tint P(int n,int\
    \ r){\r\n\t\tif(n<0||r<0||n<r) return 0;\r\n\t\treturn FAC[n]*FAC_INV[n-r]%MOD;\r\
    \n\t}\r\n\tint H(int n,int r){\r\n\t\tif(r==0) return 1;\r\n\t\treturn C(n+r-1,r);\r\
    \n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/Math/Combination/inverse/combination.hpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/Math/Combination/inverse/combination.hpp
layout: document
redirect_from:
- /library/tmp/Math/Combination/inverse/combination.hpp
- /library/tmp/Math/Combination/inverse/combination.hpp.html
title: tmp/Math/Combination/inverse/combination.hpp
---
