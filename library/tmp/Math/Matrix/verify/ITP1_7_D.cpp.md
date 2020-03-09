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


# :warning: tmp/Math/Matrix/verify/ITP1_7_D.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#21cace77429b0eae219f5b50e59adfaf">tmp/Math/Matrix/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/Math/Matrix/verify/ITP1_7_D.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 19:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
int main(){
    int n,m,l; cin>>n>>m>>l;
    Matrix<long long> a(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    Matrix<long long> b(m,l);
    for(int i=0;i<m;i++){
        for(int j=0;j<l;j++){
            cin>>b[i][j];
        }
    }
    (a*b).debug();
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/Math/Matrix/verify/ITP1_7_D.cpp"
int main(){
    int n,m,l; cin>>n>>m>>l;
    Matrix<long long> a(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    Matrix<long long> b(m,l);
    for(int i=0;i<m;i++){
        for(int j=0;j<l;j++){
            cin>>b[i][j];
        }
    }
    (a*b).debug();
    return 0;
}

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

