// とけいもんだい
#include <bits/stdc++.h>
using namespace std;

// 整数秒に対する針の角度比較
int degH(int h,int m,int s){
    return 3600*h+60*m+s;
}
int degM(int h,int m,int s){
    return 720*m+12*s;
}
int degS(int h,int m,int s){
    return 720*s;
}
// 表示を変更してstringで返す
string Uhr(int h,int m,int s){
    char out[16];
    sprintf(out,"%02d:%02d:%02d",h,m,s);
    return string(out);
}
int main(){
    int h=11,m=59,s=59;
    // cin>>h>>m>>s;
    // h%=12,m%=60,s%=60;
    printf("%02d:%02d:%02d\n",h,m,s);
    cout<<Uhr(h,m,s)<<endl;
    return 0;
}
