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


# :warning: tmp/GraphTheory/LCA/verify/GRL_5_C.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#95823e082aa65886d45d316a0caae256">tmp/GraphTheory/LCA/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/GraphTheory/LCA/verify/GRL_5_C.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 19:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
int main(){
    int n; cin>>n;
    vector<vector<int>> g(n+1);
    for(int i=0;i<n;i++){
        int k; cin>>k;
        while(k--){
            int c; cin>>c;
            g[i].push_back(c);
            g[c].push_back(i);
        }
    }
    LCA lca(n,0,g);
    int q; cin>>q;
    while(q--){
        int u,v; cin>>u>>v;
        cout<<lca.get(u,v)<<endl;
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/GraphTheory/LCA/verify/GRL_5_C.cpp"
int main(){
    int n; cin>>n;
    vector<vector<int>> g(n+1);
    for(int i=0;i<n;i++){
        int k; cin>>k;
        while(k--){
            int c; cin>>c;
            g[i].push_back(c);
            g[c].push_back(i);
        }
    }
    LCA lca(n,0,g);
    int q; cin>>q;
    while(q--){
        int u,v; cin>>u>>v;
        cout<<lca.get(u,v)<<endl;
    }
    return 0;
}

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

