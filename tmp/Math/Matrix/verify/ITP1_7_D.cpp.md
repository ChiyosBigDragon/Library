---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/Math/Matrix/verify/ITP1_7_D.cpp\"\nint main(){\r\n \
    \   int n,m,l; cin>>n>>m>>l;\r\n    Matrix<long long> a(n,m);\r\n    for(int i=0;i<n;i++){\r\
    \n        for(int j=0;j<m;j++){\r\n            cin>>a[i][j];\r\n        }\r\n\
    \    }\r\n    Matrix<long long> b(m,l);\r\n    for(int i=0;i<m;i++){\r\n     \
    \   for(int j=0;j<l;j++){\r\n            cin>>b[i][j];\r\n        }\r\n    }\r\
    \n    (a*b).debug();\r\n    return 0;\r\n}\r\n"
  code: "int main(){\r\n    int n,m,l; cin>>n>>m>>l;\r\n    Matrix<long long> a(n,m);\r\
    \n    for(int i=0;i<n;i++){\r\n        for(int j=0;j<m;j++){\r\n            cin>>a[i][j];\r\
    \n        }\r\n    }\r\n    Matrix<long long> b(m,l);\r\n    for(int i=0;i<m;i++){\r\
    \n        for(int j=0;j<l;j++){\r\n            cin>>b[i][j];\r\n        }\r\n\
    \    }\r\n    (a*b).debug();\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/Math/Matrix/verify/ITP1_7_D.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/Math/Matrix/verify/ITP1_7_D.cpp
layout: document
redirect_from:
- /library/tmp/Math/Matrix/verify/ITP1_7_D.cpp
- /library/tmp/Math/Matrix/verify/ITP1_7_D.cpp.html
title: tmp/Math/Matrix/verify/ITP1_7_D.cpp
---
