// Warshall_Floyd法
// 2点間の最短距離を求める
// 計算量O(V^3)

#include <bits/stdc++.h>
using namespace std;

// オーバーフローしないようにINFをとる
const int INF=1e9;
const long long LINF=1e15;

template<class T>
struct WarshallFloyd{
    // 頂点数(1-indexed)
    const int V;
    // d[from][to]:=2点間の最短距離
    vector<vector<T>> d;
    WarshallFloyd(const int V):
        V(V)
        {
            d=vector<vector<T>>(V+1,vector<T>(V+1,INF));
        }
    void build(){
        for(int i=0;i<=V;i++){               //経由点i
            for(int j=0;j<=V;j++){           //始点j
                for(int k=0;k<=V;k++){       //終点k
    				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
                }
            }
    	}
    }
};
// verify
// https://atcoder.jp/contests/abc012/tasks/abc012_4
int main(){
    int n,m; cin>>n>>m;
    WarshallFloyd<long long> wf(n);
    while(m--){
        int a,b,t; cin>>a>>b>>t;
        wf.d[a][b]=t;
        wf.d[b][a]=t;
    }
    wf.build();
    long long ans=LINF;
    for(int i=1;i<=n;i++){
        long long tmp=0;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            tmp=max(tmp,wf.d[i][j]);
        }
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}
