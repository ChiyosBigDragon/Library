int main(){
    int n,m,l; cin>>n>>m>>l;
    Matrix<long long> a(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    Matrix<long long> b(m,l);
    for(int i=0;i<m;i++){
        for(int j=0;j<l;j++){
            cin>>b[i][j];
        }
    }
    (a*b).debug();
    return 0;
}
