// 矩形指定には{左上},{右下}

#include <bits/stdc++.h>
using namespace std;

template<class T>
struct imos2d{
    vector<vector<T>> board;
    imos2d(int w,int h)
        :board(w+2,vector<int>(h+2,0))
    {}
    // 1点加算
    void add(pair<int,int> yx,T z){
        int y=yx.first,x=yx.second;
        board[y][x]+=z;
    }
    // 矩形加算
    void addrec(pair<int,int> yx1,pair<int,int> yx2,T z){
        int y1=yx1.first,x1=yx1.second;
        int y2=yx2.first,x2=yx2.second;
        board[y1][x1]+=z;
        board[y1][x2+1]-=z;
        board[y2+1][x1]-=z;
        board[y2+1][x2+1]+=z;
    }
    // 累積和
    void build(){
        for(int y=1;y<(int)board.size();y++){
            for(int x=1;x<(int)board[0].size();x++){
                board[y][x]+=board[y][x-1];
            }
        }
        for(int y=1;y<(int)board.size();y++){
            for(int x=1;x<(int)board[0].size();x++){
                board[y][x]+=board[y-1][x];
            }
        }
    }
    // 1点取得
    T get(pair<int,int> yx){
        int y=yx.first,x=yx.second;
        return board[y][x];
    }
    // 矩形取得
    T getrec(pair<int,int> yx1,pair<int,int> yx2){
        int y1=yx1.first,x1=yx1.second;
        int y2=yx2.first,x2=yx2.second;
        return board[y2][x2]-board[y2][x1-1]-board[y1-1][x2]+board[y1-1][x1-1];
    }
    // debug
    void debug(){
        for(int y=1;y<(int)board.size()-1;y++){
            for(int x=1;x<(int)board[0].size()-1;x++){
                cout<<board[y][x]<<" ";
            }
            cout<<endl;
        }
    }
};
// verify
// https://beta.atcoder.jp/contests/abc106/tasks/abc106_d
int main(){
    int n,m,q; cin>>n>>m>>q;
    imos2d<int> imos(n,n);
    while(m--){
        int l,r; cin>>l>>r;
        imos.addrec({1,r},{l,n},1);
    }
    imos.build();
    while(q--){
        int l,r; cin>>l>>r;
        cout<<imos.get({l,r})<<endl;
    }
    return 0;
}
// https://atcoder.jp/contests/abc005/tasks/abc005_4
// int main(){
//     int n; cin>>n;
//     imos2d<int> imos(n,n);
//     for(int y=1;y<=n;y++){
//         for(int x=1;x<=n;x++){
//             int d; cin>>d;
//             imos.add({y,x},d);
//         }
//     }
//     imos.build();
//     int ans[n*n+1]={};
//     for(int p=1;p<=n*n;p++){
//         ans[p]=ans[p-1];
//         for(int w=1;w<=p;w++){
//             int h=p/w;
//             for(int ky=1;ky+h-1<=n;ky++){
//                 for(int kx=1;kx+w-1<=n;kx++){
//                     ans[p]=max(ans[p],imos.getrec({ky,kx},{ky+h-1,kx+w-1}));
//                 }
//             }
//         }
//     }
//     int q; cin>>q;
//     while(q--){
//         int p; cin>>p;
//         cout<<ans[p]<<endl;
//     }
//     return 0;
// }
