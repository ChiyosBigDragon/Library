// root取るときはちゃんとroot()してください．
// par[]で取得できるのは圧縮済のときのみです

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

struct UnionFind{
    // 頂点数(1-indexed)
    const int V;
    // par[x]:=xのroot
    vector<int> par;
    // sz[x]:=xを含む集合のサイズ
    vector<int> sz;
    UnionFind(const int V):V(V){
        par.resize(V+1);
        for(int i=0;i<=V;i++) par[i]=i;
        sz.resize(V+1,1);
    }
    bool unite(int x,int y){
        x=root(x),y=root(y);
        if(same(x,y)) return false;
        if(y<x) swap(x,y);
        par[y]=x;
        sz[x]+=sz[y];
        return true;
    }
    int root(int x){
    	if(par[x]==x) return x; // xはroot
    	return (par[x]=root(par[x])); // xの親のroot
    }
    bool same(int x,int y){
    	return (root(x)==root(y));
    }
    int size(int x){
        return sz[root(x)];
    }
};

// verify
// https://atcoder.jp/contests/atc001/tasks/unionfind_a
// int main(){
//     int n,q; cin>>n>>q;
//     UnionFind uf(n);
//     while(q--){
//         int p,a,b; cin>>p>>a>>b;
//         if(p==0) uf.unite(a,b);
//         else cout<<(uf.same(a,b)?"Yes":"No")<<endl;
//     }
//     return 0;
// }
// https://atcoder.jp/contests/abc120/tasks/abc120_d
// int main(){
//     long long n,m; cin>>n>>m;
//     UnionFind uf(n);
//     long long a[m],b[m],ans[m];
//     rep(i,m) cin>>a[i]>>b[i];
//     ans[m-1]=n*(n-1)/2;
//     for(int q=m-2;q>=0;q--){
//         ans[q]=ans[q+1];
//         if(!uf.same(a[q+1],b[q+1])) ans[q]-=(long long)uf.size(a[q+1])*(long long)uf.size(b[q+1]);
//         uf.unite(a[q+1],b[q+1]);
//     }
//     rep(q,m) cout<<ans[q]<<endl;
//     return 0;
// }
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp
// int main(){
//     int n,q; cin>>n>>q;
//     UnionFind uf(n);
//     while(q--){
//         int com,x,y; cin>>com>>x>>y;
//         if(com==0) uf.unite(x,y);
//         else cout<<(uf.same(x,y)?1:0)<<endl;
//     }
//     return 0;
// }
