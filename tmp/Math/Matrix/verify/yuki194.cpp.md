---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/Math/Matrix/verify/yuki194.cpp\"\nint main(){\r\n  \
    \  const int MOD=1e9+7;\r\n    using mint=ModInt<MOD>;\r\n    long long n,k; cin>>n>>k;\r\
    \n    // \u306F\u305A\u308C\r\n    if(k<=n){\r\n        mint f,sum=0;\r\n    \
    \    for(int i=1;i<=k;i++){\r\n            cin>>f;\r\n            sum+=f;\r\n\
    \        }\r\n        cout<<f<<\" \"<<sum<<endl;\r\n        return 0;\r\n    }\r\
    \n    // \u30C6\u30B9\u30C81\r\n    if(n>30){\r\n        mint f[k+1],s[k+1];\r\
    \n        for(int i=1;i<=n;i++){\r\n            cin>>f[i];\r\n            s[i]=f[i]+s[i-1];\r\
    \n        }\r\n        for(int i=n+1;i<=k;i++){\r\n            f[i]=s[i-1]-s[i-n-1];\r\
    \n            s[i]=f[i]+s[i-1];\r\n        }\r\n        cout<<f[k]<<\" \"<<s[k]<<endl;\r\
    \n        return 0;\r\n    }\r\n    // \u30C6\u30B9\u30C82\r\n    mint f[n+1],s[n+1];\r\
    \n    for(int i=1;i<=n;i++){\r\n        cin>>f[i];\r\n        s[i]=f[i]+s[i-1];\r\
    \n    }\r\n    Matrix<mint> mat(n+1,n+1);\r\n    mat[0][0]=2;\r\n    mat[0][n]=-1;\r\
    \n    for(int y=1;y<n+1;y++){\r\n        mat[y][y-1]=1;\r\n    }\r\n    mat.pow(k-n);\r\
    \n    mint sk,sk1;\r\n    for(int x=0;x<n+1;x++){\r\n        sk+=mat[0][x]*s[n-x];\r\
    \n        sk1+=mat[1][x]*s[n-x];\r\n    }\r\n    cout<<sk-sk1<<\" \"<<sk<<endl;\r\
    \n    return 0;\r\n}\r\n"
  code: "int main(){\r\n    const int MOD=1e9+7;\r\n    using mint=ModInt<MOD>;\r\n\
    \    long long n,k; cin>>n>>k;\r\n    // \u306F\u305A\u308C\r\n    if(k<=n){\r\
    \n        mint f,sum=0;\r\n        for(int i=1;i<=k;i++){\r\n            cin>>f;\r\
    \n            sum+=f;\r\n        }\r\n        cout<<f<<\" \"<<sum<<endl;\r\n \
    \       return 0;\r\n    }\r\n    // \u30C6\u30B9\u30C81\r\n    if(n>30){\r\n\
    \        mint f[k+1],s[k+1];\r\n        for(int i=1;i<=n;i++){\r\n           \
    \ cin>>f[i];\r\n            s[i]=f[i]+s[i-1];\r\n        }\r\n        for(int\
    \ i=n+1;i<=k;i++){\r\n            f[i]=s[i-1]-s[i-n-1];\r\n            s[i]=f[i]+s[i-1];\r\
    \n        }\r\n        cout<<f[k]<<\" \"<<s[k]<<endl;\r\n        return 0;\r\n\
    \    }\r\n    // \u30C6\u30B9\u30C82\r\n    mint f[n+1],s[n+1];\r\n    for(int\
    \ i=1;i<=n;i++){\r\n        cin>>f[i];\r\n        s[i]=f[i]+s[i-1];\r\n    }\r\
    \n    Matrix<mint> mat(n+1,n+1);\r\n    mat[0][0]=2;\r\n    mat[0][n]=-1;\r\n\
    \    for(int y=1;y<n+1;y++){\r\n        mat[y][y-1]=1;\r\n    }\r\n    mat.pow(k-n);\r\
    \n    mint sk,sk1;\r\n    for(int x=0;x<n+1;x++){\r\n        sk+=mat[0][x]*s[n-x];\r\
    \n        sk1+=mat[1][x]*s[n-x];\r\n    }\r\n    cout<<sk-sk1<<\" \"<<sk<<endl;\r\
    \n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/Math/Matrix/verify/yuki194.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/Math/Matrix/verify/yuki194.cpp
layout: document
redirect_from:
- /library/tmp/Math/Matrix/verify/yuki194.cpp
- /library/tmp/Math/Matrix/verify/yuki194.cpp.html
title: tmp/Math/Matrix/verify/yuki194.cpp
---
