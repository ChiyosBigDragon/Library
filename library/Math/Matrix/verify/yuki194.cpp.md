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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :warning: Math/Matrix/verify/yuki194.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#57794736f63a9d595e4dbfe437025a75">Math/Matrix/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Math/Matrix/verify/yuki194.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-11 14:06:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
int main(){
    const int MOD=1e9+7;
    using mint=ModInt<MOD>;
    long long n,k; cin>>n>>k;
    // はずれ
    if(k<=n){
        mint f,sum=0;
        for(int i=1;i<=k;i++){
            cin>>f;
            sum+=f;
        }
        cout<<f<<" "<<sum<<endl;
        return 0;
    }
    // テスト1
    if(n>30){
        mint f[k+1],s[k+1];
        for(int i=1;i<=n;i++){
            cin>>f[i];
            s[i]=f[i]+s[i-1];
        }
        for(int i=n+1;i<=k;i++){
            f[i]=s[i-1]-s[i-n-1];
            s[i]=f[i]+s[i-1];
        }
        cout<<f[k]<<" "<<s[k]<<endl;
        return 0;
    }
    // テスト2
    mint f[n+1],s[n+1];
    for(int i=1;i<=n;i++){
        cin>>f[i];
        s[i]=f[i]+s[i-1];
    }
    Matrix<mint> mat(n+1,n+1);
    mat[0][0]=2;
    mat[0][n]=-1;
    for(int y=1;y<n+1;y++){
        mat[y][y-1]=1;
    }
    mat.pow(k-n);
    mint sk,sk1;
    for(int x=0;x<n+1;x++){
        sk+=mat[0][x]*s[n-x];
        sk1+=mat[1][x]*s[n-x];
    }
    cout<<sk-sk1<<" "<<sk<<endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Math/Matrix/verify/yuki194.cpp"
int main(){
    const int MOD=1e9+7;
    using mint=ModInt<MOD>;
    long long n,k; cin>>n>>k;
    // はずれ
    if(k<=n){
        mint f,sum=0;
        for(int i=1;i<=k;i++){
            cin>>f;
            sum+=f;
        }
        cout<<f<<" "<<sum<<endl;
        return 0;
    }
    // テスト1
    if(n>30){
        mint f[k+1],s[k+1];
        for(int i=1;i<=n;i++){
            cin>>f[i];
            s[i]=f[i]+s[i-1];
        }
        for(int i=n+1;i<=k;i++){
            f[i]=s[i-1]-s[i-n-1];
            s[i]=f[i]+s[i-1];
        }
        cout<<f[k]<<" "<<s[k]<<endl;
        return 0;
    }
    // テスト2
    mint f[n+1],s[n+1];
    for(int i=1;i<=n;i++){
        cin>>f[i];
        s[i]=f[i]+s[i-1];
    }
    Matrix<mint> mat(n+1,n+1);
    mat[0][0]=2;
    mat[0][n]=-1;
    for(int y=1;y<n+1;y++){
        mat[y][y-1]=1;
    }
    mat.pow(k-n);
    mint sk,sk1;
    for(int x=0;x<n+1;x++){
        sk+=mat[0][x]*s[n-x];
        sk1+=mat[1][x]*s[n-x];
    }
    cout<<sk-sk1<<" "<<sk<<endl;
    return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

