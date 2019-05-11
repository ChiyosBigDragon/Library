#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX;

int main(){
    //dpテーブル
    int dp[110][10010];

    //初期化
    int n,A; cin>>n>>A;
    int a[n]; rep(i,n) cin>>a[i];
    //dp初期化(十分大きい値に)
    rep(i,110) rep(j,10010) dp[i][j]=INF;
    dp[0][0]=0; //選ばないで成り立つのは和0のみ

    rep(i,n){
        rep(sum,A+1){
            dp[i+1][sum]=min(dp[i+1][sum],dp[i][sum]);
            if(sum-a[i]>=0) dp[i+1][sum]=min(dp[i][sum-a[i]]+1,dp[i+1][sum]);
        }
    }
    if(dp[n][A]==INF) cout<<-1<<endl;
    else cout<<dp[n][A]<<endl;

    return 0;
}
