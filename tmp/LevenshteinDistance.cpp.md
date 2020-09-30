---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_E
    - https://yukicoder.me/problems/no/225
  bundledCode: "#line 1 \"tmp/LevenshteinDistance.cpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n\r\nstruct LevenshteinDistance{\r\n    const int INF=1145141919;\r\
    \n    const int costInsert,costErase,costReplace;\r\n    LevenshteinDistance(int\
    \ i,int e,int r):\r\n        costInsert(i),costErase(e),costReplace(r)\r\n   \
    \     {}\r\n    int distance(string& s1,string& s2){\r\n        int n1=s1.size(),n2=s2.size();\r\
    \n        // dp[i][j]:=s1\u306Ei\u6587\u5B57\u76EE\u307E\u3067\u3068s2\u306Ej\u6587\
    \u5B57\u76EE\u307E\u3067\u306E\u8DDD\u96E2\r\n        vector<vector<int>> dp(n1+1,vector<int>(n2+1,INF));\r\
    \n        for(int i=0;i<=max(n1,n2);i++){\r\n            if(i<=n1) dp[i][0]=i;\r\
    \n            if(i<=n2) dp[0][i]=i;\r\n        }\r\n        for(int i=1;i<=n1;i++){\r\
    \n            for(int j=1;j<=n2;j++){\r\n                dp[i][j]=min(dp[i][j],dp[i-1][j]+costInsert);\r\
    \n                dp[i][j]=min(dp[i][j],dp[i][j-1]+costErase);\r\n           \
    \     dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s1[i-1]==s2[j-1]?0:costReplace));\r\n\
    \            }\r\n        }\r\n        return dp[n1][n2];\r\n    }\r\n};\r\n//\
    \ verify\r\n// https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_E\r\nint main(){\r\
    \n    LevenshteinDistance ld(1,1,1);\r\n    string s1,s2; cin>>s1>>s2;\r\n   \
    \ cout<<ld.distance(s1,s2)<<endl;\r\n    return 0;\r\n}\r\n// https://yukicoder.me/problems/no/225\r\
    \n// int main(){\r\n//     LevenshteinDistance ld(1,1,1);\r\n//     int n,m; cin>>n>>m;\r\
    \n//     string s1,s2; cin>>s1>>s2;\r\n//     cout<<ld.distance(s1,s2)<<endl;\r\
    \n//     return 0;\r\n// }\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\nstruct LevenshteinDistance{\r\
    \n    const int INF=1145141919;\r\n    const int costInsert,costErase,costReplace;\r\
    \n    LevenshteinDistance(int i,int e,int r):\r\n        costInsert(i),costErase(e),costReplace(r)\r\
    \n        {}\r\n    int distance(string& s1,string& s2){\r\n        int n1=s1.size(),n2=s2.size();\r\
    \n        // dp[i][j]:=s1\u306Ei\u6587\u5B57\u76EE\u307E\u3067\u3068s2\u306Ej\u6587\
    \u5B57\u76EE\u307E\u3067\u306E\u8DDD\u96E2\r\n        vector<vector<int>> dp(n1+1,vector<int>(n2+1,INF));\r\
    \n        for(int i=0;i<=max(n1,n2);i++){\r\n            if(i<=n1) dp[i][0]=i;\r\
    \n            if(i<=n2) dp[0][i]=i;\r\n        }\r\n        for(int i=1;i<=n1;i++){\r\
    \n            for(int j=1;j<=n2;j++){\r\n                dp[i][j]=min(dp[i][j],dp[i-1][j]+costInsert);\r\
    \n                dp[i][j]=min(dp[i][j],dp[i][j-1]+costErase);\r\n           \
    \     dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s1[i-1]==s2[j-1]?0:costReplace));\r\n\
    \            }\r\n        }\r\n        return dp[n1][n2];\r\n    }\r\n};\r\n//\
    \ verify\r\n// https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_E\r\nint main(){\r\
    \n    LevenshteinDistance ld(1,1,1);\r\n    string s1,s2; cin>>s1>>s2;\r\n   \
    \ cout<<ld.distance(s1,s2)<<endl;\r\n    return 0;\r\n}\r\n// https://yukicoder.me/problems/no/225\r\
    \n// int main(){\r\n//     LevenshteinDistance ld(1,1,1);\r\n//     int n,m; cin>>n>>m;\r\
    \n//     string s1,s2; cin>>s1>>s2;\r\n//     cout<<ld.distance(s1,s2)<<endl;\r\
    \n//     return 0;\r\n// }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/LevenshteinDistance.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/LevenshteinDistance.cpp
layout: document
redirect_from:
- /library/tmp/LevenshteinDistance.cpp
- /library/tmp/LevenshteinDistance.cpp.html
title: tmp/LevenshteinDistance.cpp
---
