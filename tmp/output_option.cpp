// 簡単に出力できる
// 対応:pair/vector/2次元vector

#include <bits/stdc++.h>
using namespace std;

// pair
template<typename T1,typename T2> ostream&operator<<(ostream&s,const pair<T1,T2>&p){return s<<"("<<p.first<<", "<<p.second<<")";}
// vector
template<typename T> ostream&operator<<(ostream&s,const vector<T>&v){
	int len=v.size();
	for(int i=0;i<len;++i){
		s<<v[i]; if(i<len-1) s<<"\t";
	}
	return s;
}
// 2 dimentional vector
template<typename T> ostream&operator<<(ostream&s,const vector<vector<T>>&vv){
	int len=vv.size();
	for(int i=0;i<len;++i){
		s<<vv[i]<<endl;
	}
	return s;
}

int main(){
	pair<int,int> p=make_pair(1,2);
	cout<<p<<endl;
	vector<int> x={1,2,4,5,6,12};
	vector<vector<int>> y={{1,2,4,5,6,12},{2,4,6,8,10,12}};
	cout<<x<<endl;
	cout<<y<<endl;
    return 0;
}
