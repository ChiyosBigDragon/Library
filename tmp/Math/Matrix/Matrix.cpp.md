---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/Math/Matrix/Matrix.cpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n\r\ntemplate<class T>\r\nstruct Matrix{\r\n    vector<vector<T>>\
    \ mat;\r\n    Matrix(const int h,const int w):\r\n        mat(h,vector<T>(w,0))\r\
    \n        {}\r\n    Matrix(const vector<vector<T>> &G):\r\n        mat(G)\r\n\
    \        {}\r\n    int height() const{\r\n        return mat.size();\r\n    }\r\
    \n    int width() const{\r\n        return mat[0].size();\r\n    }\r\n    // \u6DFB\
    \u5B57\r\n    const vector<T> &operator[](int i) const{\r\n        assert(0<=i&&i<(int)mat.size());\r\
    \n        return mat[i];\r\n    }\r\n    vector<T> &operator[](int i){\r\n   \
    \     assert(0<=i&&i<(int)mat.size());\r\n        return mat[i];\r\n    }\r\n\
    \    // \u5358\u4F4D\u5143\r\n    Matrix I(int n,T x){\r\n        Matrix ret(n,n);\r\
    \n        for(int i=0;i<n;i++){\r\n            ret[i][i]=x;\r\n        }\r\n \
    \       return ret;\r\n    }\r\n    // \u52A0\u6CD5\r\n    Matrix &operator +=(const\
    \ Matrix &_mat){\r\n        int h=(*this).height(),w=(*this).width();\r\n    \
    \    assert(h==_mat.height()&&w==_mat.width());\r\n        for(int y=0;y<h;y++){\r\
    \n            for(int x=0;x<w;x++){\r\n                (*this)[y][x]+=_mat[y][x];\r\
    \n            }\r\n        }\r\n        return (*this);\r\n    }\r\n    Matrix\
    \ operator +(const Matrix &_mat) const{\r\n        return Matrix(*this)+=_mat;\r\
    \n    }\r\n    // \u6E1B\u6CD5\r\n    Matrix &operator -=(const Matrix &_mat){\r\
    \n        int h=(*this).height(),w=(*this).width();\r\n        assert(h==_mat.height()&&w==_mat.width());\r\
    \n        for(int y=0;y<h;y++){\r\n            for(int x=0;x<w;x++){\r\n     \
    \           (*this)[y][x]-=_mat[y][x];\r\n            }\r\n        }\r\n     \
    \   return (*this);\r\n    }\r\n    Matrix operator -(const Matrix &_mat) const{\r\
    \n        return Matrix(*this)-=_mat;\r\n    }\r\n    // \u4E57\u6CD5\r\n    Matrix\
    \ &operator *=(const Matrix &_mat){\r\n        int h=(*this).height(),w=(*this).width();\r\
    \n        int _h=_mat.height(),_w=_mat.width();\r\n        assert(w==_h);\r\n\
    \        vector<vector<T>> ret(h,vector<T>(_w,0));\r\n        for(int y=0;y<h;y++){\r\
    \n            for(int x=0;x<_w;x++){\r\n                for(int k=0;k<w;k++){\r\
    \n                    ret[y][x]+=(*this)[y][k]*_mat[k][x];\r\n               \
    \ }\r\n            }\r\n        }\r\n        mat=ret;\r\n        return (*this);\r\
    \n    }\r\n    Matrix operator *(const Matrix &_mat) const{\r\n        return\
    \ Matrix(*this)*=_mat;\r\n    }\r\n    // \u51AA\u4E57\r\n    Matrix pow(long\
    \ long k){\r\n        Matrix ret=I((*this).height(),1);\r\n        while(k>0){\r\
    \n            if(k&1) ret*=(*this);\r\n            (*this)*=(*this);\r\n     \
    \       k>>=1ll;\r\n        }\r\n        (*this)=ret;\r\n        return (*this);\r\
    \n    }\r\n    void debug(){\r\n        int h=height(),w=width();\r\n        for(int\
    \ y=0;y<h;y++){\r\n            for(int x=0;x<w;x++){\r\n                cout<<mat[y][x]<<(x==w-1?\"\
    \\n\":\" \");\r\n            }\r\n        }\r\n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\ntemplate<class T>\r\
    \nstruct Matrix{\r\n    vector<vector<T>> mat;\r\n    Matrix(const int h,const\
    \ int w):\r\n        mat(h,vector<T>(w,0))\r\n        {}\r\n    Matrix(const vector<vector<T>>\
    \ &G):\r\n        mat(G)\r\n        {}\r\n    int height() const{\r\n        return\
    \ mat.size();\r\n    }\r\n    int width() const{\r\n        return mat[0].size();\r\
    \n    }\r\n    // \u6DFB\u5B57\r\n    const vector<T> &operator[](int i) const{\r\
    \n        assert(0<=i&&i<(int)mat.size());\r\n        return mat[i];\r\n    }\r\
    \n    vector<T> &operator[](int i){\r\n        assert(0<=i&&i<(int)mat.size());\r\
    \n        return mat[i];\r\n    }\r\n    // \u5358\u4F4D\u5143\r\n    Matrix I(int\
    \ n,T x){\r\n        Matrix ret(n,n);\r\n        for(int i=0;i<n;i++){\r\n   \
    \         ret[i][i]=x;\r\n        }\r\n        return ret;\r\n    }\r\n    //\
    \ \u52A0\u6CD5\r\n    Matrix &operator +=(const Matrix &_mat){\r\n        int\
    \ h=(*this).height(),w=(*this).width();\r\n        assert(h==_mat.height()&&w==_mat.width());\r\
    \n        for(int y=0;y<h;y++){\r\n            for(int x=0;x<w;x++){\r\n     \
    \           (*this)[y][x]+=_mat[y][x];\r\n            }\r\n        }\r\n     \
    \   return (*this);\r\n    }\r\n    Matrix operator +(const Matrix &_mat) const{\r\
    \n        return Matrix(*this)+=_mat;\r\n    }\r\n    // \u6E1B\u6CD5\r\n    Matrix\
    \ &operator -=(const Matrix &_mat){\r\n        int h=(*this).height(),w=(*this).width();\r\
    \n        assert(h==_mat.height()&&w==_mat.width());\r\n        for(int y=0;y<h;y++){\r\
    \n            for(int x=0;x<w;x++){\r\n                (*this)[y][x]-=_mat[y][x];\r\
    \n            }\r\n        }\r\n        return (*this);\r\n    }\r\n    Matrix\
    \ operator -(const Matrix &_mat) const{\r\n        return Matrix(*this)-=_mat;\r\
    \n    }\r\n    // \u4E57\u6CD5\r\n    Matrix &operator *=(const Matrix &_mat){\r\
    \n        int h=(*this).height(),w=(*this).width();\r\n        int _h=_mat.height(),_w=_mat.width();\r\
    \n        assert(w==_h);\r\n        vector<vector<T>> ret(h,vector<T>(_w,0));\r\
    \n        for(int y=0;y<h;y++){\r\n            for(int x=0;x<_w;x++){\r\n    \
    \            for(int k=0;k<w;k++){\r\n                    ret[y][x]+=(*this)[y][k]*_mat[k][x];\r\
    \n                }\r\n            }\r\n        }\r\n        mat=ret;\r\n    \
    \    return (*this);\r\n    }\r\n    Matrix operator *(const Matrix &_mat) const{\r\
    \n        return Matrix(*this)*=_mat;\r\n    }\r\n    // \u51AA\u4E57\r\n    Matrix\
    \ pow(long long k){\r\n        Matrix ret=I((*this).height(),1);\r\n        while(k>0){\r\
    \n            if(k&1) ret*=(*this);\r\n            (*this)*=(*this);\r\n     \
    \       k>>=1ll;\r\n        }\r\n        (*this)=ret;\r\n        return (*this);\r\
    \n    }\r\n    void debug(){\r\n        int h=height(),w=width();\r\n        for(int\
    \ y=0;y<h;y++){\r\n            for(int x=0;x<w;x++){\r\n                cout<<mat[y][x]<<(x==w-1?\"\
    \\n\":\" \");\r\n            }\r\n        }\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/Math/Matrix/Matrix.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/Math/Matrix/Matrix.cpp
layout: document
redirect_from:
- /library/tmp/Math/Matrix/Matrix.cpp
- /library/tmp/Math/Matrix/Matrix.cpp.html
title: tmp/Math/Matrix/Matrix.cpp
---
