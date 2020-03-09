int main(){
    int n; cin>>n;
    vector<vector<int>> g(n+1);
    for(int i=0;i<n-1;i++){
        int x,y; cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    LCA lca(n,1,g);
    int q; cin>>q;
    while(q--){
        int a,b; cin>>a>>b;
        int ad=lca.depthOrder[lca.nodeFirstID[a]];
        int bd=lca.depthOrder[lca.nodeFirstID[b]];
        int cd=lca.depthOrder[lca.nodeFirstID[lca.get(a,b)]];
        cout<<abs(ad-cd)+abs(bd-cd)+1<<endl;
    }
    return 0;
}
