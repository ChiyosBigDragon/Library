// bit演算もろもろ
#include <bits/stdc++.h>
using namespace std;

// 最上位bit
unsigned long long MSB(unsigned long long n){
    n=n&0xFFFFFFFF00000000?n&0xFFFFFFFF00000000:n;
    n=n&0xFFFF0000FFFF0000?n&0xFFFF0000FFFF0000:n;
    n=n&0xFF00FF00FF00FF00?n&0xFF00FF00FF00FF00:n;
    n=n&0xF0F0F0F0F0F0F0F0?n&0xF0F0F0F0F0F0F0F0:n;
    n=n&0xCCCCCCCCCCCCCCCC?n&0xCCCCCCCCCCCCCCCC:n;
    n=n&0xAAAAAAAAAAAAAAAA?n&0xAAAAAAAAAAAAAAAA:n;
    return n;
}
// bitが何本立っているか
long long cntbit(long long n){
    n=(n&0x5555555555555555)+((n&0xAAAAAAAAAAAAAAAA)>>1);
    n=(n&0x3333333333333333)+((n&0xCCCCCCCCCCCCCCCC)>>2);
    n=(n&0x0F0F0F0F0F0F0F0F)+((n&0xF0F0F0F0F0F0F0F0)>>4);
    n=(n&0x00FF00FF00FF00FF)+((n&0xFF00FF00FF00FF00)>>8);
    n=(n&0x0000FFFF0000FFFF)+((n&0xFFFF0000FFFF0000)>>16);
    n=(n&0x00000000FFFFFFFF)+((n&0xFFFFFFFF00000000)>>32);
    return n;
}
