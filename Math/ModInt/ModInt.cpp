#include <bits/stdc++.h>
using namespace std;

using fint64 = int_fast64_t;
template<fint64 MOD>
struct ModInt{
    fint64 x;
    ModInt():x(0){}
    ModInt(fint64 x):
        x(x>=0?x%MOD:(MOD-(-x)%MOD)%MOD)
        {}
    // 負号
    ModInt operator -() const{
        return ModInt(-x);
    }
    // 加算
    ModInt &operator +=(const ModInt &rhs){
        x+=rhs.x;
        if(x>=MOD) x-=MOD;
        return (*this);
    }
    ModInt operator +(const ModInt &rhs) const{
        return ModInt(*this)+=rhs;
    }
    // 減算
    ModInt &operator -=(const ModInt &rhs){
        x+=MOD-rhs.x;
        if(x>=MOD) x-=MOD;
        return (*this);
    }
    ModInt operator -(const ModInt &rhs) const{
        return ModInt(*this)-=rhs;
    }
    // 乗算
    ModInt &operator *=(const ModInt &rhs){
        x*=rhs.x;
        if(x>=MOD) x%=MOD;
        return (*this);
    }
    ModInt operator *(const ModInt &rhs) const{
        return ModInt(*this)*=rhs;
    }
    // 除算
    ModInt &operator /=(const ModInt &rhs){
        (*this)*=rhs.inverse();
        return (*this);
    }
    ModInt operator /(const ModInt &rhs) const{
        return ModInt(*this)/=rhs;
    }
    // 等号
    bool operator ==(const ModInt &rhs){
        return x==rhs.x;
    }
    bool operator !=(const ModInt &rhs){
        return x!=rhs.x;
    }
    // 累乗
    ModInt pow(fint64 n){
        fint64 tmp=x;
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
        fint64 a=x,b=MOD,s=1,t=0;
        while(b>0){
            fint64 u=a/b;
            a-=u*b;
            s-=u*t;
            swap(a,b);
            swap(s,t);
        }
        return ModInt(s);
    }
    // 入出力
    friend istream &operator >>(istream &lhs,ModInt<MOD> &rhs){
        fint64 x; lhs>>x;
        rhs=ModInt<MOD>(x);
        return lhs;
    }
    friend ostream &operator <<(ostream &lhs,const ModInt<MOD> &rhs){
        return lhs<<rhs.x;
    }
};
