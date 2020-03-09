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


# :warning: LIS.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/LIS.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-11 14:06:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

template<class T>
struct LIS{
    const int n;
    const T INF;
    using F=function<bool(T,T)>;
    const vector<T> val;
    const F comp;
    vector<T> dp;
    LIS(const int n,const T INF,const vector<T>& val,const F comp):n(n),INF(INF),val(val),comp(comp){
        dp.resize(n+1,INF);
    }
    // 構築
    int sz=0;
    void build(){
        for(T i:val){
            auto itr=lower_bound(dp.begin(),dp.end(),i,comp);
            *itr=i;
            sz=max(sz,(int)(itr-dp.begin()));
        }
    }
    int size(){
        return sz+1;
    }
    vector<T> get(){
        int sz=size()-1;
        vector<T> ret;
        for(int i=n-1;i>=0&&sz>=0;i--){
            if((dp[sz]==val[i]||comp(dp[sz],val[i]))&&comp(val[i],dp[sz+1])){
                ret.push_back(val[i]);
                sz--;
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp
int main(){
    int n; cin>>n;
    vector<int> a(n); rep(i,n) cin>>a[i];
    LIS<int> lis(n,INF,a,[](int a,int b){return a<b;});
    lis.build();
    cout<<lis.size()<<endl;
    return 0;
}
// https://atcoder.jp/contests/abc038/tasks/abc038_d
// int main(){
//     int n; cin>>n;
//     pair<int,int> box[n];
//     rep(i,n){
//         int w,h; cin>>w>>h;
//         box[i]={w,-h};
//     }
//     sort(box,box+n);
//     vector<int> a(n);
//     rep(i,n) a[i]=-box[i].second;
//     LIS<int> lis(a.size(),INF,a,[](int a,int b){return a<b;});
//     lis.build();
//     cout<<lis.size()<<endl;
//     return 0;
// }

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "LIS.cpp"
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

template<class T>
struct LIS{
    const int n;
    const T INF;
    using F=function<bool(T,T)>;
    const vector<T> val;
    const F comp;
    vector<T> dp;
    LIS(const int n,const T INF,const vector<T>& val,const F comp):n(n),INF(INF),val(val),comp(comp){
        dp.resize(n+1,INF);
    }
    // 構築
    int sz=0;
    void build(){
        for(T i:val){
            auto itr=lower_bound(dp.begin(),dp.end(),i,comp);
            *itr=i;
            sz=max(sz,(int)(itr-dp.begin()));
        }
    }
    int size(){
        return sz+1;
    }
    vector<T> get(){
        int sz=size()-1;
        vector<T> ret;
        for(int i=n-1;i>=0&&sz>=0;i--){
            if((dp[sz]==val[i]||comp(dp[sz],val[i]))&&comp(val[i],dp[sz+1])){
                ret.push_back(val[i]);
                sz--;
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp
int main(){
    int n; cin>>n;
    vector<int> a(n); rep(i,n) cin>>a[i];
    LIS<int> lis(n,INF,a,[](int a,int b){return a<b;});
    lis.build();
    cout<<lis.size()<<endl;
    return 0;
}
// https://atcoder.jp/contests/abc038/tasks/abc038_d
// int main(){
//     int n; cin>>n;
//     pair<int,int> box[n];
//     rep(i,n){
//         int w,h; cin>>w>>h;
//         box[i]={w,-h};
//     }
//     sort(box,box+n);
//     vector<int> a(n);
//     rep(i,n) a[i]=-box[i].second;
//     LIS<int> lis(a.size(),INF,a,[](int a,int b){return a<b;});
//     lis.build();
//     cout<<lis.size()<<endl;
//     return 0;
// }

```
{% endraw %}

<a href="../index.html">Back to top page</a>

