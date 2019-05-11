// 二分探索
// key以上で「最小」となる要素のindexを返す
// また、keyが見つかった場合"find"を出力する
// 計算量O(logN)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

// 単調増加列a
vector<int> a={1,14,32,51,51,51,243,419,750,910};

// indexが条件を満たすか?
bool isOK(int index,int key){
    if(a[index]>=key) return true;
    else return false;
}

// 二分探索
int binary_search(int key){
	// key以上の値をとるindexは全てokとする
    int ng=-1; // aの左の範囲外は必ずng
    int ok=(int)a.size(); // aの右の範囲外は必ずok

    while (abs(ok-ng)>1) {
        int mid=(ok+ng)/2;
        if(isOK(mid,key)) ok=mid;
        else ng=mid;
    }
    return ok;
}

int main(){
	int key=51;
	int index=binary_search(key);
    cout<<index<<endl;
	if(a[index]==key) cout<<"find"<<endl;
	return 0;
}
