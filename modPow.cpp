// 繰り返し二乗法
// 累乗の高速化
// 計算量O(logN)

#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

//a^nを求める
long long modpow(long long a,long long n){
    long long x=1;
    while(n>0){
        //nの2進数表記の右端が1
        if(n&1){
            x=x*a%MOD;
        }
        a=a*a%MOD;
        n>>=1; //nを右に1bitずらす
    }
    return x;
}

int main(){
    int a,n; cin>>a>>n;
    cout<<modpow(a,n)<<endl;
    return 0;
}
