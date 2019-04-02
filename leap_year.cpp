#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

bool leap_year(int n){
    if(n%400==0) return true;
    if(n%100==0) return false;
    if(n%4==0) return true;
    return false;
}

int main(){
    for(int i=1500;i<=2000;i++){
        if(leap_year(i)) cout<<i<<endl;
    }
    return 0;
}
