#include <bits/stdc++.h>
using namespace std;
using u64 = uint_fast64_t;

template<u64 MOD>
struct ModInt{
    u64 x;
    ModInt():x(0){}
    ModInt(u64 x):
        x(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD)
        {}
    // 負号
    ModInt &operator -(){
        return ModInt(-x);
    }
    // 加算
    ModInt &operator +=(const ModInt &rhs){
        x+=rhs.x;
        if(x>=MOD) x-=MOD;
        return (*this);
    }
    ModInt &operator +(const ModInt &rhs){
        return (*this)+=rhs;
    }
    // 減算
    ModInt &operator -=(const ModInt &rhs){
        x+=MOD-rhs.x;
        if(x>=MOD) x-=MOD;
        return (*this);
    }
    ModInt &operator -(const ModInt &rhs){
        return (*this)-=rhs;
    }
    // 乗算
    ModInt &operator *=(const ModInt &rhs){
        x*=rhs.x;
        if(x>=MOD) x%=MOD;
        return (*this);
    }
    ModInt &operator *(const ModInt &rhs){
        return (*this)*=rhs;
    }
    // 除算
    ModInt &operator /=(const ModInt &rhs){
        (*this)*=rhs.inverse();
        return (*this);
    }
    ModInt &operator /(const ModInt &rhs){
        return (*this)/=rhs;
    }
    // 等号
    bool &operator ==(const ModInt &rhs){
        return x==rhs.x;
    }
    bool &operator !=(const ModInt &rhs){
        return x!=rhs.x;
    }
    // 累乗
    ModInt pow(u64 n){
        u64 tmp=x;
        x=1;
        while(n>0){
            if(n&1) x=x*tmp%MOD;
            tmp=tmp*tmp%MOD;
            n>>=1ll;
        }
        return (*this);
    }
    // 逆元
    ModInt inverse(){
        u64 a=x,b=MOD,s=1,t=0;
        while(b>0){
            u64 u=b/a;
            b-=u*a;
            t-=u*s;
            swap(a,b);
            swap(s,t);
        }
        return ModInt(s);
    }
    // 入出力
    friend istream &operator >>(istream &lhs,ModInt<MOD> &rhs){
        u64 x; lhs>>x;
        rhs=ModInt<MOD>(x);
        return lhs;
    }
    friend ostream &operator <<(ostream &lhs,const ModInt<MOD> &rhs){
        return lhs<<rhs.x;
    }
};
