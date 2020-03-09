#include <bits/stdc++.h>
using namespace std;

// BEGIN CUT HERE
template<size_t MAX>
struct Combination {
	constexpr int MAX = 5000010;
	const int MOD;
	vector<long long> FAC;
	vector<long long> INV;
	vector<long long> FAC_INV;
	Combination(const int MOD):
		MOD(MOD)
		{
			FAC=vector<long long>(MAX);
			INV=vector<long long>(MAX);
			FAC_INV=vector<long long>(MAX);
			FAC[0]=INV[1]=FAC_INV[0]=1;
			for(int i=1;i<MAX;i++){
				FAC[i]=FAC[i-1]*i%MOD;
				if(i>1) INV[i]=MOD-INV[MOD%i]*(MOD/i)%MOD;
				FAC_INV[i]=FAC_INV[i-1]*INV[i]%MOD;
			}
		}
	int C(int n,int r){
		if(n<0||r<0||n<r) return 0;
		return FAC[n]*FAC_INV[r]%MOD*FAC_INV[n-r]%MOD;
	}
	int P(int n,int r){
		if(n<0||r<0||n<r) return 0;
		return FAC[n]*FAC_INV[n-r]%MOD;
	}
	int H(int n,int r){
		if(r==0) return 1;
		return C(n+r-1,r);
	}
};
