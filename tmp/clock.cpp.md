---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/clock.cpp\"\n// \u3068\u3051\u3044\u3082\u3093\u3060\
    \u3044\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n// \u6574\u6570\
    \u79D2\u306B\u5BFE\u3059\u308B\u91DD\u306E\u89D2\u5EA6\u6BD4\u8F03\r\nint degH(int\
    \ h,int m,int s){\r\n    return 3600*h+60*m+s;\r\n}\r\nint degM(int h,int m,int\
    \ s){\r\n    return 720*m+12*s;\r\n}\r\nint degS(int h,int m,int s){\r\n    return\
    \ 720*s;\r\n}\r\n// \u8868\u793A\u3092\u5909\u66F4\u3057\u3066string\u3067\u8FD4\
    \u3059\r\nstring Uhr(int h,int m,int s){\r\n    char out[16];\r\n    sprintf(out,\"\
    %02d:%02d:%02d\",h,m,s);\r\n    return string(out);\r\n}\r\nint main(){\r\n  \
    \  int h=11,m=59,s=59;\r\n    // cin>>h>>m>>s;\r\n    // h%=12,m%=60,s%=60;\r\n\
    \    printf(\"%02d:%02d:%02d\\n\",h,m,s);\r\n    cout<<Uhr(h,m,s)<<endl;\r\n \
    \   return 0;\r\n}\r\n"
  code: "// \u3068\u3051\u3044\u3082\u3093\u3060\u3044\r\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n\r\n// \u6574\u6570\u79D2\u306B\u5BFE\u3059\u308B\u91DD\
    \u306E\u89D2\u5EA6\u6BD4\u8F03\r\nint degH(int h,int m,int s){\r\n    return 3600*h+60*m+s;\r\
    \n}\r\nint degM(int h,int m,int s){\r\n    return 720*m+12*s;\r\n}\r\nint degS(int\
    \ h,int m,int s){\r\n    return 720*s;\r\n}\r\n// \u8868\u793A\u3092\u5909\u66F4\
    \u3057\u3066string\u3067\u8FD4\u3059\r\nstring Uhr(int h,int m,int s){\r\n   \
    \ char out[16];\r\n    sprintf(out,\"%02d:%02d:%02d\",h,m,s);\r\n    return string(out);\r\
    \n}\r\nint main(){\r\n    int h=11,m=59,s=59;\r\n    // cin>>h>>m>>s;\r\n    //\
    \ h%=12,m%=60,s%=60;\r\n    printf(\"%02d:%02d:%02d\\n\",h,m,s);\r\n    cout<<Uhr(h,m,s)<<endl;\r\
    \n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/clock.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/clock.cpp
layout: document
redirect_from:
- /library/tmp/clock.cpp
- /library/tmp/clock.cpp.html
title: tmp/clock.cpp
---
