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


# :warning: tmp/Math/ModInt/verify/ChokudaiSpeedRun001_G.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#e1dd9be4c93b41ca242fc9510df5f942">tmp/Math/ModInt/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/Math/ModInt/verify/ChokudaiSpeedRun001_G.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 19:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
int main(){
    const int MOD=1e9+7;
    using mint=ModInt<MOD>;
    int n; cin>>n;
    mint ans;
    char c;
    while(cin>>c){
        ans*=10;
        ans+=c-'0';
    }
    cout<<ans<<endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/Math/ModInt/verify/ChokudaiSpeedRun001_G.cpp"
int main(){
    const int MOD=1e9+7;
    using mint=ModInt<MOD>;
    int n; cin>>n;
    mint ans;
    char c;
    while(cin>>c){
        ans*=10;
        ans+=c-'0';
    }
    cout<<ans<<endl;
    return 0;
}

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

