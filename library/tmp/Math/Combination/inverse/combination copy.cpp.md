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
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :warning: tmp/Math/Combination/inverse/combination copy.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#c77cf685f67ae44b42909da57e1be54a">tmp/Math/Combination/inverse</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/Math/Combination/inverse/combination copy.cpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Combination{
    const int MAX=5000010;
    const int MOD;
    vector<long long> FAC;
    vector<long long> INV;
    vector<long long> FAC_INV;
    Combination(const int MOD):
        MOD(MOD)
        {
            FAC=vector<long long>(MAX);
            INV=vector<long long>(MAX);
            FAC_INV=vector<long long>(MAX);
            FAC[0]=INV[1]=FAC_INV[0]=1;
            for(int i=1;i<MAX;i++){
                FAC[i]=FAC[i-1]*i%MOD;
                if(i>1) INV[i]=MOD-INV[MOD%i]*(MOD/i)%MOD;
                FAC_INV[i]=FAC_INV[i-1]*INV[i]%MOD;
            }
        }
    int C(int n,int r){
        if(n<0||r<0||n<r) return 0;
        return FAC[n]*FAC_INV[r]%MOD*FAC_INV[n-r]%MOD;
    }
    int P(int n,int r){
        if(n<0||r<0||n<r) return 0;
        return FAC[n]*FAC_INV[n-r]%MOD;
    }
    int H(int n,int r){
        if(r==0) return 1;
        return C(n+r-1,r);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/Math/Combination/inverse/combination copy.cpp"
#include <bits/stdc++.h>
using namespace std;

struct Combination{
    const int MAX=5000010;
    const int MOD;
    vector<long long> FAC;
    vector<long long> INV;
    vector<long long> FAC_INV;
    Combination(const int MOD):
        MOD(MOD)
        {
            FAC=vector<long long>(MAX);
            INV=vector<long long>(MAX);
            FAC_INV=vector<long long>(MAX);
            FAC[0]=INV[1]=FAC_INV[0]=1;
            for(int i=1;i<MAX;i++){
                FAC[i]=FAC[i-1]*i%MOD;
                if(i>1) INV[i]=MOD-INV[MOD%i]*(MOD/i)%MOD;
                FAC_INV[i]=FAC_INV[i-1]*INV[i]%MOD;
            }
        }
    int C(int n,int r){
        if(n<0||r<0||n<r) return 0;
        return FAC[n]*FAC_INV[r]%MOD*FAC_INV[n-r]%MOD;
    }
    int P(int n,int r){
        if(n<0||r<0||n<r) return 0;
        return FAC[n]*FAC_INV[n-r]%MOD;
    }
    int H(int n,int r){
        if(r==0) return 1;
        return C(n+r-1,r);
    }
};

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

