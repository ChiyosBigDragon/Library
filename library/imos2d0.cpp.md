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


# :warning: imos2d0.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/imos2d0.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-11 14:06:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template<class T>
struct imos2d{
    vector<vector<T>> board;
    imos2d(int w,int h)
        :board(w+2,vector<int>(h+2,0))
    {}
    // 矩形加算
    void add(pair<int,int> xy1,pair<int,int> xy2,T z){
        int x1=xy1.first,y1=xy1.second;
        int x2=xy2.first,y2=xy2.second;
        board[x1][y1]+=z;
        board[x1][y2+1]-=z;
        board[x2+1][y1]-=z;
        board[x2+1][y2+1]+=z;
    }
    // 累積和
    void build(){
        for(int x=1;x<(int)board.size();x++){
            for(int y=1;y<(int)board[0].size();y++){
                board[x][y]+=board[x][y-1];
            }
        }
        for(int x=1;x<(int)board.size();x++){
            for(int y=1;y<(int)board[0].size();y++){
                board[x][y]+=board[x-1][y];
            }
        }
    }
    // 値取得
    T get(int x,int y){
        return board[x][y];
    }
    // debug
    void debug(){
        for(int x=1;x<(int)board.size()-1;x++){
            for(int y=1;y<(int)board[0].size()-1;y++){
                cout<<board[x][y]<<" ";
            }
            cout<<endl;
        }
    }
};
// verify
// https://beta.atcoder.jp/contests/abc106/tasks/abc106_d
int main(){
    int n,m,q; cin>>n>>m>>q;
    imos2d<int> imos(n,n);
    while(m--){
        int l,r; cin>>l>>r;
        imos.add({1,r},{l,n},1);
    }
    imos.build();
    while(q--){
        int l,r; cin>>l>>r;
        cout<<imos.get(l,r)<<endl;
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "imos2d0.cpp"
#include <bits/stdc++.h>
using namespace std;

template<class T>
struct imos2d{
    vector<vector<T>> board;
    imos2d(int w,int h)
        :board(w+2,vector<int>(h+2,0))
    {}
    // 矩形加算
    void add(pair<int,int> xy1,pair<int,int> xy2,T z){
        int x1=xy1.first,y1=xy1.second;
        int x2=xy2.first,y2=xy2.second;
        board[x1][y1]+=z;
        board[x1][y2+1]-=z;
        board[x2+1][y1]-=z;
        board[x2+1][y2+1]+=z;
    }
    // 累積和
    void build(){
        for(int x=1;x<(int)board.size();x++){
            for(int y=1;y<(int)board[0].size();y++){
                board[x][y]+=board[x][y-1];
            }
        }
        for(int x=1;x<(int)board.size();x++){
            for(int y=1;y<(int)board[0].size();y++){
                board[x][y]+=board[x-1][y];
            }
        }
    }
    // 値取得
    T get(int x,int y){
        return board[x][y];
    }
    // debug
    void debug(){
        for(int x=1;x<(int)board.size()-1;x++){
            for(int y=1;y<(int)board[0].size()-1;y++){
                cout<<board[x][y]<<" ";
            }
            cout<<endl;
        }
    }
};
// verify
// https://beta.atcoder.jp/contests/abc106/tasks/abc106_d
int main(){
    int n,m,q; cin>>n>>m>>q;
    imos2d<int> imos(n,n);
    while(m--){
        int l,r; cin>>l>>r;
        imos.add({1,r},{l,n},1);
    }
    imos.build();
    while(q--){
        int l,r; cin>>l>>r;
        cout<<imos.get(l,r)<<endl;
    }
    return 0;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

