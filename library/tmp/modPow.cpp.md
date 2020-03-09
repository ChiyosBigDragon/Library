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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: tmp/modPow.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#fa816edb83e95bf0c8da580bdfd491ef">tmp</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/modPow.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 19:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 繰り返し二乗法
// 累乗の高速化
// 計算量O(logN)

#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

//a^nを求める
long long modpow(long long a,long long n){
    long long x=1;
    while(n>0){
        //nの2進数表記の右端が1
        if(n&1){
            x=x*a%MOD;
        }
        a=a*a%MOD;
        n>>=1; //nを右に1bitずらす
    }
    return x;
}

int main(){
    int a,n; cin>>a>>n;
    cout<<modpow(a,n)<<endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/modPow.cpp"
// 繰り返し二乗法
// 累乗の高速化
// 計算量O(logN)

#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

//a^nを求める
long long modpow(long long a,long long n){
    long long x=1;
    while(n>0){
        //nの2進数表記の右端が1
        if(n&1){
            x=x*a%MOD;
        }
        a=a*a%MOD;
        n>>=1; //nを右に1bitずらす
    }
    return x;
}

int main(){
    int a,n; cin>>a>>n;
    cout<<modpow(a,n)<<endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

