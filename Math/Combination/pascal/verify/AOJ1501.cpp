int main(){
    const int MOD=100000007;
    CombinationOnPascal com(MOD);
    int r,c,a1,a2,b1,b2; cin>>r>>c>>a1>>a2>>b1>>b2;
    int h1=abs(a1-b1),h2=r-abs(a1-b1);
    int h=min(h1,h2);
    int w1=abs(a2-b2),w2=c-abs(a2-b2);
    int w=min(w1,w2);
    int ans=com.C(h+w,h);
    if(h1==h2) ans=ans*2%MOD;
    if(w1==w2) ans=ans*2%MOD;
    cout<<ans<<endl;
    return 0;
}
