int main(){
    const int MOD=1e9+7;
    Combination com(MOD);
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n,k,tmp=0;
        for(int i=2;i<(int)s.size();i++){
            if(s[i]==')'){
                k=tmp;
            }else if(s[i]==','){
                n=tmp;
                tmp=0;
            }else{
                tmp*=10;
                tmp+=s[i]-'0';
            }
        }
        if(s[0]=='C') cout<<com.C(n,k)<<endl;
        if(s[0]=='P') cout<<com.P(n,k)<<endl;
        if(s[0]=='H') cout<<com.H(n,k)<<endl;
    }
    return 0;
}
