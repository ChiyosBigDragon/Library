---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/Math/Combination/pascal/combination_pascal.cpp\"\n#include\
    \ <bits/stdc++.h>\r\nusing namespace std;\r\n\r\nstruct CombinationOnPascal{\r\
    \n    const int MAX=2010;\r\n    const int MOD;\r\n    vector<vector<int>> COM;\r\
    \n    vector<vector<int>> PER;\r\n    CombinationOnPascal(const int MOD):\r\n\
    \        MOD(MOD)\r\n        {\r\n            COM=vector<vector<int>>(MAX,vector<int>(MAX));\r\
    \n            PER=vector<vector<int>>(MAX,vector<int>(MAX));\r\n            COM[0][0]=PER[0][0]=1;\r\
    \n            for(int i=1;i<MAX;i++){\r\n                COM[i][0]=PER[i][0]=1;\r\
    \n                for(int j=1;j<MAX;j++){\r\n                    COM[i][j]=(COM[i-1][j-1]+COM[i-1][j])%MOD;\r\
    \n                    PER[i][j]=PER[i][j-1]*(i-j+1)%MOD;\r\n                }\r\
    \n            }\r\n        }\r\n    int C(int n,int r){\r\n        if(n<0||r<0||n<r)\
    \ return 0;\r\n        return COM[n][r];\r\n    }\r\n    int P(int n,int r){\r\
    \n        if(n<0||r<0||n<r) return 0;\r\n        return PER[n][r];\r\n    }\r\n\
    \    int H(int n,int r){\r\n        if(r==0) return 1;\r\n        return C(n+r-1,r);\r\
    \n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\nstruct CombinationOnPascal{\r\
    \n    const int MAX=2010;\r\n    const int MOD;\r\n    vector<vector<int>> COM;\r\
    \n    vector<vector<int>> PER;\r\n    CombinationOnPascal(const int MOD):\r\n\
    \        MOD(MOD)\r\n        {\r\n            COM=vector<vector<int>>(MAX,vector<int>(MAX));\r\
    \n            PER=vector<vector<int>>(MAX,vector<int>(MAX));\r\n            COM[0][0]=PER[0][0]=1;\r\
    \n            for(int i=1;i<MAX;i++){\r\n                COM[i][0]=PER[i][0]=1;\r\
    \n                for(int j=1;j<MAX;j++){\r\n                    COM[i][j]=(COM[i-1][j-1]+COM[i-1][j])%MOD;\r\
    \n                    PER[i][j]=PER[i][j-1]*(i-j+1)%MOD;\r\n                }\r\
    \n            }\r\n        }\r\n    int C(int n,int r){\r\n        if(n<0||r<0||n<r)\
    \ return 0;\r\n        return COM[n][r];\r\n    }\r\n    int P(int n,int r){\r\
    \n        if(n<0||r<0||n<r) return 0;\r\n        return PER[n][r];\r\n    }\r\n\
    \    int H(int n,int r){\r\n        if(r==0) return 1;\r\n        return C(n+r-1,r);\r\
    \n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/Math/Combination/pascal/combination_pascal.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/Math/Combination/pascal/combination_pascal.cpp
layout: document
redirect_from:
- /library/tmp/Math/Combination/pascal/combination_pascal.cpp
- /library/tmp/Math/Combination/pascal/combination_pascal.cpp.html
title: tmp/Math/Combination/pascal/combination_pascal.cpp
---
