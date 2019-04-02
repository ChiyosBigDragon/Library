#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

template<class T>
struct WeightedUnionFind{
    // 頂点数(1-indexed)
    const int V;
    // par[x]:=xのroot
    vector<int> par;
    // sz[x]:=xを含む集合のサイズ
    vector<int> sz;
    // w[x]:=xのrootに対する重み
    vector<T> w;
    WeightedUnionFind(const int V):V(V){
        par.resize(V+1);
        for(int i=0;i<=V;i++) par[i]=i;
        sz.resize(V+1,1);
        w.resize(V+1);
    }
    // w[y] - w[x] = z
    bool unite(int x,int y,T z){
        z=z+weight(x)-weight(y);
        x=root(x),y=root(y);
        if(same(x,y)) return false;
        if(y<x){
            swap(x,y);
            z=-z;
        }
        par[y]=x;
        sz[x]+=sz[y];
        w[y]=z;
        return true;
    }
    int root(int x){
    	if(par[x]==x) return x; // xはroot
        root(par[x]); // rootから累積和
        w[x]+=w[par[x]]; // 親の重みを加算する
    	return (par[x]=root(par[x])); // xの親のroot
    }
    bool same(int x,int y){
    	return (root(x)==root(y));
    }
    int size(int x){
        return sz[root(x)];
    }
    T weight(int x){
        root(x); // 経路圧縮用
        return w[x];
    }
    T diff(int x,int y){
        assert(same(x,y));
        return weight(y)-weight(x);
    }
};

// https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
int main(){
    int n,q; cin>>n>>q;
    WeightedUnionFind<long long> uf(n);
    while(q--){
        int info,x,y,z; cin>>info>>x>>y;
        if(info==0){
            cin>>z;
            uf.unite(x,y,z);
        }else{
            if(uf.same(x,y)){
                cout<<uf.diff(x,y)<<endl;
            }else{
                cout<<"?"<<endl;
            }
        }
    }
    return 0;
}
