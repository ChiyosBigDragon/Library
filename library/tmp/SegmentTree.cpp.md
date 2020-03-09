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


# :warning: tmp/SegmentTree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#fa816edb83e95bf0c8da580bdfd491ef">tmp</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/SegmentTree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 19:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 0-indexed

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

template<class T>
struct SegmentTree{
    using F=function<T(T,T)>;
    const T init;
    const F f;
    int sz;
    vector<T> seg;
    SegmentTree(int n,const T init,const F f):
        init(init),
        f(f)
        {
            sz=1;
            while(sz<n) sz<<=1;
            seg.resize(sz<<1,init);
        }
    // 代入
    void set(int id,T x){
        seg[id+sz]=x;
    }
    // 構築
    void build(){
        for(int k=sz-1;k>0;k--){
            seg[k]=f(seg[2*k],seg[2*k+1]);
        }
    }
    // 更新
    void update(int id){
        while(id>>=1){
            seg[id]=f(seg[2*id],seg[2*id+1]);
        }
    }
    // 置換
    void replace(int id,T x){
        id+=sz;
        seg[id]=x;
        update(id);
    }
    // 加算
    void add(int id,T x){
        id+=sz;
        seg[id]+=x;
        update(id);
    }
    // [l,r)の結果を取得
    T get(int l,int r){
        T L=init,R=init;
        l+=sz,r+=sz;
        for(;l<r;l>>=1,r>>=1){
            if(l&1) L=f(L,seg[l++]);
            if(r&1) R=f(seg[--r],R);
        }
        return f(L,R);
    }
    // debug
    void debug(){
        int i=1;
        for(int r=2;r<=2*sz;r<<=1){
            while(i<r){
                cout<<seg[i++]<<" ";
            }
            cout<<"\n";
        }
    }
};
// verify
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
int main(){
    int n,q; cin>>n>>q;
    SegmentTree<int> seg(n,(1ll<<31)-1,[](int a,int b){return min(a,b);});
    while(q--){
        int com,x,y; cin>>com>>x>>y;
        if(com==0) seg.replace(x,y);
        else cout<<seg.get(x,y+1)<<endl;
        // seg.debug();
    }
    return 0;
}
// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
// int main(){
//     int n,q; cin>>n>>q;
//     SegmentTree<int> seg(n,0,[](int a,int b){return a+b;});
//     while(q--){
//         int com,x,y; cin>>com>>x>>y;
//         if(com==0) seg.add(x,y);
//         else cout<<seg.get(x,y+1)<<endl;
//         // seg.debug();
//     }
//     return 0;
// }
// https://atcoder.jp/contests/arc008/tasks/arc008_4
// int main(){
//     long long n,m; cin>>n>>m;
//     set<long long> pp;
//     pair<long long,pair<double,double>> machen[m];
//     rep(i,m){
//         long long p; cin>>p;
//         pp.insert(p);
//         double a,b; cin>>a>>b;
//         machen[i]={p,{a,b}};
//     }
//     int id=0; map<long long,int> mp;
//     for(auto p:pp) mp[p]=(id++);
//     SegmentTree<pair<double,double>> seg(m,{1,0},[](pair<double,double> a,pair<double,double> b){return make_pair(a.first*b.first,a.second*b.first+b.second);});
//     // seg.debug();
//     double ansmax=1,ansmin=1;
//     rep(i,m){
//         long long p=machen[i].first;
//         double a=machen[i].second.first,b=machen[i].second.second;
//         seg.update(mp[p],{a,b});
//         auto x=seg.get(0,m);
//         double val=x.first+x.second;
//         ansmax=max(ansmax,val);
//         ansmin=min(ansmin,val);
//         // printf("%.10f\n",ansmin);
//         // printf("%.10f\n",ansmax);
//     }
//     printf("%.10f\n",ansmin);
//     printf("%.10f\n",ansmax);
//     return 0;
// }
// https://atcoder.jp/contests/abc125/tasks/abc125_c
// long long gcd(long long x,long long y){
//     return y>0?gcd(y,x%y):x;
// }
//
// int main(){
//     int n; cin>>n;
//     SegmentTree<int> seg(n,0,gcd);
//     for(int i=0;i<n;i++){
//         int a; cin>>a;
//         seg.replace(i,a);
//     }
//     int ans=0;
//     for(int i=0;i<n;i++){
//         int l=i>0?seg.get(0,i):0;
//         int r=i<n-1?seg.get(i+1,n):0;
//         ans=max(ans,(int)gcd(l,r));
//     }
//     cout<<ans<<endl;
//     return 0;
// }

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/SegmentTree.cpp"
// 0-indexed

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

template<class T>
struct SegmentTree{
    using F=function<T(T,T)>;
    const T init;
    const F f;
    int sz;
    vector<T> seg;
    SegmentTree(int n,const T init,const F f):
        init(init),
        f(f)
        {
            sz=1;
            while(sz<n) sz<<=1;
            seg.resize(sz<<1,init);
        }
    // 代入
    void set(int id,T x){
        seg[id+sz]=x;
    }
    // 構築
    void build(){
        for(int k=sz-1;k>0;k--){
            seg[k]=f(seg[2*k],seg[2*k+1]);
        }
    }
    // 更新
    void update(int id){
        while(id>>=1){
            seg[id]=f(seg[2*id],seg[2*id+1]);
        }
    }
    // 置換
    void replace(int id,T x){
        id+=sz;
        seg[id]=x;
        update(id);
    }
    // 加算
    void add(int id,T x){
        id+=sz;
        seg[id]+=x;
        update(id);
    }
    // [l,r)の結果を取得
    T get(int l,int r){
        T L=init,R=init;
        l+=sz,r+=sz;
        for(;l<r;l>>=1,r>>=1){
            if(l&1) L=f(L,seg[l++]);
            if(r&1) R=f(seg[--r],R);
        }
        return f(L,R);
    }
    // debug
    void debug(){
        int i=1;
        for(int r=2;r<=2*sz;r<<=1){
            while(i<r){
                cout<<seg[i++]<<" ";
            }
            cout<<"\n";
        }
    }
};
// verify
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A&lang=jp
int main(){
    int n,q; cin>>n>>q;
    SegmentTree<int> seg(n,(1ll<<31)-1,[](int a,int b){return min(a,b);});
    while(q--){
        int com,x,y; cin>>com>>x>>y;
        if(com==0) seg.replace(x,y);
        else cout<<seg.get(x,y+1)<<endl;
        // seg.debug();
    }
    return 0;
}
// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
// int main(){
//     int n,q; cin>>n>>q;
//     SegmentTree<int> seg(n,0,[](int a,int b){return a+b;});
//     while(q--){
//         int com,x,y; cin>>com>>x>>y;
//         if(com==0) seg.add(x,y);
//         else cout<<seg.get(x,y+1)<<endl;
//         // seg.debug();
//     }
//     return 0;
// }
// https://atcoder.jp/contests/arc008/tasks/arc008_4
// int main(){
//     long long n,m; cin>>n>>m;
//     set<long long> pp;
//     pair<long long,pair<double,double>> machen[m];
//     rep(i,m){
//         long long p; cin>>p;
//         pp.insert(p);
//         double a,b; cin>>a>>b;
//         machen[i]={p,{a,b}};
//     }
//     int id=0; map<long long,int> mp;
//     for(auto p:pp) mp[p]=(id++);
//     SegmentTree<pair<double,double>> seg(m,{1,0},[](pair<double,double> a,pair<double,double> b){return make_pair(a.first*b.first,a.second*b.first+b.second);});
//     // seg.debug();
//     double ansmax=1,ansmin=1;
//     rep(i,m){
//         long long p=machen[i].first;
//         double a=machen[i].second.first,b=machen[i].second.second;
//         seg.update(mp[p],{a,b});
//         auto x=seg.get(0,m);
//         double val=x.first+x.second;
//         ansmax=max(ansmax,val);
//         ansmin=min(ansmin,val);
//         // printf("%.10f\n",ansmin);
//         // printf("%.10f\n",ansmax);
//     }
//     printf("%.10f\n",ansmin);
//     printf("%.10f\n",ansmax);
//     return 0;
// }
// https://atcoder.jp/contests/abc125/tasks/abc125_c
// long long gcd(long long x,long long y){
//     return y>0?gcd(y,x%y):x;
// }
//
// int main(){
//     int n; cin>>n;
//     SegmentTree<int> seg(n,0,gcd);
//     for(int i=0;i<n;i++){
//         int a; cin>>a;
//         seg.replace(i,a);
//     }
//     int ans=0;
//     for(int i=0;i<n;i++){
//         int l=i>0?seg.get(0,i):0;
//         int r=i<n-1?seg.get(i+1,n):0;
//         ans=max(ans,(int)gcd(l,r));
//     }
//     cout<<ans<<endl;
//     return 0;
// }

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

