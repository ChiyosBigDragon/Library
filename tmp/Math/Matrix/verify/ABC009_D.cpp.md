---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/Math/Matrix/verify/ABC009_D.cpp\"\n// Matrix\u30AF\u30E9\
    \u30B9\u306B\u4EE5\u4E0B\u3092\u8FFD\u52A0-------------------------------\r\n\
    // XOR\r\nMatrix &operator ^=(const Matrix &_mat){\r\n    int h=(*this).height(),w=(*this).width();\r\
    \n    assert(h==_mat.height()&&w==_mat.width());\r\n    for(int y=0;y<h;y++){\r\
    \n        for(int x=0;x<w;x++){\r\n            (*this)[y][x]^=_mat[y][x];\r\n\
    \        }\r\n    }\r\n    return (*this);\r\n}\r\nMatrix operator ^(const Matrix\
    \ &_mat){\r\n    return (*this)^=_mat;\r\n}\r\n// AND\r\nMatrix &operator &=(const\
    \ Matrix &_mat){\r\n    int h=(*this).height(),w=(*this).width();\r\n    int _h=_mat.height(),_w=_mat.width();\r\
    \n    assert(w==_h);\r\n    vector<vector<T>> ret(h,vector<T>(_w,0));\r\n    for(int\
    \ y=0;y<h;y++){\r\n        for(int x=0;x<_w;x++){\r\n            for(int k=0;k<w;k++){\r\
    \n                ret[y][x]^=mat[y][k]&_mat[k][x];\r\n            }\r\n      \
    \  }\r\n    }\r\n    mat=ret;\r\n    return (*this);\r\n}\r\nMatrix operator &(const\
    \ Matrix &_mat){\r\n    return (*this)&=_mat;\r\n}\r\n// AND\u7D2F\u4E57\r\nMatrix\
    \ powand(long long n){\r\n    Matrix ret=I((*this).height(),UINT_MAX);\r\n   \
    \ while(n>0){\r\n        if(n&1) ret&=(*this);\r\n        (*this)&=(*this);\r\n\
    \        n>>=1ll;\r\n    }\r\n    (*this)=ret;\r\n    return (*this);\r\n}\r\n\
    // \u3053\u3053\u307E\u3067------------------------------------------------\r\n\
    \r\nint main(){\r\n    int k,m; cin>>k>>m;\r\n    unsigned int a[k];\r\n    for(int\
    \ i=0;i<k;i++) cin>>a[i];\r\n    Matrix<unsigned int> mat(k,k);\r\n    for(int\
    \ i=0;i<k;i++) cin>>mat[0][i];\r\n    for(int i=1;i<k;i++) mat[i][i-1]=UINT_MAX;\r\
    \n    if(m<k){\r\n        cout<<a[m-1]<<endl;\r\n        return 0;\r\n    }\r\n\
    \    mat.powand(m-k);\r\n    long long ans=0;\r\n    for(int i=0;i<k;i++){\r\n\
    \        ans^=(mat[0][i]&a[k-1-i]);\r\n    }\r\n    cout<<ans<<endl;\r\n    return\
    \ 0;\r\n}\r\n"
  code: "// Matrix\u30AF\u30E9\u30B9\u306B\u4EE5\u4E0B\u3092\u8FFD\u52A0-------------------------------\r\
    \n// XOR\r\nMatrix &operator ^=(const Matrix &_mat){\r\n    int h=(*this).height(),w=(*this).width();\r\
    \n    assert(h==_mat.height()&&w==_mat.width());\r\n    for(int y=0;y<h;y++){\r\
    \n        for(int x=0;x<w;x++){\r\n            (*this)[y][x]^=_mat[y][x];\r\n\
    \        }\r\n    }\r\n    return (*this);\r\n}\r\nMatrix operator ^(const Matrix\
    \ &_mat){\r\n    return (*this)^=_mat;\r\n}\r\n// AND\r\nMatrix &operator &=(const\
    \ Matrix &_mat){\r\n    int h=(*this).height(),w=(*this).width();\r\n    int _h=_mat.height(),_w=_mat.width();\r\
    \n    assert(w==_h);\r\n    vector<vector<T>> ret(h,vector<T>(_w,0));\r\n    for(int\
    \ y=0;y<h;y++){\r\n        for(int x=0;x<_w;x++){\r\n            for(int k=0;k<w;k++){\r\
    \n                ret[y][x]^=mat[y][k]&_mat[k][x];\r\n            }\r\n      \
    \  }\r\n    }\r\n    mat=ret;\r\n    return (*this);\r\n}\r\nMatrix operator &(const\
    \ Matrix &_mat){\r\n    return (*this)&=_mat;\r\n}\r\n// AND\u7D2F\u4E57\r\nMatrix\
    \ powand(long long n){\r\n    Matrix ret=I((*this).height(),UINT_MAX);\r\n   \
    \ while(n>0){\r\n        if(n&1) ret&=(*this);\r\n        (*this)&=(*this);\r\n\
    \        n>>=1ll;\r\n    }\r\n    (*this)=ret;\r\n    return (*this);\r\n}\r\n\
    // \u3053\u3053\u307E\u3067------------------------------------------------\r\n\
    \r\nint main(){\r\n    int k,m; cin>>k>>m;\r\n    unsigned int a[k];\r\n    for(int\
    \ i=0;i<k;i++) cin>>a[i];\r\n    Matrix<unsigned int> mat(k,k);\r\n    for(int\
    \ i=0;i<k;i++) cin>>mat[0][i];\r\n    for(int i=1;i<k;i++) mat[i][i-1]=UINT_MAX;\r\
    \n    if(m<k){\r\n        cout<<a[m-1]<<endl;\r\n        return 0;\r\n    }\r\n\
    \    mat.powand(m-k);\r\n    long long ans=0;\r\n    for(int i=0;i<k;i++){\r\n\
    \        ans^=(mat[0][i]&a[k-1-i]);\r\n    }\r\n    cout<<ans<<endl;\r\n    return\
    \ 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/Math/Matrix/verify/ABC009_D.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/Math/Matrix/verify/ABC009_D.cpp
layout: document
redirect_from:
- /library/tmp/Math/Matrix/verify/ABC009_D.cpp
- /library/tmp/Math/Matrix/verify/ABC009_D.cpp.html
title: tmp/Math/Matrix/verify/ABC009_D.cpp
---
