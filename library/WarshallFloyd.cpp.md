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


# :warning: WarshallFloyd.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/WarshallFloyd.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-11 14:06:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// Warshall_Floyd法
// 2点間の最短距離を求める
// 計算量O(V^3)

#include <bits/stdc++.h>
using namespace std;

// オーバーフローしないようにINFをとる
const int INF=1e9;
const long long LINF=1e15;

template<class T>
struct WarshallFloyd{
    // 頂点数(1-indexed)
    const int V;
    // d[from][to]:=2点間の最短距離
    vector<vector<T>> d;
    WarshallFloyd(const int V):
        V(V)
        {
            d=vector<vector<T>>(V+1,vector<T>(V+1,INF));
        }
    void build(){
        for(int i=0;i<=V;i++){               //経由点i
            for(int j=0;j<=V;j++){           //始点j
                for(int k=0;k<=V;k++){       //終点k
    				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
                }
            }
    	}
    }
};
// verify
// https://atcoder.jp/contests/abc012/tasks/abc012_4
int main(){
    int n,m; cin>>n>>m;
    WarshallFloyd<long long> wf(n);
    while(m--){
        int a,b,t; cin>>a>>b>>t;
        wf.d[a][b]=t;
        wf.d[b][a]=t;
    }
    wf.build();
    long long ans=LINF;
    for(int i=1;i<=n;i++){
        long long tmp=0;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            tmp=max(tmp,wf.d[i][j]);
        }
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "WarshallFloyd.cpp"
// Warshall_Floyd法
// 2点間の最短距離を求める
// 計算量O(V^3)

#include <bits/stdc++.h>
using namespace std;

// オーバーフローしないようにINFをとる
const int INF=1e9;
const long long LINF=1e15;

template<class T>
struct WarshallFloyd{
    // 頂点数(1-indexed)
    const int V;
    // d[from][to]:=2点間の最短距離
    vector<vector<T>> d;
    WarshallFloyd(const int V):
        V(V)
        {
            d=vector<vector<T>>(V+1,vector<T>(V+1,INF));
        }
    void build(){
        for(int i=0;i<=V;i++){               //経由点i
            for(int j=0;j<=V;j++){           //始点j
                for(int k=0;k<=V;k++){       //終点k
    				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
                }
            }
    	}
    }
};
// verify
// https://atcoder.jp/contests/abc012/tasks/abc012_4
int main(){
    int n,m; cin>>n>>m;
    WarshallFloyd<long long> wf(n);
    while(m--){
        int a,b,t; cin>>a>>b>>t;
        wf.d[a][b]=t;
        wf.d[b][a]=t;
    }
    wf.build();
    long long ans=LINF;
    for(int i=1;i<=n;i++){
        long long tmp=0;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            tmp=max(tmp,wf.d[i][j]);
        }
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

