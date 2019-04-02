// 最大公約数

#include <bits/stdc++.h>
using namespace std;
inline long long mod(long long n,long long m){return(n%m+m)%m;}

long long gcd(long long x,long long y){
    //Euclidの互除法
    if(!(x%y)) return y;
    return gcd(y,x%y);
}
long long lcm(long long x,long long y){
    return x/gcd(x,y)*y;
}
// gcd(a,b)とax+by=gcd(a,b)を満たす(x,y)
long long ex_gcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        // gcd(a,b)x+0y=gcd(a,b)
        x=1,y=0;
        return a;
    }
    long long d=ex_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
// x≡{b}(mod{m})を満たすx(mod(lcm{m}))
long long CRT(vector<long long> b,vector<long long> m){
    // x≡0(mod1)は全ての整数
    long long ret=0,M=1;
    for(int i=0;i<(int)b.size();i++){
        long long x,y;
        long long d=ex_gcd(M,m[i],x,y);
        if((b[i]-ret)%d) return -1;
        // 最後にMで割るので共通しないもので剰余
        ret+=(b[i]-ret)/d*x%(m[i]/d)*M;
        M*=m[i]/d;
    }
    return mod(ret,M);
}
int main(){
    int x,y; cin>>x>>y;
    cout<<gcd(x,y)<<endl;
    return 0;
}
