---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tmp/Math/ModInt/ModInt.cpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n\r\nusing fint64 = int_fast64_t;\r\ntemplate<fint64\
    \ MOD>\r\nstruct ModInt{\r\n    fint64 x;\r\n    ModInt():x(0){}\r\n    ModInt(fint64\
    \ x):\r\n        x(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD)\r\n        {}\r\n    // \u8CA0\
    \u53F7\r\n    ModInt operator -() const{\r\n        return ModInt(-x);\r\n   \
    \ }\r\n    // \u52A0\u7B97\r\n    ModInt &operator +=(const ModInt &rhs){\r\n\
    \        x+=rhs.x;\r\n        if(x>=MOD) x-=MOD;\r\n        return (*this);\r\n\
    \    }\r\n    ModInt operator +(const ModInt &rhs) const{\r\n        return ModInt(*this)+=rhs;\r\
    \n    }\r\n    // \u6E1B\u7B97\r\n    ModInt &operator -=(const ModInt &rhs){\r\
    \n        x+=MOD-rhs.x;\r\n        if(x>=MOD) x-=MOD;\r\n        return (*this);\r\
    \n    }\r\n    ModInt operator -(const ModInt &rhs) const{\r\n        return ModInt(*this)-=rhs;\r\
    \n    }\r\n    // \u4E57\u7B97\r\n    ModInt &operator *=(const ModInt &rhs){\r\
    \n        x*=rhs.x;\r\n        if(x>=MOD) x%=MOD;\r\n        return (*this);\r\
    \n    }\r\n    ModInt operator *(const ModInt &rhs) const{\r\n        return ModInt(*this)*=rhs;\r\
    \n    }\r\n    // \u9664\u7B97\r\n    ModInt &operator /=(const ModInt &rhs){\r\
    \n        (*this)*=rhs.inverse();\r\n        return (*this);\r\n    }\r\n    ModInt\
    \ operator /(const ModInt &rhs) const{\r\n        return ModInt(*this)/=rhs;\r\
    \n    }\r\n    // \u7B49\u53F7\r\n    bool operator ==(const ModInt &rhs){\r\n\
    \        return x==rhs.x;\r\n    }\r\n    bool operator !=(const ModInt &rhs){\r\
    \n        return x!=rhs.x;\r\n    }\r\n    // \u7D2F\u4E57\r\n    ModInt pow(fint64\
    \ n) const{\r\n        fint64 tmp=x;\r\n        fint64 ret=1;\r\n        while(n>0){\r\
    \n            if(n&1) ret=ret*tmp%MOD;\r\n            tmp=tmp*tmp%MOD;\r\n   \
    \         n>>=1ll;\r\n        }\r\n        return ModInt(ret);\r\n    }\r\n  \
    \  // \u9006\u5143\r\n    ModInt inverse() const{\r\n        fint64 a=x,b=MOD,s=1,t=0;\r\
    \n        while(b>0){\r\n            fint64 u=a/b;\r\n            a-=u*b;\r\n\
    \            s-=u*t;\r\n            swap(a,b);\r\n            swap(s,t);\r\n \
    \       }\r\n        return ModInt(s);\r\n    }\r\n    // \u5165\u51FA\u529B\r\
    \n    friend istream &operator >>(istream &lhs,ModInt<MOD> &rhs){\r\n        fint64\
    \ x; lhs>>x;\r\n        rhs=ModInt<MOD>(x);\r\n        return lhs;\r\n    }\r\n\
    \    friend ostream &operator <<(ostream &lhs,const ModInt<MOD> &rhs){\r\n   \
    \     return lhs<<rhs.x;\r\n    }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\nusing fint64 = int_fast64_t;\r\
    \ntemplate<fint64 MOD>\r\nstruct ModInt{\r\n    fint64 x;\r\n    ModInt():x(0){}\r\
    \n    ModInt(fint64 x):\r\n        x(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD)\r\n      \
    \  {}\r\n    // \u8CA0\u53F7\r\n    ModInt operator -() const{\r\n        return\
    \ ModInt(-x);\r\n    }\r\n    // \u52A0\u7B97\r\n    ModInt &operator +=(const\
    \ ModInt &rhs){\r\n        x+=rhs.x;\r\n        if(x>=MOD) x-=MOD;\r\n       \
    \ return (*this);\r\n    }\r\n    ModInt operator +(const ModInt &rhs) const{\r\
    \n        return ModInt(*this)+=rhs;\r\n    }\r\n    // \u6E1B\u7B97\r\n    ModInt\
    \ &operator -=(const ModInt &rhs){\r\n        x+=MOD-rhs.x;\r\n        if(x>=MOD)\
    \ x-=MOD;\r\n        return (*this);\r\n    }\r\n    ModInt operator -(const ModInt\
    \ &rhs) const{\r\n        return ModInt(*this)-=rhs;\r\n    }\r\n    // \u4E57\
    \u7B97\r\n    ModInt &operator *=(const ModInt &rhs){\r\n        x*=rhs.x;\r\n\
    \        if(x>=MOD) x%=MOD;\r\n        return (*this);\r\n    }\r\n    ModInt\
    \ operator *(const ModInt &rhs) const{\r\n        return ModInt(*this)*=rhs;\r\
    \n    }\r\n    // \u9664\u7B97\r\n    ModInt &operator /=(const ModInt &rhs){\r\
    \n        (*this)*=rhs.inverse();\r\n        return (*this);\r\n    }\r\n    ModInt\
    \ operator /(const ModInt &rhs) const{\r\n        return ModInt(*this)/=rhs;\r\
    \n    }\r\n    // \u7B49\u53F7\r\n    bool operator ==(const ModInt &rhs){\r\n\
    \        return x==rhs.x;\r\n    }\r\n    bool operator !=(const ModInt &rhs){\r\
    \n        return x!=rhs.x;\r\n    }\r\n    // \u7D2F\u4E57\r\n    ModInt pow(fint64\
    \ n) const{\r\n        fint64 tmp=x;\r\n        fint64 ret=1;\r\n        while(n>0){\r\
    \n            if(n&1) ret=ret*tmp%MOD;\r\n            tmp=tmp*tmp%MOD;\r\n   \
    \         n>>=1ll;\r\n        }\r\n        return ModInt(ret);\r\n    }\r\n  \
    \  // \u9006\u5143\r\n    ModInt inverse() const{\r\n        fint64 a=x,b=MOD,s=1,t=0;\r\
    \n        while(b>0){\r\n            fint64 u=a/b;\r\n            a-=u*b;\r\n\
    \            s-=u*t;\r\n            swap(a,b);\r\n            swap(s,t);\r\n \
    \       }\r\n        return ModInt(s);\r\n    }\r\n    // \u5165\u51FA\u529B\r\
    \n    friend istream &operator >>(istream &lhs,ModInt<MOD> &rhs){\r\n        fint64\
    \ x; lhs>>x;\r\n        rhs=ModInt<MOD>(x);\r\n        return lhs;\r\n    }\r\n\
    \    friend ostream &operator <<(ostream &lhs,const ModInt<MOD> &rhs){\r\n   \
    \     return lhs<<rhs.x;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/Math/ModInt/ModInt.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/Math/ModInt/ModInt.cpp
layout: document
redirect_from:
- /library/tmp/Math/ModInt/ModInt.cpp
- /library/tmp/Math/ModInt/ModInt.cpp.html
title: tmp/Math/ModInt/ModInt.cpp
---
