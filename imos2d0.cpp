#include <bits/stdc++.h>
using namespace std;

template<class T>
struct imos2d{
    vector<vector<T>> board;
    imos2d(int w,int h)
        :board(w+2,vector<int>(h+2,0))
    {}
    // 矩形加算
    void add(pair<int,int> xy1,pair<int,int> xy2,T z){
        int x1=xy1.first,y1=xy1.second;
        int x2=xy2.first,y2=xy2.second;
        board[x1][y1]+=z;
        board[x1][y2+1]-=z;
        board[x2+1][y1]-=z;
        board[x2+1][y2+1]+=z;
    }
    // 累積和
    void build(){
        for(int x=1;x<(int)board.size();x++){
            for(int y=1;y<(int)board[0].size();y++){
                board[x][y]+=board[x][y-1];
            }
        }
        for(int x=1;x<(int)board.size();x++){
            for(int y=1;y<(int)board[0].size();y++){
                board[x][y]+=board[x-1][y];
            }
        }
    }
    // 値取得
    T get(int x,int y){
        return board[x][y];
    }
    // debug
    void debug(){
        for(int x=1;x<(int)board.size()-1;x++){
            for(int y=1;y<(int)board[0].size()-1;y++){
                cout<<board[x][y]<<" ";
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
        imos.add({1,r},{l,n},1);
    }
    imos.build();
    while(q--){
        int l,r; cin>>l>>r;
        cout<<imos.get(l,r)<<endl;
    }
    return 0;
}
