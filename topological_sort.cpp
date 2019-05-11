#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

struct topological_sort{
    const int V;
    vector<vector<int>> board;
    vector<int> into,list;
    vector<bool> visited;
    topological_sort(int v)
        :V(v)
        ,into(v,0)
        ,visited(v,false)
        {
            board.assign(v,vector<int>());
        }
    // 入力
    void add(int from,int to){
        board[from].push_back(to);
        into[to]++;
    }
    // トポロジカルソート
    void build(){
        for(int i=0;i<V;i++){
            if(into[i]==0&&!visited[i]){
                queue<int> q;
                q.push(i);
                while(q.size()){
                    int from=q.front(); q.pop();
                    list.push_back(from);
                    visited[from]=true;
                    for(int to:board[from]){
                        into[to]--;
                        if(into[to]==0&&!visited[to]){
                            q.push(to);
                        }
                    }
                }
            }
        }
    }
    // 取得
    vector<int> get(){
        return list;
    }
};
// verify
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp
int main(){
    int V,E; cin>>V>>E;
    topological_sort graph(V);
    while(E--){
        int s,t; cin>>s>>t;
        graph.add(s,t);
    }
    graph.build();
    vector<int> l=graph.get();
    rep(i,V) cout<<l[i]<<(i==V-1?"\n":" ");
    return 0;
}
