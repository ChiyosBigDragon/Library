---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/divisor.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nvector<int64_t> divisor(int64_t n) {\n    vector<int64_t> ret;\n   \
    \ for(int64_t i = 1; i * i <= n; ++i) {\n        if(n % i == 0) {\n          \
    \  ret.emplace_back(i);\n            if(i * i != n) ret.emplace_back(n / i);\n\
    \        }\n    }\n    sort(ret.begin(), ret.end());\n    return ret;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nvector<int64_t> divisor(int64_t\
    \ n) {\n    vector<int64_t> ret;\n    for(int64_t i = 1; i * i <= n; ++i) {\n\
    \        if(n % i == 0) {\n            ret.emplace_back(i);\n            if(i\
    \ * i != n) ret.emplace_back(n / i);\n        }\n    }\n    sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/divisor.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/divisor.cpp
layout: document
redirect_from:
- /library/tmp/divisor.cpp
- /library/tmp/divisor.cpp.html
title: tmp/divisor.cpp
---
