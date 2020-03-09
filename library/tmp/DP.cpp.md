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


# :warning: tmp/DP.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#fa816edb83e95bf0c8da580bdfd491ef">tmp</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/DP.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 19:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX;

int main(){
    //dpテーブル
    int dp[110][10010];

    //初期化
    int n,A; cin>>n>>A;
    int a[n]; rep(i,n) cin>>a[i];
    //dp初期化(十分大きい値に)
    rep(i,110) rep(j,10010) dp[i][j]=INF;
    dp[0][0]=0; //選ばないで成り立つのは和0のみ

    rep(i,n){
        rep(sum,A+1){
            dp[i+1][sum]=min(dp[i+1][sum],dp[i][sum]);
            if(sum-a[i]>=0) dp[i+1][sum]=min(dp[i][sum-a[i]]+1,dp[i+1][sum]);
        }
    }
    if(dp[n][A]==INF) cout<<-1<<endl;
    else cout<<dp[n][A]<<endl;

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/DP.cpp"
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX;

int main(){
    //dpテーブル
    int dp[110][10010];

    //初期化
    int n,A; cin>>n>>A;
    int a[n]; rep(i,n) cin>>a[i];
    //dp初期化(十分大きい値に)
    rep(i,110) rep(j,10010) dp[i][j]=INF;
    dp[0][0]=0; //選ばないで成り立つのは和0のみ

    rep(i,n){
        rep(sum,A+1){
            dp[i+1][sum]=min(dp[i+1][sum],dp[i][sum]);
            if(sum-a[i]>=0) dp[i+1][sum]=min(dp[i][sum-a[i]]+1,dp[i+1][sum]);
        }
    }
    if(dp[n][A]==INF) cout<<-1<<endl;
    else cout<<dp[n][A]<<endl;

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

