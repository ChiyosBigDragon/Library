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


# :warning: MST.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/MST.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-11 14:06:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 最小全域木のコスト(プリム法)
// verify
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

const int VMAX=10010;
int V,E;
vector<vector<pair<int,int>>> edge;
bool used[VMAX];
long long MST(int start){
    if(V==1) return 0;
    rep(i,VMAX) used[i]=0;
    // {cost,{from,to}}
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(auto e:edge[start]){
        pq.push({e.second,{start,e.first}});
    }
    long long ret=0;
    int cnt=1;
    while(pq.size()||cnt<V){
        auto e=pq.top(); pq.pop();
        int cost=e.first,from=e.second.first,to=e.second.second;
        used[from]=1;
        if(!used[to]){
            ret+=cost;
            used[to]=1;
            cnt++;
            for(auto e:edge[to]){
                pq.push({e.second,{to,e.first}});
            }
        }
    }
    return (cnt==V?ret:-1);
}
int main(){
    cin>>V>>E;
    edge.resize(V);
    int start;
    rep(i,E){
        int from,to,cost; cin>>from>>to>>cost;
        start=from;
        edge[from].push_back({to,cost});
        edge[to].push_back({from,cost});
    }
    cout<<MST(start)<<endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "MST.cpp"
// 最小全域木のコスト(プリム法)
// verify
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

const int VMAX=10010;
int V,E;
vector<vector<pair<int,int>>> edge;
bool used[VMAX];
long long MST(int start){
    if(V==1) return 0;
    rep(i,VMAX) used[i]=0;
    // {cost,{from,to}}
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(auto e:edge[start]){
        pq.push({e.second,{start,e.first}});
    }
    long long ret=0;
    int cnt=1;
    while(pq.size()||cnt<V){
        auto e=pq.top(); pq.pop();
        int cost=e.first,from=e.second.first,to=e.second.second;
        used[from]=1;
        if(!used[to]){
            ret+=cost;
            used[to]=1;
            cnt++;
            for(auto e:edge[to]){
                pq.push({e.second,{to,e.first}});
            }
        }
    }
    return (cnt==V?ret:-1);
}
int main(){
    cin>>V>>E;
    edge.resize(V);
    int start;
    rep(i,E){
        int from,to,cost; cin>>from>>to>>cost;
        start=from;
        edge[from].push_back({to,cost});
        edge[to].push_back({from,cost});
    }
    cout<<MST(start)<<endl;
    return 0;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

