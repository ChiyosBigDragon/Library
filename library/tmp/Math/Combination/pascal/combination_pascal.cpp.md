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


# :warning: tmp/Math/Combination/pascal/combination_pascal.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#ae3783e453db1d5e00197869d6a0cced">tmp/Math/Combination/pascal</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/Math/Combination/pascal/combination_pascal.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 19:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

struct CombinationOnPascal{
    const int MAX=2010;
    const int MOD;
    vector<vector<int>> COM;
    vector<vector<int>> PER;
    CombinationOnPascal(const int MOD):
        MOD(MOD)
        {
            COM=vector<vector<int>>(MAX,vector<int>(MAX));
            PER=vector<vector<int>>(MAX,vector<int>(MAX));
            COM[0][0]=PER[0][0]=1;
            for(int i=1;i<MAX;i++){
                COM[i][0]=PER[i][0]=1;
                for(int j=1;j<MAX;j++){
                    COM[i][j]=(COM[i-1][j-1]+COM[i-1][j])%MOD;
                    PER[i][j]=PER[i][j-1]*(i-j+1)%MOD;
                }
            }
        }
    int C(int n,int r){
        if(n<0||r<0||n<r) return 0;
        return COM[n][r];
    }
    int P(int n,int r){
        if(n<0||r<0||n<r) return 0;
        return PER[n][r];
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
#line 1 "tmp/Math/Combination/pascal/combination_pascal.cpp"
#include <bits/stdc++.h>
using namespace std;

struct CombinationOnPascal{
    const int MAX=2010;
    const int MOD;
    vector<vector<int>> COM;
    vector<vector<int>> PER;
    CombinationOnPascal(const int MOD):
        MOD(MOD)
        {
            COM=vector<vector<int>>(MAX,vector<int>(MAX));
            PER=vector<vector<int>>(MAX,vector<int>(MAX));
            COM[0][0]=PER[0][0]=1;
            for(int i=1;i<MAX;i++){
                COM[i][0]=PER[i][0]=1;
                for(int j=1;j<MAX;j++){
                    COM[i][j]=(COM[i-1][j-1]+COM[i-1][j])%MOD;
                    PER[i][j]=PER[i][j-1]*(i-j+1)%MOD;
                }
            }
        }
    int C(int n,int r){
        if(n<0||r<0||n<r) return 0;
        return COM[n][r];
    }
    int P(int n,int r){
        if(n<0||r<0||n<r) return 0;
        return PER[n][r];
    }
    int H(int n,int r){
        if(r==0) return 1;
        return C(n+r-1,r);
    }
};

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

