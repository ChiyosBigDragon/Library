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
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: gcd_lcm.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/gcd_lcm.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-11 14:06:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 最大公約数

#include <bits/stdc++.h>
using namespace std;
inline long long mod(long long n,long long m){return(n%m+m)%m;}

long long gcd(long long x,long long y){
    return y>0?gcd(y,x%y):x;
}
long long lcm(long long x,long long y){
    return x/gcd(x,y)*y;
}
// gcd(a,b)とax+by=gcd(a,b)を満たす(x,y)
long long ex_gcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        // gcd(a,b)x+0y=gcd(a,b)
        x=1,y=0;
        return a;
    }
    long long d=ex_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
// x≡{b}(mod{m})を満たすx(mod(lcm{m}))
long long CRT(vector<long long> b,vector<long long> m){
    // x≡0(mod1)は全ての整数
    long long ret=0,M=1;
    for(int i=0;i<(int)b.size();i++){
        long long x,y;
        long long d=ex_gcd(M,m[i],x,y);
        if((b[i]-ret)%d) return -1;
        // 最後にMで割るので共通しないもので剰余
        ret+=(b[i]-ret)/d*x%(m[i]/d)*M;
        M*=m[i]/d;
    }
    return mod(ret,M);
}
int main(){
    int x,y; cin>>x>>y;
    cout<<gcd(x,y)<<endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "gcd_lcm.cpp"
// 最大公約数

#include <bits/stdc++.h>
using namespace std;
inline long long mod(long long n,long long m){return(n%m+m)%m;}

long long gcd(long long x,long long y){
    return y>0?gcd(y,x%y):x;
}
long long lcm(long long x,long long y){
    return x/gcd(x,y)*y;
}
// gcd(a,b)とax+by=gcd(a,b)を満たす(x,y)
long long ex_gcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        // gcd(a,b)x+0y=gcd(a,b)
        x=1,y=0;
        return a;
    }
    long long d=ex_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
// x≡{b}(mod{m})を満たすx(mod(lcm{m}))
long long CRT(vector<long long> b,vector<long long> m){
    // x≡0(mod1)は全ての整数
    long long ret=0,M=1;
    for(int i=0;i<(int)b.size();i++){
        long long x,y;
        long long d=ex_gcd(M,m[i],x,y);
        if((b[i]-ret)%d) return -1;
        // 最後にMで割るので共通しないもので剰余
        ret+=(b[i]-ret)/d*x%(m[i]/d)*M;
        M*=m[i]/d;
    }
    return mod(ret,M);
}
int main(){
    int x,y; cin>>x>>y;
    cout<<gcd(x,y)<<endl;
    return 0;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

