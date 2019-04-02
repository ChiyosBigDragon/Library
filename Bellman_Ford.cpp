// 工事中

// Bellman_Ford法
// 始点終点間の最短距離を求める(負経路込み)
// 見つからないときはINF
// 閉路があるときはNEGATIVE CYCLEを出力
// 計算量O(VE)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=1e9,MOD=1e9+7; // オーバーフローしないようにINFをとる


struct edge{
	int from,to,cost;
};
int V,E;   // 頂点数V,辺E
int start; // 始点

vector<int> d; // d[i]:=始点から点iまでの距離
edge e[2000];

bool Bellman_Ford(int start){
    d=vector<int>(V,INF);     // 全点をINFで初期化
    d[start]=0;               // startとの距離0
    for(int i=0;i<V;i++){
		bool update=false;
        for(int j=0;j<E;j++){
            if(d[e[j].from]!=INF&&d[e[j].to]>d[e[j].from]+e[j].cost){
                d[e[j].to]=d[e[j].from]+e[j].cost;
                    update=true;
            }
        }
		if(!update) break;
		if(i==V-1&&update){
			return false;
		}
    }
    return true;
}

int main(){
	cin>>V>>E>>start;
	// V*VのgraphをINFで初期化
    rep(i,E){
        cin>>e[i].from>>e[i].to>>e[i].cost;
    }
	if(!Bellman_Ford(start)){
		cout<<"NEGATIVE CYCLE"<<endl;
	}else{
		rep(i,V){
	        if(d[i]==INF) cout<<"INF"<<endl;
	        else cout<<d[i]<<endl;
	    }
	}
	return 0;
}
