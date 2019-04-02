// combination
// Pascal's triangle

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

const int MAX=1000;
const int MOD=9;
long long COM[MAX][MAX];
// テーブル作成
void COMinit(){
    memset(COM,0,sizeof(COM));
    COM[0][0]=1;
    for(int i=1;i<MAX;i++){
        COM[i][0]=1;
        for(int j=1;j<MAX;j++){
            COM[i][j]=(COM[i-1][j-1]+COM[i-1][j])%MOD;
        }
    }
}
int main(){
    COMinit();
    cout<<COM[10][3]<<endl;
}
