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


# :warning: tmp/binary_search.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#fa816edb83e95bf0c8da580bdfd491ef">tmp</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/binary_search.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 19:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 二分探索
// key以上で「最小」となる要素のindexを返す
// また、keyが見つかった場合"find"を出力する
// 計算量O(logN)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

// 単調増加列a
vector<int> a={1,14,32,51,51,51,243,419,750,910};

// indexが条件を満たすか?
bool isOK(int index,int key){
    if(a[index]>=key) return true;
    else return false;
}

// 二分探索
int binary_search(int key){
	// key以上の値をとるindexは全てokとする
    int ng=-1; // aの左の範囲外は必ずng
    int ok=(int)a.size(); // aの右の範囲外は必ずok

    while (abs(ok-ng)>1) {
        int mid=(ok+ng)/2;
        if(isOK(mid,key)) ok=mid;
        else ng=mid;
    }
    return ok;
}

int main(){
	int key=51;
	int index=binary_search(key);
    cout<<index<<endl;
	if(a[index]==key) cout<<"find"<<endl;
	return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/binary_search.cpp"
// 二分探索
// key以上で「最小」となる要素のindexを返す
// また、keyが見つかった場合"find"を出力する
// 計算量O(logN)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

// 単調増加列a
vector<int> a={1,14,32,51,51,51,243,419,750,910};

// indexが条件を満たすか?
bool isOK(int index,int key){
    if(a[index]>=key) return true;
    else return false;
}

// 二分探索
int binary_search(int key){
	// key以上の値をとるindexは全てokとする
    int ng=-1; // aの左の範囲外は必ずng
    int ok=(int)a.size(); // aの右の範囲外は必ずok

    while (abs(ok-ng)>1) {
        int mid=(ok+ng)/2;
        if(isOK(mid,key)) ok=mid;
        else ng=mid;
    }
    return ok;
}

int main(){
	int key=51;
	int index=binary_search(key);
    cout<<index<<endl;
	if(a[index]==key) cout<<"find"<<endl;
	return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

