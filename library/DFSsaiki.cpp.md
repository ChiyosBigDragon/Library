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


# :warning: DFSsaiki.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/DFSsaiki.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-11 14:06:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 深さ優先探索(再帰)
// 辞書順最小経路を求める
// 計算量O(E)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

int n,m,ans=0;
int a[10][10]={};
bool visited[10];

int dfs(int now){
	visited[now]=1;
	bool all=1;
	rep(i,n){
		if(!visited[i]) all=0;
	}
	if(all) return ++ans;
	rep(i,n){
		if(visited[i]) continue;
		if(!a[now][i]) continue;
		dfs(i);
		visited[i]=0;
	}
	return ans;
}

int main(){
	cin>>n>>m;
	rep(i,m){
		int b,c; cin>>b>>c;
		a[b-1][c-1]=a[c-1][b-1]=1;
	}
	rep(i,n) visited[i]=0;
	cout<<dfs(0)<<endl;
	return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DFSsaiki.cpp"
// 深さ優先探索(再帰)
// 辞書順最小経路を求める
// 計算量O(E)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

int n,m,ans=0;
int a[10][10]={};
bool visited[10];

int dfs(int now){
	visited[now]=1;
	bool all=1;
	rep(i,n){
		if(!visited[i]) all=0;
	}
	if(all) return ++ans;
	rep(i,n){
		if(visited[i]) continue;
		if(!a[now][i]) continue;
		dfs(i);
		visited[i]=0;
	}
	return ans;
}

int main(){
	cin>>n>>m;
	rep(i,m){
		int b,c; cin>>b>>c;
		a[b-1][c-1]=a[c-1][b-1]=1;
	}
	rep(i,n) visited[i]=0;
	cout<<dfs(0)<<endl;
	return 0;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

