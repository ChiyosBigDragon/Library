---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/output_option.cpp\"\n// \u7C21\u5358\u306B\u51FA\u529B\
    \u3067\u304D\u308B\r\n// \u5BFE\u5FDC:pair/vector/2\u6B21\u5143vector\r\n\r\n\
    #include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n// pair\r\ntemplate<typename\
    \ T1,typename T2> ostream&operator<<(ostream&s,const pair<T1,T2>&p){return s<<\"\
    (\"<<p.first<<\", \"<<p.second<<\")\";}\r\n// vector\r\ntemplate<typename T> ostream&operator<<(ostream&s,const\
    \ vector<T>&v){\r\n\tint len=v.size();\r\n\tfor(int i=0;i<len;++i){\r\n\t\ts<<v[i];\
    \ if(i<len-1) s<<\"\\t\";\r\n\t}\r\n\treturn s;\r\n}\r\n// 2 dimentional vector\r\
    \ntemplate<typename T> ostream&operator<<(ostream&s,const vector<vector<T>>&vv){\r\
    \n\tint len=vv.size();\r\n\tfor(int i=0;i<len;++i){\r\n\t\ts<<vv[i]<<endl;\r\n\
    \t}\r\n\treturn s;\r\n}\r\n\r\nint main(){\r\n\tpair<int,int> p=make_pair(1,2);\r\
    \n\tcout<<p<<endl;\r\n\tvector<int> x={1,2,4,5,6,12};\r\n\tvector<vector<int>>\
    \ y={{1,2,4,5,6,12},{2,4,6,8,10,12}};\r\n\tcout<<x<<endl;\r\n\tcout<<y<<endl;\r\
    \n    return 0;\r\n}\r\n"
  code: "// \u7C21\u5358\u306B\u51FA\u529B\u3067\u304D\u308B\r\n// \u5BFE\u5FDC:pair/vector/2\u6B21\
    \u5143vector\r\n\r\n#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n//\
    \ pair\r\ntemplate<typename T1,typename T2> ostream&operator<<(ostream&s,const\
    \ pair<T1,T2>&p){return s<<\"(\"<<p.first<<\", \"<<p.second<<\")\";}\r\n// vector\r\
    \ntemplate<typename T> ostream&operator<<(ostream&s,const vector<T>&v){\r\n\t\
    int len=v.size();\r\n\tfor(int i=0;i<len;++i){\r\n\t\ts<<v[i]; if(i<len-1) s<<\"\
    \\t\";\r\n\t}\r\n\treturn s;\r\n}\r\n// 2 dimentional vector\r\ntemplate<typename\
    \ T> ostream&operator<<(ostream&s,const vector<vector<T>>&vv){\r\n\tint len=vv.size();\r\
    \n\tfor(int i=0;i<len;++i){\r\n\t\ts<<vv[i]<<endl;\r\n\t}\r\n\treturn s;\r\n}\r\
    \n\r\nint main(){\r\n\tpair<int,int> p=make_pair(1,2);\r\n\tcout<<p<<endl;\r\n\
    \tvector<int> x={1,2,4,5,6,12};\r\n\tvector<vector<int>> y={{1,2,4,5,6,12},{2,4,6,8,10,12}};\r\
    \n\tcout<<x<<endl;\r\n\tcout<<y<<endl;\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/output_option.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/output_option.cpp
layout: document
redirect_from:
- /library/tmp/output_option.cpp
- /library/tmp/output_option.cpp.html
title: tmp/output_option.cpp
---
