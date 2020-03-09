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


# :warning: tmp/prime_factorization.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#fa816edb83e95bf0c8da580bdfd491ef">tmp</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/prime_factorization.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 19:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

map<long long,int> mp;
vector<long long> prime_factorization(long long n){
    vector<long long> v;
    if(n==1) v.push_back(1);
    long long i=2;
    while(n>1){
        if(n<i*i){
            v.push_back(n);
            mp[n]++;
            return v;
        }
        if(n%i==0){
            n/=i;
            v.push_back(i);
            mp[i]++;
        }else{
            i++;
        }
    }
    return v;
}

int main(){
    int n=1000000;
    vector<long long> v=prime_factorization(n);
    for(auto i:v) cout<<i<<" ";
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/prime_factorization.cpp"
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

map<long long,int> mp;
vector<long long> prime_factorization(long long n){
    vector<long long> v;
    if(n==1) v.push_back(1);
    long long i=2;
    while(n>1){
        if(n<i*i){
            v.push_back(n);
            mp[n]++;
            return v;
        }
        if(n%i==0){
            n/=i;
            v.push_back(i);
            mp[i]++;
        }else{
            i++;
        }
    }
    return v;
}

int main(){
    int n=1000000;
    vector<long long> v=prime_factorization(n);
    for(auto i:v) cout<<i<<" ";
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

