// エラトステネスの篩
// 素数を列挙
// 計算量O(NloglogN)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

//nまでの素数を列挙
void Sieve_of_Eratosthenes(int n){
	n++;
    bool list[n]; rep(i,n) list[i]=1; //全数にフラグ
	//2の倍数,3の倍数…と削っていく
    for(int i=2;i*i<n;i++){
        if(list[i]){
            for(int j=2;i*j<n;j++) list[i*j]=0;
        }
    }
	//フラグが立っていれば素数
    for(int i=2;i<n;i++){
        if(list[i]) cout<<i<<endl;
    }
}

// int main(){
//  	Sieve_of_Eratosthenes(100);
// }
