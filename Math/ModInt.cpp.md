---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/PointSetRangeComposite.test.cpp
    title: test/yosupo/PointSetRangeComposite.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: x ^ n
    links: []
  bundledCode: "#line 1 \"Math/ModInt.cpp\"\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n\r\n// BEGIN CUT HERE\r\n/**\r\n * @tparam MOD\r\n */\r\ntemplate<int_fast64_t\
    \ MOD>\r\nstruct ModInt {\r\npublic:\r\n\tint_fast64_t x;\r\n\tModInt() : x(0)\
    \ {}\r\n\tModInt(int_fast64_t x) : x(x >= 0 ? x % MOD : (MOD - (-x) % MOD) % MOD)\
    \ {}\r\n\tconstexpr ModInt operator-() const {\r\n\t\treturn ModInt(-x);\r\n\t\
    }\r\n\tconstexpr ModInt& operator+=(const ModInt& rhs) {\r\n\t\tx += rhs.x;\r\n\
    \t\tif(x >= MOD) {\r\n\t\t\tx -= MOD;\r\n\t\t}\r\n\t\treturn (*this);\r\n\t}\r\
    \n\tconstexpr ModInt operator+(const ModInt& rhs) const {\r\n\t\treturn ModInt(*this)\
    \ += rhs;\r\n\t}\r\n\tconstexpr ModInt& operator-=(const ModInt& rhs) {\r\n\t\t\
    x += MOD - rhs.x;\r\n\t\tif(x >= MOD) {\r\n\t\t\tx -= MOD;\r\n\t\t}\r\n\t\treturn\
    \ (*this);\r\n\t}\r\n\tconstexpr ModInt operator-(const ModInt& rhs) const {\r\
    \n\t\treturn ModInt(*this) -= rhs;\r\n\t}\r\n\tconstexpr ModInt& operator*=(const\
    \ ModInt& rhs) {\r\n\t\tx *= rhs.x;\r\n\t\tif(x >= MOD) {\r\n\t\t\tx %= MOD;\r\
    \n\t\t}\r\n\t\treturn (*this);\r\n\t}\r\n\tconstexpr ModInt operator*(const ModInt&\
    \ rhs) const {\r\n\t\treturn ModInt(*this) *= rhs;\r\n\t}\r\n\tconstexpr ModInt&\
    \ operator/=(const ModInt &rhs) {\r\n\t\t(*this) *= rhs.inverse();\r\n\t\treturn\
    \ (*this);\r\n\t}\r\n\tconstexpr ModInt operator/(const ModInt& rhs) const {\r\
    \n\t\treturn ModInt(*this) /= rhs;\r\n\t}\r\n\tconstexpr bool operator==(const\
    \ ModInt& rhs) {\r\n\t\treturn x == rhs.x;\r\n\t}\r\n\tconstexpr bool operator!=(const\
    \ ModInt& rhs) {\r\n\t\treturn x != rhs.x;\r\n\t}\r\n\t/**\r\n\t * @brief x ^\
    \ n\r\n\t */\r\n\tconstexpr ModInt pow(int_fast64_t n) const {\r\n\t\tint_fast64_t\
    \ tmp = x;\r\n\t\tint_fast64_t ret = 1;\r\n\t\twhile(n > 0){\r\n\t\t\tif(n & 1)\
    \ {\r\n\t\t\t\tret = ret * tmp % MOD;\r\n\t\t\t}\r\n\t\t\ttmp = tmp * tmp % MOD;\r\
    \n\t\t\tn >>= static_cast<int_fast64_t>(1);\r\n\t\t}\r\n\t\treturn ModInt(ret);\r\
    \n\t}\r\n\t/**\r\n\t * @brief 1 / x\r\n\t */\r\n\tconstexpr ModInt inverse() const\
    \ {\r\n\t\tint_fast64_t a = x, b = MOD, s = 1, t = 0;\r\n\t\twhile(b > 0) {\r\n\
    \t\t\tint_fast64_t u = a / b;\r\n\t\t\ta -= u * b;\r\n\t\t\ts -= u * t;\r\n\t\t\
    \tswap(a, b);\r\n\t\t\tswap(s, t);\r\n\t\t}\r\n\t\treturn ModInt(s);\r\n\t}\r\n\
    \tfriend istream& operator>>(istream& lhs, ModInt<MOD>& rhs) {\r\n\t\tint_fast64_t\
    \ x;\r\n\t\tlhs >> x;\r\n\t\trhs = ModInt<MOD>(x);\r\n\t\treturn lhs;\r\n\t}\r\
    \n\tfriend ostream& operator<<(ostream& lhs, const ModInt<MOD>& rhs) {\r\n\t\t\
    return lhs << rhs.x;\r\n\t}\r\n};\r\n// END CUT HERE\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\n// BEGIN CUT HERE\r\
    \n/**\r\n * @tparam MOD\r\n */\r\ntemplate<int_fast64_t MOD>\r\nstruct ModInt\
    \ {\r\npublic:\r\n\tint_fast64_t x;\r\n\tModInt() : x(0) {}\r\n\tModInt(int_fast64_t\
    \ x) : x(x >= 0 ? x % MOD : (MOD - (-x) % MOD) % MOD) {}\r\n\tconstexpr ModInt\
    \ operator-() const {\r\n\t\treturn ModInt(-x);\r\n\t}\r\n\tconstexpr ModInt&\
    \ operator+=(const ModInt& rhs) {\r\n\t\tx += rhs.x;\r\n\t\tif(x >= MOD) {\r\n\
    \t\t\tx -= MOD;\r\n\t\t}\r\n\t\treturn (*this);\r\n\t}\r\n\tconstexpr ModInt operator+(const\
    \ ModInt& rhs) const {\r\n\t\treturn ModInt(*this) += rhs;\r\n\t}\r\n\tconstexpr\
    \ ModInt& operator-=(const ModInt& rhs) {\r\n\t\tx += MOD - rhs.x;\r\n\t\tif(x\
    \ >= MOD) {\r\n\t\t\tx -= MOD;\r\n\t\t}\r\n\t\treturn (*this);\r\n\t}\r\n\tconstexpr\
    \ ModInt operator-(const ModInt& rhs) const {\r\n\t\treturn ModInt(*this) -= rhs;\r\
    \n\t}\r\n\tconstexpr ModInt& operator*=(const ModInt& rhs) {\r\n\t\tx *= rhs.x;\r\
    \n\t\tif(x >= MOD) {\r\n\t\t\tx %= MOD;\r\n\t\t}\r\n\t\treturn (*this);\r\n\t\
    }\r\n\tconstexpr ModInt operator*(const ModInt& rhs) const {\r\n\t\treturn ModInt(*this)\
    \ *= rhs;\r\n\t}\r\n\tconstexpr ModInt& operator/=(const ModInt &rhs) {\r\n\t\t\
    (*this) *= rhs.inverse();\r\n\t\treturn (*this);\r\n\t}\r\n\tconstexpr ModInt\
    \ operator/(const ModInt& rhs) const {\r\n\t\treturn ModInt(*this) /= rhs;\r\n\
    \t}\r\n\tconstexpr bool operator==(const ModInt& rhs) {\r\n\t\treturn x == rhs.x;\r\
    \n\t}\r\n\tconstexpr bool operator!=(const ModInt& rhs) {\r\n\t\treturn x != rhs.x;\r\
    \n\t}\r\n\t/**\r\n\t * @brief x ^ n\r\n\t */\r\n\tconstexpr ModInt pow(int_fast64_t\
    \ n) const {\r\n\t\tint_fast64_t tmp = x;\r\n\t\tint_fast64_t ret = 1;\r\n\t\t\
    while(n > 0){\r\n\t\t\tif(n & 1) {\r\n\t\t\t\tret = ret * tmp % MOD;\r\n\t\t\t\
    }\r\n\t\t\ttmp = tmp * tmp % MOD;\r\n\t\t\tn >>= static_cast<int_fast64_t>(1);\r\
    \n\t\t}\r\n\t\treturn ModInt(ret);\r\n\t}\r\n\t/**\r\n\t * @brief 1 / x\r\n\t\
    \ */\r\n\tconstexpr ModInt inverse() const {\r\n\t\tint_fast64_t a = x, b = MOD,\
    \ s = 1, t = 0;\r\n\t\twhile(b > 0) {\r\n\t\t\tint_fast64_t u = a / b;\r\n\t\t\
    \ta -= u * b;\r\n\t\t\ts -= u * t;\r\n\t\t\tswap(a, b);\r\n\t\t\tswap(s, t);\r\
    \n\t\t}\r\n\t\treturn ModInt(s);\r\n\t}\r\n\tfriend istream& operator>>(istream&\
    \ lhs, ModInt<MOD>& rhs) {\r\n\t\tint_fast64_t x;\r\n\t\tlhs >> x;\r\n\t\trhs\
    \ = ModInt<MOD>(x);\r\n\t\treturn lhs;\r\n\t}\r\n\tfriend ostream& operator<<(ostream&\
    \ lhs, const ModInt<MOD>& rhs) {\r\n\t\treturn lhs << rhs.x;\r\n\t}\r\n};\r\n\
    // END CUT HERE"
  dependsOn: []
  isVerificationFile: false
  path: Math/ModInt.cpp
  requiredBy: []
  timestamp: '2020-10-11 19:08:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/PointSetRangeComposite.test.cpp
documentation_of: Math/ModInt.cpp
layout: document
redirect_from:
- /library/Math/ModInt.cpp
- /library/Math/ModInt.cpp.html
title: x ^ n
---
