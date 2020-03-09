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


# :warning: imos1d.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/imos1d.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-11 14:06:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template<class T>
struct imos1d{
    vector<T> board;
    imos1d(int n)
        :board(n+2)
    {}
    // 矩形加算
    void add(pair<int,int> lr,T z){
        int l=lr.first,r=lr.second;
        board[l]+=z;
        board[r+1]-=z;
    }
    // 累積和
    void build(){
        for(int i=1;i<(int)board.size();i++){
            board[i]+=board[i-1];
        }
    }
    // 値取得
    T get(int i){
        return board[i];
    }
    // debug
    void debug(){
        for(int i=1;i<(int)board.size()-1;i++){
            cout<<board[i]<<" ";
        }
        cout<<endl;
    }
};
// verify
int main(){
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "imos1d.cpp"
#include <bits/stdc++.h>
using namespace std;

template<class T>
struct imos1d{
    vector<T> board;
    imos1d(int n)
        :board(n+2)
    {}
    // 矩形加算
    void add(pair<int,int> lr,T z){
        int l=lr.first,r=lr.second;
        board[l]+=z;
        board[r+1]-=z;
    }
    // 累積和
    void build(){
        for(int i=1;i<(int)board.size();i++){
            board[i]+=board[i-1];
        }
    }
    // 値取得
    T get(int i){
        return board[i];
    }
    // debug
    void debug(){
        for(int i=1;i<(int)board.size()-1;i++){
            cout<<board[i]<<" ";
        }
        cout<<endl;
    }
};
// verify
int main(){
    return 0;
}

```
{% endraw %}

<a href="../index.html">Back to top page</a>

