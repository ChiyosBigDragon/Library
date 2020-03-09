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


# :warning: tmp/Dijkstra.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#fa816edb83e95bf0c8da580bdfd491ef">tmp</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/Dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 19:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// Dijkstra法(枝刈りあり)
// 始点から全点間の最短距離を求める
// 見つからないときはINF
// 計算量O((E+V)logE)
// verify
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;

const int VMAX=100010;
int V,E,start,goal;
vector<pair<long long,int>> edge[VMAX];
long long dist[VMAX];
bool used[VMAX];

void dijkstra(){
    // 距離をLINFで初期化
    rep(to,VMAX) dist[to]=LINF;
    // 始点は0
    dist[start]=0;
    // フラグを下げる
    rep(v,VMAX) used[v]=false;
    // 優先度付きキュー:[距離,頂点]←距離の昇順
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
    // 距離0,始点
    q.push({0,start});
    // dijkstra
    while(q.size()){
        // 取り出してd=距離,v=頂点
        pair<long long,int> p=q.top(); q.pop();
        long long d=p.first;
        int from=p.second;
        if(used[from]) continue;
        used[from]=true;
        // 頂点から出る辺すべてについて
        for(auto e:edge[from]){
            long long cost=e.first,to=e.second;
            // 短縮できるとき
            if(d+cost<dist[to]){
                dist[to]=d+cost;
                q.push({dist[to],to});
            }
        }
    }
}

int main(){
    cin>>V>>E>>start>>goal;
    rep(i,E){
        int from,to,distance;
        cin>>from>>to>>distance;
        edge[from].push_back({distance,to});
        edge[to].push_back({distance,from});
    }
    dijkstra();
    cout<<dist[goal]<<endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/Dijkstra.cpp"
// Dijkstra法(枝刈りあり)
// 始点から全点間の最短距離を求める
// 見つからないときはINF
// 計算量O((E+V)logE)
// verify
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;

const int VMAX=100010;
int V,E,start,goal;
vector<pair<long long,int>> edge[VMAX];
long long dist[VMAX];
bool used[VMAX];

void dijkstra(){
    // 距離をLINFで初期化
    rep(to,VMAX) dist[to]=LINF;
    // 始点は0
    dist[start]=0;
    // フラグを下げる
    rep(v,VMAX) used[v]=false;
    // 優先度付きキュー:[距離,頂点]←距離の昇順
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
    // 距離0,始点
    q.push({0,start});
    // dijkstra
    while(q.size()){
        // 取り出してd=距離,v=頂点
        pair<long long,int> p=q.top(); q.pop();
        long long d=p.first;
        int from=p.second;
        if(used[from]) continue;
        used[from]=true;
        // 頂点から出る辺すべてについて
        for(auto e:edge[from]){
            long long cost=e.first,to=e.second;
            // 短縮できるとき
            if(d+cost<dist[to]){
                dist[to]=d+cost;
                q.push({dist[to],to});
            }
        }
    }
}

int main(){
    cin>>V>>E>>start>>goal;
    rep(i,E){
        int from,to,distance;
        cin>>from>>to>>distance;
        edge[from].push_back({distance,to});
        edge[to].push_back({distance,from});
    }
    dijkstra();
    cout<<dist[goal]<<endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

