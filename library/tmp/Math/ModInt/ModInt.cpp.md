---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :warning: tmp/Math/ModInt/ModInt.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#51f14846ca8674ab4b6e13d40504d6ba">tmp/Math/ModInt</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/Math/ModInt/ModInt.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 19:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

using fint64 = int_fast64_t;
template<fint64 MOD>
struct ModInt{
    fint64 x;
    ModInt():x(0){}
    ModInt(fint64 x):
        x(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD)
        {}
    // 負号
    ModInt operator -() const{
        return ModInt(-x);
    }
    // 加算
    ModInt &operator +=(const ModInt &rhs){
        x+=rhs.x;
        if(x>=MOD) x-=MOD;
        return (*this);
    }
    ModInt operator +(const ModInt &rhs) const{
        return ModInt(*this)+=rhs;
    }
    // 減算
    ModInt &operator -=(const ModInt &rhs){
        x+=MOD-rhs.x;
        if(x>=MOD) x-=MOD;
        return (*this);
    }
    ModInt operator -(const ModInt &rhs) const{
        return ModInt(*this)-=rhs;
    }
    // 乗算
    ModInt &operator *=(const ModInt &rhs){
        x*=rhs.x;
        if(x>=MOD) x%=MOD;
        return (*this);
    }
    ModInt operator *(const ModInt &rhs) const{
        return ModInt(*this)*=rhs;
    }
    // 除算
    ModInt &operator /=(const ModInt &rhs){
        (*this)*=rhs.inverse();
        return (*this);
    }
    ModInt operator /(const ModInt &rhs) const{
        return ModInt(*this)/=rhs;
    }
    // 等号
    bool operator ==(const ModInt &rhs){
        return x==rhs.x;
    }
    bool operator !=(const ModInt &rhs){
        return x!=rhs.x;
    }
    // 累乗
    ModInt pow(fint64 n) const{
        fint64 tmp=x;
        fint64 ret=1;
        while(n>0){
            if(n&1) ret=ret*tmp%MOD;
            tmp=tmp*tmp%MOD;
            n>>=1ll;
        }
        return ModInt(ret);
    }
    // 逆元
    ModInt inverse() const{
        fint64 a=x,b=MOD,s=1,t=0;
        while(b>0){
            fint64 u=a/b;
            a-=u*b;
            s-=u*t;
            swap(a,b);
            swap(s,t);
        }
        return ModInt(s);
    }
    // 入出力
    friend istream &operator >>(istream &lhs,ModInt<MOD> &rhs){
        fint64 x; lhs>>x;
        rhs=ModInt<MOD>(x);
        return lhs;
    }
    friend ostream &operator <<(ostream &lhs,const ModInt<MOD> &rhs){
        return lhs<<rhs.x;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/Math/ModInt/ModInt.cpp"
#include <bits/stdc++.h>
using namespace std;

using fint64 = int_fast64_t;
template<fint64 MOD>
struct ModInt{
    fint64 x;
    ModInt():x(0){}
    ModInt(fint64 x):
        x(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD)
        {}
    // 負号
    ModInt operator -() const{
        return ModInt(-x);
    }
    // 加算
    ModInt &operator +=(const ModInt &rhs){
        x+=rhs.x;
        if(x>=MOD) x-=MOD;
        return (*this);
    }
    ModInt operator +(const ModInt &rhs) const{
        return ModInt(*this)+=rhs;
    }
    // 減算
    ModInt &operator -=(const ModInt &rhs){
        x+=MOD-rhs.x;
        if(x>=MOD) x-=MOD;
        return (*this);
    }
    ModInt operator -(const ModInt &rhs) const{
        return ModInt(*this)-=rhs;
    }
    // 乗算
    ModInt &operator *=(const ModInt &rhs){
        x*=rhs.x;
        if(x>=MOD) x%=MOD;
        return (*this);
    }
    ModInt operator *(const ModInt &rhs) const{
        return ModInt(*this)*=rhs;
    }
    // 除算
    ModInt &operator /=(const ModInt &rhs){
        (*this)*=rhs.inverse();
        return (*this);
    }
    ModInt operator /(const ModInt &rhs) const{
        return ModInt(*this)/=rhs;
    }
    // 等号
    bool operator ==(const ModInt &rhs){
        return x==rhs.x;
    }
    bool operator !=(const ModInt &rhs){
        return x!=rhs.x;
    }
    // 累乗
    ModInt pow(fint64 n) const{
        fint64 tmp=x;
        fint64 ret=1;
        while(n>0){
            if(n&1) ret=ret*tmp%MOD;
            tmp=tmp*tmp%MOD;
            n>>=1ll;
        }
        return ModInt(ret);
    }
    // 逆元
    ModInt inverse() const{
        fint64 a=x,b=MOD,s=1,t=0;
        while(b>0){
            fint64 u=a/b;
            a-=u*b;
            s-=u*t;
            swap(a,b);
            swap(s,t);
        }
        return ModInt(s);
    }
    // 入出力
    friend istream &operator >>(istream &lhs,ModInt<MOD> &rhs){
        fint64 x; lhs>>x;
        rhs=ModInt<MOD>(x);
        return lhs;
    }
    friend ostream &operator <<(ostream &lhs,const ModInt<MOD> &rhs){
        return lhs<<rhs.x;
    }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

