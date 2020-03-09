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


# :warning: is_prime.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/is_prime.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-11 14:06:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 素数判定

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

bool is_prime(int n){
    if(n<2) return 0; //素数は2以上
	if(n==2 || n==3) return 1; //2,3は素数
    if(n%2==0 || n%3==0) return 0; //2,3の倍数を消去
    //以降素数は6k±1にしかない
    if(n%6!=1 && n%6!=5) return 0;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0) return 0; //6k-1
        if(n%(i+2)==0) return 0; //6k+1
    }
    return 1;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "is_prime.cpp"
// 素数判定

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

bool is_prime(int n){
    if(n<2) return 0; //素数は2以上
	if(n==2 || n==3) return 1; //2,3は素数
    if(n%2==0 || n%3==0) return 0; //2,3の倍数を消去
    //以降素数は6k±1にしかない
    if(n%6!=1 && n%6!=5) return 0;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0) return 0; //6k-1
        if(n%(i+2)==0) return 0; //6k+1
    }
    return 1;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

