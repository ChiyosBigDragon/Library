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
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :warning: tmp/Math/Matrix/verify/ABC009_D.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#21cace77429b0eae219f5b50e59adfaf">tmp/Math/Matrix/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/Math/Matrix/verify/ABC009_D.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 19:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// Matrixクラスに以下を追加-------------------------------
// XOR
Matrix &operator ^=(const Matrix &_mat){
    int h=(*this).height(),w=(*this).width();
    assert(h==_mat.height()&&w==_mat.width());
    for(int y=0;y<h;y++){
        for(int x=0;x<w;x++){
            (*this)[y][x]^=_mat[y][x];
        }
    }
    return (*this);
}
Matrix operator ^(const Matrix &_mat){
    return (*this)^=_mat;
}
// AND
Matrix &operator &=(const Matrix &_mat){
    int h=(*this).height(),w=(*this).width();
    int _h=_mat.height(),_w=_mat.width();
    assert(w==_h);
    vector<vector<T>> ret(h,vector<T>(_w,0));
    for(int y=0;y<h;y++){
        for(int x=0;x<_w;x++){
            for(int k=0;k<w;k++){
                ret[y][x]^=mat[y][k]&_mat[k][x];
            }
        }
    }
    mat=ret;
    return (*this);
}
Matrix operator &(const Matrix &_mat){
    return (*this)&=_mat;
}
// AND累乗
Matrix powand(long long n){
    Matrix ret=I((*this).height(),UINT_MAX);
    while(n>0){
        if(n&1) ret&=(*this);
        (*this)&=(*this);
        n>>=1ll;
    }
    (*this)=ret;
    return (*this);
}
// ここまで------------------------------------------------

int main(){
    int k,m; cin>>k>>m;
    unsigned int a[k];
    for(int i=0;i<k;i++) cin>>a[i];
    Matrix<unsigned int> mat(k,k);
    for(int i=0;i<k;i++) cin>>mat[0][i];
    for(int i=1;i<k;i++) mat[i][i-1]=UINT_MAX;
    if(m<k){
        cout<<a[m-1]<<endl;
        return 0;
    }
    mat.powand(m-k);
    long long ans=0;
    for(int i=0;i<k;i++){
        ans^=(mat[0][i]&a[k-1-i]);
    }
    cout<<ans<<endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/Math/Matrix/verify/ABC009_D.cpp"
// Matrixクラスに以下を追加-------------------------------
// XOR
Matrix &operator ^=(const Matrix &_mat){
    int h=(*this).height(),w=(*this).width();
    assert(h==_mat.height()&&w==_mat.width());
    for(int y=0;y<h;y++){
        for(int x=0;x<w;x++){
            (*this)[y][x]^=_mat[y][x];
        }
    }
    return (*this);
}
Matrix operator ^(const Matrix &_mat){
    return (*this)^=_mat;
}
// AND
Matrix &operator &=(const Matrix &_mat){
    int h=(*this).height(),w=(*this).width();
    int _h=_mat.height(),_w=_mat.width();
    assert(w==_h);
    vector<vector<T>> ret(h,vector<T>(_w,0));
    for(int y=0;y<h;y++){
        for(int x=0;x<_w;x++){
            for(int k=0;k<w;k++){
                ret[y][x]^=mat[y][k]&_mat[k][x];
            }
        }
    }
    mat=ret;
    return (*this);
}
Matrix operator &(const Matrix &_mat){
    return (*this)&=_mat;
}
// AND累乗
Matrix powand(long long n){
    Matrix ret=I((*this).height(),UINT_MAX);
    while(n>0){
        if(n&1) ret&=(*this);
        (*this)&=(*this);
        n>>=1ll;
    }
    (*this)=ret;
    return (*this);
}
// ここまで------------------------------------------------

int main(){
    int k,m; cin>>k>>m;
    unsigned int a[k];
    for(int i=0;i<k;i++) cin>>a[i];
    Matrix<unsigned int> mat(k,k);
    for(int i=0;i<k;i++) cin>>mat[0][i];
    for(int i=1;i<k;i++) mat[i][i-1]=UINT_MAX;
    if(m<k){
        cout<<a[m-1]<<endl;
        return 0;
    }
    mat.powand(m-k);
    long long ans=0;
    for(int i=0;i<k;i++){
        ans^=(mat[0][i]&a[k-1-i]);
    }
    cout<<ans<<endl;
    return 0;
}

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

