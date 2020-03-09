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


# :warning: Bellman_Ford.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/Bellman_Ford.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-11 14:06:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 工事中

// Bellman_Ford法
// 始点終点間の最短距離を求める(負経路込み)
// 見つからないときはINF
// 閉路があるときはNEGATIVE CYCLEを出力
// 計算量O(VE)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=1e9,MOD=1e9+7; // オーバーフローしないようにINFをとる


struct edge{
	int from,to,cost;
};
int V,E;   // 頂点数V,辺E
int start; // 始点

vector<int> d; // d[i]:=始点から点iまでの距離
edge e[2000];

bool Bellman_Ford(int start){
    d=vector<int>(V,INF);     // 全点をINFで初期化
    d[start]=0;               // startとの距離0
    for(int i=0;i<V;i++){
		bool update=false;
        for(int j=0;j<E;j++){
            if(d[e[j].from]!=INF&&d[e[j].to]>d[e[j].from]+e[j].cost){
                d[e[j].to]=d[e[j].from]+e[j].cost;
                    update=true;
            }
        }
		if(!update) break;
		if(i==V-1&&update){
			return false;
		}
    }
    return true;
}

int main(){
	cin>>V>>E>>start;
	// V*VのgraphをINFで初期化
    rep(i,E){
        cin>>e[i].from>>e[i].to>>e[i].cost;
    }
	if(!Bellman_Ford(start)){
		cout<<"NEGATIVE CYCLE"<<endl;
	}else{
		rep(i,V){
	        if(d[i]==INF) cout<<"INF"<<endl;
	        else cout<<d[i]<<endl;
	    }
	}
	return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Bellman_Ford.cpp"
// 工事中

// Bellman_Ford法
// 始点終点間の最短距離を求める(負経路込み)
// 見つからないときはINF
// 閉路があるときはNEGATIVE CYCLEを出力
// 計算量O(VE)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=1e9,MOD=1e9+7; // オーバーフローしないようにINFをとる


struct edge{
	int from,to,cost;
};
int V,E;   // 頂点数V,辺E
int start; // 始点

vector<int> d; // d[i]:=始点から点iまでの距離
edge e[2000];

bool Bellman_Ford(int start){
    d=vector<int>(V,INF);     // 全点をINFで初期化
    d[start]=0;               // startとの距離0
    for(int i=0;i<V;i++){
		bool update=false;
        for(int j=0;j<E;j++){
            if(d[e[j].from]!=INF&&d[e[j].to]>d[e[j].from]+e[j].cost){
                d[e[j].to]=d[e[j].from]+e[j].cost;
                    update=true;
            }
        }
		if(!update) break;
		if(i==V-1&&update){
			return false;
		}
    }
    return true;
}

int main(){
	cin>>V>>E>>start;
	// V*VのgraphをINFで初期化
    rep(i,E){
        cin>>e[i].from>>e[i].to>>e[i].cost;
    }
	if(!Bellman_Ford(start)){
		cout<<"NEGATIVE CYCLE"<<endl;
	}else{
		rep(i,V){
	        if(d[i]==INF) cout<<"INF"<<endl;
	        else cout<<d[i]<<endl;
	    }
	}
	return 0;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

