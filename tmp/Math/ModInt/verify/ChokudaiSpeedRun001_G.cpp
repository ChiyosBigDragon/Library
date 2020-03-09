int main(){
    const int MOD=1e9+7;
    using mint=ModInt<MOD>;
    int n; cin>>n;
    mint ans;
    char c;
    while(cin>>c){
        ans*=10;
        ans+=c-'0';
    }
    cout<<ans<<endl;
    return 0;
}
