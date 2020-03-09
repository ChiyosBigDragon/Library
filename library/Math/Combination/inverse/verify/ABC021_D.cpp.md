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


# :warning: Math/Combination/inverse/verify/ABC021_D.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#0bcf0a0641ff0778c76a271e9fa52e02">Math/Combination/inverse/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Combination/inverse/verify/ABC021_D.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-11 14:06:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
int main(){
    const int MOD=1e9+7;
    Combination com(MOD);
    int n,k; cin>>n>>k;
    cout<<com.H(n,k)<<endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/Combination/inverse/verify/ABC021_D.cpp"
int main(){
    const int MOD=1e9+7;
    Combination com(MOD);
    int n,k; cin>>n>>k;
    cout<<com.H(n,k)<<endl;
    return 0;
}

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

