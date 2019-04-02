// コドフェス2014
// n個の高さ範囲とm個の高さ点が与えられて、できるだけ対応させる
// 高さを下から見て範囲の下限が来たらキューに上限を入れる。
// 点が来たら条件を満たすまでキューから取り出して最上と対応させる。
// 実装がいやらしい

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1e9,MOD=1e9+7;

int main(){
    const int MAX=114514;
    int n,m; cin>>n>>m;
    vector<int> range[MAX];
    rep(i,n){
        int x,y; cin>>x>>y;
        range[x].push_back(y);
    }
    int pillow[MAX]={};
    rep(i,m){
        int x; cin>>x;
        pillow[x]++;
    }

    int ans=0;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int height=1;height<MAX;height++){
        for(auto i:range[height]){
            q.push(i);
            // cout<<"push"<<i<<endl;
        }
        // cout<<pillow[height]<<endl;
        while(pillow[height]&&q.size()){
            int a=q.top();
            // cout<<a<<endl;
            if(a>=height){
                // cout<<"pop"<<a<<endl;
                ans++;
                q.pop();
                pillow[height]--;
            }else{
                // cout<<"hu"<<endl;
                while(q.top()<height){
                    q.pop();
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
