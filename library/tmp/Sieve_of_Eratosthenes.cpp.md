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


# :warning: tmp/Sieve_of_Eratosthenes.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#fa816edb83e95bf0c8da580bdfd491ef">tmp</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/Sieve_of_Eratosthenes.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 19:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// エラトステネスの篩
// 素数を列挙
// 計算量O(NloglogN)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

//nまでの素数を列挙
void Sieve_of_Eratosthenes(int n){
	n++;
    bool list[n]; rep(i,n) list[i]=1; //全数にフラグ
	//2の倍数,3の倍数…と削っていく
    for(int i=2;i*i<n;i++){
        if(list[i]){
            for(int j=2;i*j<n;j++) list[i*j]=0;
        }
    }
	//フラグが立っていれば素数
    for(int i=2;i<n;i++){
        if(list[i]) cout<<i<<endl;
    }
}

// int main(){
//  	Sieve_of_Eratosthenes(100);
// }

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/Sieve_of_Eratosthenes.cpp"
// エラトステネスの篩
// 素数を列挙
// 計算量O(NloglogN)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

//nまでの素数を列挙
void Sieve_of_Eratosthenes(int n){
	n++;
    bool list[n]; rep(i,n) list[i]=1; //全数にフラグ
	//2の倍数,3の倍数…と削っていく
    for(int i=2;i*i<n;i++){
        if(list[i]){
            for(int j=2;i*j<n;j++) list[i*j]=0;
        }
    }
	//フラグが立っていれば素数
    for(int i=2;i<n;i++){
        if(list[i]) cout<<i<<endl;
    }
}

// int main(){
//  	Sieve_of_Eratosthenes(100);
// }

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

