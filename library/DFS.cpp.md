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


# :warning: DFS.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/DFS.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-11 14:06:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 深さ優先探索
// 辞書順最小経路を求める
// 計算量O(E)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=1<<29;

int main(){
    //初期化
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    stack<pair<int,int>> st;
    int h,w,sy,sx,gy,gx; //盤面,スタート,ゴール
    cin>>h>>w>>sy>>sx>>gy>>gx;
    //sy--; sx--; gy--; gx--;
    char c[h][w]; int d[h][w]; //d[i][j]:=(j,i)までの最短経路
    rep(i,h){
        rep(j,w){
            cin>>c[i][j]; d[i][j]=INF;
        }
    }
    d[sy][sx]=0;
    st.push(make_pair(sy,sx));

    //実行
    while(st.size()){
        pair<int,int> p=st.top(); //スタックの最上を取り出す
        st.pop(); //取り出したら削除
        int prev=d[p.first][p.second]; //一手前の手数prev
        rep(i,4){ //4方向探索
            int cy=p.first+dy[i];
            int cx=p.second+dx[i];
            if(0<=cy&&cy<h&&0<=cx&&cx<w){ //範囲外取得キケン
                if(c[cy][cx]=='.' and d[cy][cx]==INF){ //通行可能かつ未到達
                    d[cy][cx]=prev+1;
                    st.push(make_pair(cy,cx)); //突っ込む
                }
            }
        }
    }
    cout<<d[gy][gx]<<endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DFS.cpp"
// 深さ優先探索
// 辞書順最小経路を求める
// 計算量O(E)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=1<<29;

int main(){
    //初期化
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    stack<pair<int,int>> st;
    int h,w,sy,sx,gy,gx; //盤面,スタート,ゴール
    cin>>h>>w>>sy>>sx>>gy>>gx;
    //sy--; sx--; gy--; gx--;
    char c[h][w]; int d[h][w]; //d[i][j]:=(j,i)までの最短経路
    rep(i,h){
        rep(j,w){
            cin>>c[i][j]; d[i][j]=INF;
        }
    }
    d[sy][sx]=0;
    st.push(make_pair(sy,sx));

    //実行
    while(st.size()){
        pair<int,int> p=st.top(); //スタックの最上を取り出す
        st.pop(); //取り出したら削除
        int prev=d[p.first][p.second]; //一手前の手数prev
        rep(i,4){ //4方向探索
            int cy=p.first+dy[i];
            int cx=p.second+dx[i];
            if(0<=cy&&cy<h&&0<=cx&&cx<w){ //範囲外取得キケン
                if(c[cy][cx]=='.' and d[cy][cx]==INF){ //通行可能かつ未到達
                    d[cy][cx]=prev+1;
                    st.push(make_pair(cy,cx)); //突っ込む
                }
            }
        }
    }
    cout<<d[gy][gx]<<endl;
    return 0;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

