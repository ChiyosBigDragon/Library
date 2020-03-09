// 幅優先探索
// 最短経路を求める
// 計算量O(E)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX;

int main(){
    //初期化
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    queue<pair<int,int>> q;
    int h,w,sy,sx,gy,gx; //盤面,スタート,ゴール
    cin>>h>>w>>sy>>sx>>gy>>gx;
    //sy--; sx--; gy--; gx--;
    char c[h][w]; int d[h][w]; //d[i][j]:=(j,i)までの最短経路
    rep(i,h){
        rep(j,w){
            cin>>c[i][j]; d[i][j]=INF;
        }
    }
    d[sy][sx]=0;
    q.push(make_pair(sy,sx));

    //実行
    while(q.size()){
        pair<int,int> p=q.front(); //キューの先頭を取り出す
        q.pop(); //取り出したら削除
        int prev=d[p.first][p.second]; //一手前の手数prev
        rep(i,4){ //4方向探索
            int cy=p.first+dy[i];
            int cx=p.second+dx[i];
            if(0<=cy&&cy<h&&0<=cx&&cx<w){ //範囲外取得キケン
                if(c[cy][cx]=='.' and d[cy][cx]==INF){ //通行可能かつ未到達
                    d[cy][cx]=prev+1;
                    q.push(make_pair(cy,cx));
                }
            }
        }
    }
    cout<<d[gy][gx]<<endl;
    return 0;
}
