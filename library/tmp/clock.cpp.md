---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: tmp/clock.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#fa816edb83e95bf0c8da580bdfd491ef">tmp</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/clock.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 19:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/clock.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

