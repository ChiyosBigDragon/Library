---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/DP.cpp\"\n#include <bits/stdc++.h>\r\n#define rep(i,n)\
    \ for(int i=0;i<n;i++)\r\nusing namespace std;\r\nconst int INF=INT_MAX;\r\n\r\
    \nint main(){\r\n    //dp\u30C6\u30FC\u30D6\u30EB\r\n    int dp[110][10010];\r\
    \n\r\n    //\u521D\u671F\u5316\r\n    int n,A; cin>>n>>A;\r\n    int a[n]; rep(i,n)\
    \ cin>>a[i];\r\n    //dp\u521D\u671F\u5316(\u5341\u5206\u5927\u304D\u3044\u5024\
    \u306B)\r\n    rep(i,110) rep(j,10010) dp[i][j]=INF;\r\n    dp[0][0]=0; //\u9078\
    \u3070\u306A\u3044\u3067\u6210\u308A\u7ACB\u3064\u306E\u306F\u548C0\u306E\u307F\
    \r\n\r\n    rep(i,n){\r\n        rep(sum,A+1){\r\n            dp[i+1][sum]=min(dp[i+1][sum],dp[i][sum]);\r\
    \n            if(sum-a[i]>=0) dp[i+1][sum]=min(dp[i][sum-a[i]]+1,dp[i+1][sum]);\r\
    \n        }\r\n    }\r\n    if(dp[n][A]==INF) cout<<-1<<endl;\r\n    else cout<<dp[n][A]<<endl;\r\
    \n\r\n    return 0;\r\n}\r\n"
  code: "#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\nusing\
    \ namespace std;\r\nconst int INF=INT_MAX;\r\n\r\nint main(){\r\n    //dp\u30C6\
    \u30FC\u30D6\u30EB\r\n    int dp[110][10010];\r\n\r\n    //\u521D\u671F\u5316\r\
    \n    int n,A; cin>>n>>A;\r\n    int a[n]; rep(i,n) cin>>a[i];\r\n    //dp\u521D\
    \u671F\u5316(\u5341\u5206\u5927\u304D\u3044\u5024\u306B)\r\n    rep(i,110) rep(j,10010)\
    \ dp[i][j]=INF;\r\n    dp[0][0]=0; //\u9078\u3070\u306A\u3044\u3067\u6210\u308A\
    \u7ACB\u3064\u306E\u306F\u548C0\u306E\u307F\r\n\r\n    rep(i,n){\r\n        rep(sum,A+1){\r\
    \n            dp[i+1][sum]=min(dp[i+1][sum],dp[i][sum]);\r\n            if(sum-a[i]>=0)\
    \ dp[i+1][sum]=min(dp[i][sum-a[i]]+1,dp[i+1][sum]);\r\n        }\r\n    }\r\n\
    \    if(dp[n][A]==INF) cout<<-1<<endl;\r\n    else cout<<dp[n][A]<<endl;\r\n\r\
    \n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/DP.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/DP.cpp
layout: document
redirect_from:
- /library/tmp/DP.cpp
- /library/tmp/DP.cpp.html
title: tmp/DP.cpp
---
