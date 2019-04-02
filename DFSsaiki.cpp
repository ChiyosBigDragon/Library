// 深さ優先探索(再帰)
// 辞書順最小経路を求める
// 計算量O(E)

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int INF=INT_MAX,MOD=1e9+7;

int n,m,ans=0;
int a[10][10]={};
bool visited[10];

int dfs(int now){
	visited[now]=1;
	bool all=1;
	rep(i,n){
		if(!visited[i]) all=0;
	}
	if(all) return ++ans;
	rep(i,n){
		if(visited[i]) continue;
		if(!a[now][i]) continue;
		dfs(i);
		visited[i]=0;
	}
	return ans;
}

int main(){
	cin>>n>>m;
	rep(i,m){
		int b,c; cin>>b>>c;
		a[b-1][c-1]=a[c-1][b-1]=1;
	}
	rep(i,n) visited[i]=0;
	cout<<dfs(0)<<endl;
	return 0;
}
