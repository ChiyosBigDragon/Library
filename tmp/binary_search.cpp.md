---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/binary_search.cpp\"\n// \u4E8C\u5206\u63A2\u7D22\r\n\
    // key\u4EE5\u4E0A\u3067\u300C\u6700\u5C0F\u300D\u3068\u306A\u308B\u8981\u7D20\
    \u306Eindex\u3092\u8FD4\u3059\r\n// \u307E\u305F\u3001key\u304C\u898B\u3064\u304B\
    \u3063\u305F\u5834\u5408\"find\"\u3092\u51FA\u529B\u3059\u308B\r\n// \u8A08\u7B97\
    \u91CFO(logN)\r\n\r\n#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\
    \nusing namespace std;\r\nconst int INF=INT_MAX,MOD=1e9+7;\r\n\r\n// \u5358\u8ABF\
    \u5897\u52A0\u5217a\r\nvector<int> a={1,14,32,51,51,51,243,419,750,910};\r\n\r\
    \n// index\u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B?\r\nbool isOK(int index,int\
    \ key){\r\n    if(a[index]>=key) return true;\r\n    else return false;\r\n}\r\
    \n\r\n// \u4E8C\u5206\u63A2\u7D22\r\nint binary_search(int key){\r\n\t// key\u4EE5\
    \u4E0A\u306E\u5024\u3092\u3068\u308Bindex\u306F\u5168\u3066ok\u3068\u3059\u308B\
    \r\n    int ng=-1; // a\u306E\u5DE6\u306E\u7BC4\u56F2\u5916\u306F\u5FC5\u305A\
    ng\r\n    int ok=(int)a.size(); // a\u306E\u53F3\u306E\u7BC4\u56F2\u5916\u306F\
    \u5FC5\u305Aok\r\n\r\n    while (abs(ok-ng)>1) {\r\n        int mid=(ok+ng)/2;\r\
    \n        if(isOK(mid,key)) ok=mid;\r\n        else ng=mid;\r\n    }\r\n    return\
    \ ok;\r\n}\r\n\r\nint main(){\r\n\tint key=51;\r\n\tint index=binary_search(key);\r\
    \n    cout<<index<<endl;\r\n\tif(a[index]==key) cout<<\"find\"<<endl;\r\n\treturn\
    \ 0;\r\n}\r\n"
  code: "// \u4E8C\u5206\u63A2\u7D22\r\n// key\u4EE5\u4E0A\u3067\u300C\u6700\u5C0F\
    \u300D\u3068\u306A\u308B\u8981\u7D20\u306Eindex\u3092\u8FD4\u3059\r\n// \u307E\
    \u305F\u3001key\u304C\u898B\u3064\u304B\u3063\u305F\u5834\u5408\"find\"\u3092\u51FA\
    \u529B\u3059\u308B\r\n// \u8A08\u7B97\u91CFO(logN)\r\n\r\n#include <bits/stdc++.h>\r\
    \n#define rep(i,n) for(int i=0;i<n;i++)\r\nusing namespace std;\r\nconst int INF=INT_MAX,MOD=1e9+7;\r\
    \n\r\n// \u5358\u8ABF\u5897\u52A0\u5217a\r\nvector<int> a={1,14,32,51,51,51,243,419,750,910};\r\
    \n\r\n// index\u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B?\r\nbool isOK(int\
    \ index,int key){\r\n    if(a[index]>=key) return true;\r\n    else return false;\r\
    \n}\r\n\r\n// \u4E8C\u5206\u63A2\u7D22\r\nint binary_search(int key){\r\n\t//\
    \ key\u4EE5\u4E0A\u306E\u5024\u3092\u3068\u308Bindex\u306F\u5168\u3066ok\u3068\
    \u3059\u308B\r\n    int ng=-1; // a\u306E\u5DE6\u306E\u7BC4\u56F2\u5916\u306F\u5FC5\
    \u305Ang\r\n    int ok=(int)a.size(); // a\u306E\u53F3\u306E\u7BC4\u56F2\u5916\
    \u306F\u5FC5\u305Aok\r\n\r\n    while (abs(ok-ng)>1) {\r\n        int mid=(ok+ng)/2;\r\
    \n        if(isOK(mid,key)) ok=mid;\r\n        else ng=mid;\r\n    }\r\n    return\
    \ ok;\r\n}\r\n\r\nint main(){\r\n\tint key=51;\r\n\tint index=binary_search(key);\r\
    \n    cout<<index<<endl;\r\n\tif(a[index]==key) cout<<\"find\"<<endl;\r\n\treturn\
    \ 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/binary_search.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/binary_search.cpp
layout: document
redirect_from:
- /library/tmp/binary_search.cpp
- /library/tmp/binary_search.cpp.html
title: tmp/binary_search.cpp
---
