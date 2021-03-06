// 最小全域木のコスト(プリム法)
// verify
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

const int VMAX=10010;
int V,E;
vector<vector<pair<int,int>>> edge;
bool used[VMAX];
long long MST(int start){
    if(V==1) return 0;
    rep(i,VMAX) used[i]=0;
    // {cost,{from,to}}
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    for(auto e:edge[start]){
        pq.push({e.second,{start,e.first}});
    }
    long long ret=0;
    int cnt=1;
    while(pq.size()||cnt<V){
        auto e=pq.top(); pq.pop();
        int cost=e.first,from=e.second.first,to=e.second.second;
        used[from]=1;
        if(!used[to]){
            ret+=cost;
            used[to]=1;
            cnt++;
            for(auto e:edge[to]){
                pq.push({e.second,{to,e.first}});
            }
        }
    }
    return (cnt==V?ret:-1);
}
int main(){
    cin>>V>>E;
    edge.resize(V);
    int start;
    rep(i,E){
        int from,to,cost; cin>>from>>to>>cost;
        start=from;
        edge[from].push_back({to,cost});
        edge[to].push_back({from,cost});
    }
    cout<<MST(start)<<endl;
    return 0;
}
