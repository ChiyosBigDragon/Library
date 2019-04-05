#include <bits/stdc++.h>
using namespace std;

struct CombinationOnPascal{
    const int MAX=2010;
    const int MOD;
    vector<vector<int>> COM;
    vector<vector<int>> PER;
    CombinationOnPascal(const int MOD):
        MOD(MOD)
        {
            COM=vector<vector<int>>(MAX,vector<int>(MAX));
            PER=vector<vector<int>>(MAX,vector<int>(MAX));
            COM[0][0]=PER[0][0]=1;
            for(int i=1;i<MAX;i++){
                COM[i][0]=PER[i][0]=1;
                for(int j=1;j<MAX;j++){
                    COM[i][j]=(COM[i-1][j-1]+COM[i-1][j])%MOD;
                    PER[i][j]=PER[i][j-1]*(i-j+1)%MOD;
                }
            }
        }
    int C(int n,int r){
        if(n<0||r<0||n<r) return 0;
        return COM[n][r];
    }
    int P(int n,int r){
        if(n<0||r<0||n<r) return 0;
        return PER[n][r];
    }
    int H(int n,int r){
        if(r==0) return 1;
        return C(n+r-1,r);
    }
};
