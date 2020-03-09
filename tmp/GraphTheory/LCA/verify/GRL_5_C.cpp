int main(){
    int n; cin>>n;
    vector<vector<int>> g(n+1);
    for(int i=0;i<n;i++){
        int k; cin>>k;
        while(k--){
            int c; cin>>c;
            g[i].push_back(c);
            g[c].push_back(i);
        }
    }
    LCA lca(n,0,g);
    int q; cin>>q;
    while(q--){
        int u,v; cin>>u>>v;
        cout<<lca.get(u,v)<<endl;
    }
    return 0;
}
