---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/bit.cpp\"\n// bit\u6F14\u7B97\u3082\u308D\u3082\u308D\
    \r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n// \u6700\u4E0A\u4F4D\
    bit\r\nunsigned long long MSB(unsigned long long n){\r\n    n=n&0xFFFFFFFF00000000?n&0xFFFFFFFF00000000:n;\r\
    \n    n=n&0xFFFF0000FFFF0000?n&0xFFFF0000FFFF0000:n;\r\n    n=n&0xFF00FF00FF00FF00?n&0xFF00FF00FF00FF00:n;\r\
    \n    n=n&0xF0F0F0F0F0F0F0F0?n&0xF0F0F0F0F0F0F0F0:n;\r\n    n=n&0xCCCCCCCCCCCCCCCC?n&0xCCCCCCCCCCCCCCCC:n;\r\
    \n    n=n&0xAAAAAAAAAAAAAAAA?n&0xAAAAAAAAAAAAAAAA:n;\r\n    return n;\r\n}\r\n\
    // bit\u304C\u4F55\u672C\u7ACB\u3063\u3066\u3044\u308B\u304B\r\nlong long cntbit(long\
    \ long n){\r\n    n=(n&0x5555555555555555)+((n&0xAAAAAAAAAAAAAAAA)>>1);\r\n  \
    \  n=(n&0x3333333333333333)+((n&0xCCCCCCCCCCCCCCCC)>>2);\r\n    n=(n&0x0F0F0F0F0F0F0F0F)+((n&0xF0F0F0F0F0F0F0F0)>>4);\r\
    \n    n=(n&0x00FF00FF00FF00FF)+((n&0xFF00FF00FF00FF00)>>8);\r\n    n=(n&0x0000FFFF0000FFFF)+((n&0xFFFF0000FFFF0000)>>16);\r\
    \n    n=(n&0x00000000FFFFFFFF)+((n&0xFFFFFFFF00000000)>>32);\r\n    return n;\r\
    \n}\r\n"
  code: "// bit\u6F14\u7B97\u3082\u308D\u3082\u308D\r\n#include <bits/stdc++.h>\r\n\
    using namespace std;\r\n\r\n// \u6700\u4E0A\u4F4Dbit\r\nunsigned long long MSB(unsigned\
    \ long long n){\r\n    n=n&0xFFFFFFFF00000000?n&0xFFFFFFFF00000000:n;\r\n    n=n&0xFFFF0000FFFF0000?n&0xFFFF0000FFFF0000:n;\r\
    \n    n=n&0xFF00FF00FF00FF00?n&0xFF00FF00FF00FF00:n;\r\n    n=n&0xF0F0F0F0F0F0F0F0?n&0xF0F0F0F0F0F0F0F0:n;\r\
    \n    n=n&0xCCCCCCCCCCCCCCCC?n&0xCCCCCCCCCCCCCCCC:n;\r\n    n=n&0xAAAAAAAAAAAAAAAA?n&0xAAAAAAAAAAAAAAAA:n;\r\
    \n    return n;\r\n}\r\n// bit\u304C\u4F55\u672C\u7ACB\u3063\u3066\u3044\u308B\
    \u304B\r\nlong long cntbit(long long n){\r\n    n=(n&0x5555555555555555)+((n&0xAAAAAAAAAAAAAAAA)>>1);\r\
    \n    n=(n&0x3333333333333333)+((n&0xCCCCCCCCCCCCCCCC)>>2);\r\n    n=(n&0x0F0F0F0F0F0F0F0F)+((n&0xF0F0F0F0F0F0F0F0)>>4);\r\
    \n    n=(n&0x00FF00FF00FF00FF)+((n&0xFF00FF00FF00FF00)>>8);\r\n    n=(n&0x0000FFFF0000FFFF)+((n&0xFFFF0000FFFF0000)>>16);\r\
    \n    n=(n&0x00000000FFFFFFFF)+((n&0xFFFFFFFF00000000)>>32);\r\n    return n;\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/bit.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/bit.cpp
layout: document
redirect_from:
- /library/tmp/bit.cpp
- /library/tmp/bit.cpp.html
title: tmp/bit.cpp
---
