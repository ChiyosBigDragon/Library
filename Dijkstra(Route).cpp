// Dijkstra法(枝刈りあり)(無向木経路探索)
// 「終点」から全点間の最短距離を求める
// 最短経路を辞書順最小で表示
// 計算量O((E+V)logE)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX;

const int VMAX=300;
int V,E,start,goal;
int board[VMAX][VMAX];
int dist[VMAX];
bool used[VMAX];
vector<int> route;

void Dijkstra(){
    // 距離をINFで初期化
    rep(to,VMAX) dist[to]=INF;
    // 始点は0
    dist[goal]=0;
    // フラグを下げる
    rep(v,VMAX) used[v]=false;
    // 優先度付きキュー:[距離,頂点]←距離の昇順
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    // 距離0,始点
    q.push(make_pair(0,goal));
    // dijkstra
    while(q.size()){
        // 取り出してd=距離,v=頂点
        pair<int,int> p=q.top(); q.pop();
        int d=p.first,v=p.second;
        if(used[v]) continue;
        used[v]=true;
        // 頂点から出る辺すべてについて
        for(int to=0;to<V;to++){
            // 辺が存在して短縮できるとき
            if(board[v][to]>0 && d+board[v][to]<dist[to]){
                dist[to]=d+board[v][to];
                q.push(make_pair(dist[to],to));
            }
        }
    }
}

void Route(int from){
    route.push_back(from);
    if(from==goal) return;
    rep(to,V){
        if(board[from][to]>0){
            // 最短距離から逆算する
            if(dist[from]==dist[to]+board[from][to]){
                Route(to);
                return;
            }
        }
    }
}

int main(){
    rep(i,VMAX)rep(j,VMAX) board[i][j]=-1;
    cin>>V>>E>>start>>goal;
    rep(i,E){
        int from,to,distance;
        cin>>from>>to>>distance;
        board[from][to]=board[to][from]=distance;
    }
    Dijkstra();
    Route(start);
    for(auto i:route) cout<<i<<(i!=goal?" ":"");
    cout<<endl;
    return 0;
}
