// 素数判定

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

bool is_prime(int n){
    if(n<2) return 0; //素数は2以上
	if(n==2 || n==3) return 1; //2,3は素数
    if(n%2==0 || n%3==0) return 0; //2,3の倍数を消去
    //以降素数は6k±1にしかない
    if(n%6!=1 && n%6!=5) return 0;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0) return 0; //6k-1
        if(n%(i+2)==0) return 0; //6k+1
    }
    return 1;
}
