#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

map<long long,int> mp;
vector<long long> prime_factorization(long long n){
    vector<long long> v;
    if(n==1) v.push_back(1);
    long long i=2;
    while(n>1){
        if(n<i*i){
            v.push_back(n);
            mp[n]++;
            return v;
        }
        if(n%i==0){
            n/=i;
            v.push_back(i);
            mp[i]++;
        }else{
            i++;
        }
    }
    return v;
}

int main(){
    int n=1000000;
    vector<long long> v=prime_factorization(n);
    for(auto i:v) cout<<i<<" ";
    return 0;
}
