#include <bits/stdc++.h>
using namespace std;
const int INF=1145141919;

struct LevenshteinDistance{
    const int costInsert,costErase,costReplace;
    LevenshteinDistance(int i,int e,int r):
        costInsert(i),costErase(e),costReplace(r)
        {}
    int distance(string& s1,string& s2){
        int n1=s1.size(),n2=s2.size();
        // dp[i][j]:=s1のi文字目までとs2のj文字目までの距離
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,INF));
        for(int i=0;i<=max(n1,n2);i++){
            if(i<=n1) dp[i][0]=i;
            if(i<=n2) dp[0][i]=i;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                dp[i][j]=min(dp[i][j],dp[i-1][j]+costInsert);
                dp[i][j]=min(dp[i][j],dp[i][j-1]+costErase);
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s1[i-1]==s2[j-1]?0:costReplace));
            }
        }
        return dp[n1][n2];
    }
};
// verify
// https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_E
int main(){
    LevenshteinDistance ld(1,1,1);
    string s1,s2; cin>>s1>>s2;
    cout<<ld.distance(s1,s2)<<endl;
    return 0;
}
// https://yukicoder.me/problems/no/225
// int main(){
//     LevenshteinDistance ld(1,1,1);
//     int n,m; cin>>n>>m;
//     string s1,s2; cin>>s1>>s2;
//     cout<<ld.distance(s1,s2)<<endl;
//     return 0;
// }
