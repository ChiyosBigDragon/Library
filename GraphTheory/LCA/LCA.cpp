#include <bits/stdc++.h>
using namespace std;

struct SegmentTreeForLCA{
    int sz;
    // {深さ,id}
    vector<pair<int,int>> seg;
    // 初期化
    void resize(int n){
        sz=1;
        while(sz<n) sz<<=1;
        seg.resize(sz<<1,{1<<30,-1});
    }
    // 代入
    void set(int id,int depth){
        seg[id+sz]={depth,id};
    }
    // 構築
    void build(){
        for(int k=sz-1;k>0;k--){
            seg[k]=min(seg[2*k],seg[2*k+1]);
        }
    }
    // [l,r]の結果を取得
    int get(int l,int r){
        pair<int,int> L={1<<30,-1},R={1<<30,-1};
        l+=sz,r+=sz+1;
        for(;l<r;l>>=1,r>>=1){
            if(l&1) L=min(L,seg[l++]);
            if(r&1) R=min(seg[--r],R);
        }
        return min(L,R).second;
    }
};
struct LCA{
    const int V;
    const int root;
    const vector<vector<int>> &edge;
    vector<int> nodeOrder;
    vector<int> depthOrder;
    vector<int> nodeFirstID;
    SegmentTreeForLCA seg;
    LCA(int V,int root,vector<vector<int>> edge):
        V(V),
        root(root),
        edge(edge)
        {
            const int MAX=2*V-1;
            nodeOrder.resize(MAX);
            depthOrder.resize(MAX);
            nodeFirstID.resize(V+1,-1);
            eulerTour(root,-1,0);
            seg.resize(MAX);
            for(int id=0;id<MAX;id++){
                seg.set(id,depthOrder[id]);
            }
            seg.build();
        }
    int id=0;
    void eulerTour(int from,int par,int depth){
        nodeOrder[id]=from;
        depthOrder[id]=depth;
        nodeFirstID[from]=id;
        id++;
        for(int to:edge[from]){
            if(to==par) continue;
            eulerTour(to,from,depth+1);
            nodeOrder[id]=from;
            depthOrder[id]=depth;
            id++;
        }
    }
    // uとvのLCA
    int get(int u,int v){
        return nodeOrder[seg.get(min(nodeFirstID[u],nodeFirstID[v]),max(nodeFirstID[u],nodeFirstID[v]))];
    }
};
