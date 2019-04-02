// combination
// nCk(mod p)←pは素数!!!!!!!!!

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

const long long MAX=510000;
const long long MOD=1e9+7;
// 階乗,逆元,逆元の階乗
long long fac[MAX],inv[MAX],finv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
// 二項係数計算
long long COM(long long n,long long k){
    if(n<k) return 0;
    if(n<0||k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int main() {
    // 前処理
    COMinit();
    // 計算例(C(10,3)%MOD)
    cout << COM(10,3) << endl;
    return 0;
}
