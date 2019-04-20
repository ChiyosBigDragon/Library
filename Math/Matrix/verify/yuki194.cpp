int main(){
    const int MOD=1e9+7;
    using mint=ModInt<MOD>;
    long long n,k; cin>>n>>k;
    // はずれ
    if(k<=n){
        mint f,sum=0;
        for(int i=1;i<=k;i++){
            cin>>f;
            sum+=f;
        }
        cout<<f<<" "<<sum<<endl;
        return 0;
    }
    // テスト1
    if(n>30){
        mint f[k+1],s[k+1];
        for(int i=1;i<=n;i++){
            cin>>f[i];
            s[i]=f[i]+s[i-1];
        }
        for(int i=n+1;i<=k;i++){
            f[i]=s[i-1]-s[i-n-1];
            s[i]=f[i]+s[i-1];
        }
        cout<<f[k]<<" "<<s[k]<<endl;
        return 0;
    }
    // テスト2
    mint f[n+1],s[n+1];
    for(int i=1;i<=n;i++){
        cin>>f[i];
        s[i]=f[i]+s[i-1];
    }
    Matrix<mint> mat(n+1,n+1);
    mat[0][0]=2;
    mat[0][n]=-1;
    for(int y=1;y<n+1;y++){
        mat[y][y-1]=1;
    }
    mat.pow(k-n);
    mint sk,sk1;
    for(int x=0;x<n+1;x++){
        sk+=mat[0][x]*s[n-x];
        sk1+=mat[1][x]*s[n-x];
    }
    cout<<sk-sk1<<" "<<sk<<endl;
    return 0;
}
