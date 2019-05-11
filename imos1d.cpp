#include <bits/stdc++.h>
using namespace std;

template<class T>
struct imos1d{
    vector<T> board;
    imos1d(int n)
        :board(n+2)
    {}
    // 矩形加算
    void add(pair<int,int> lr,T z){
        int l=lr.first,r=lr.second;
        board[l]+=z;
        board[r+1]-=z;
    }
    // 累積和
    void build(){
        for(int i=1;i<(int)board.size();i++){
            board[i]+=board[i-1];
        }
    }
    // 値取得
    T get(int i){
        return board[i];
    }
    // debug
    void debug(){
        for(int i=1;i<(int)board.size()-1;i++){
            cout<<board[i]<<" ";
        }
        cout<<endl;
    }
};
// verify
int main(){
    return 0;
}
