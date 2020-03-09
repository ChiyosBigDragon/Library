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


# :warning: tmp/Math/Matrix/Matrix.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#5a65a1effde5b0ea70629e489e28fe51">tmp/Math/Matrix</a>
* <a href="{{ site.github.repository_url }}/blob/master/tmp/Math/Matrix/Matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-09 19:28:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Matrix{
    vector<vector<T>> mat;
    Matrix(const int h,const int w):
        mat(h,vector<T>(w,0))
        {}
    Matrix(const vector<vector<T>> &G):
        mat(G)
        {}
    int height() const{
        return mat.size();
    }
    int width() const{
        return mat[0].size();
    }
    // 添字
    const vector<T> &operator[](int i) const{
        assert(0<=i&&i<(int)mat.size());
        return mat[i];
    }
    vector<T> &operator[](int i){
        assert(0<=i&&i<(int)mat.size());
        return mat[i];
    }
    // 単位元
    Matrix I(int n,T x){
        Matrix ret(n,n);
        for(int i=0;i<n;i++){
            ret[i][i]=x;
        }
        return ret;
    }
    // 加法
    Matrix &operator +=(const Matrix &_mat){
        int h=(*this).height(),w=(*this).width();
        assert(h==_mat.height()&&w==_mat.width());
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                (*this)[y][x]+=_mat[y][x];
            }
        }
        return (*this);
    }
    Matrix operator +(const Matrix &_mat) const{
        return Matrix(*this)+=_mat;
    }
    // 減法
    Matrix &operator -=(const Matrix &_mat){
        int h=(*this).height(),w=(*this).width();
        assert(h==_mat.height()&&w==_mat.width());
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                (*this)[y][x]-=_mat[y][x];
            }
        }
        return (*this);
    }
    Matrix operator -(const Matrix &_mat) const{
        return Matrix(*this)-=_mat;
    }
    // 乗法
    Matrix &operator *=(const Matrix &_mat){
        int h=(*this).height(),w=(*this).width();
        int _h=_mat.height(),_w=_mat.width();
        assert(w==_h);
        vector<vector<T>> ret(h,vector<T>(_w,0));
        for(int y=0;y<h;y++){
            for(int x=0;x<_w;x++){
                for(int k=0;k<w;k++){
                    ret[y][x]+=(*this)[y][k]*_mat[k][x];
                }
            }
        }
        mat=ret;
        return (*this);
    }
    Matrix operator *(const Matrix &_mat) const{
        return Matrix(*this)*=_mat;
    }
    // 冪乗
    Matrix pow(long long k){
        Matrix ret=I((*this).height(),1);
        while(k>0){
            if(k&1) ret*=(*this);
            (*this)*=(*this);
            k>>=1ll;
        }
        (*this)=ret;
        return (*this);
    }
    void debug(){
        int h=height(),w=width();
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                cout<<mat[y][x]<<(x==w-1?"\n":" ");
            }
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tmp/Math/Matrix/Matrix.cpp"
#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Matrix{
    vector<vector<T>> mat;
    Matrix(const int h,const int w):
        mat(h,vector<T>(w,0))
        {}
    Matrix(const vector<vector<T>> &G):
        mat(G)
        {}
    int height() const{
        return mat.size();
    }
    int width() const{
        return mat[0].size();
    }
    // 添字
    const vector<T> &operator[](int i) const{
        assert(0<=i&&i<(int)mat.size());
        return mat[i];
    }
    vector<T> &operator[](int i){
        assert(0<=i&&i<(int)mat.size());
        return mat[i];
    }
    // 単位元
    Matrix I(int n,T x){
        Matrix ret(n,n);
        for(int i=0;i<n;i++){
            ret[i][i]=x;
        }
        return ret;
    }
    // 加法
    Matrix &operator +=(const Matrix &_mat){
        int h=(*this).height(),w=(*this).width();
        assert(h==_mat.height()&&w==_mat.width());
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                (*this)[y][x]+=_mat[y][x];
            }
        }
        return (*this);
    }
    Matrix operator +(const Matrix &_mat) const{
        return Matrix(*this)+=_mat;
    }
    // 減法
    Matrix &operator -=(const Matrix &_mat){
        int h=(*this).height(),w=(*this).width();
        assert(h==_mat.height()&&w==_mat.width());
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                (*this)[y][x]-=_mat[y][x];
            }
        }
        return (*this);
    }
    Matrix operator -(const Matrix &_mat) const{
        return Matrix(*this)-=_mat;
    }
    // 乗法
    Matrix &operator *=(const Matrix &_mat){
        int h=(*this).height(),w=(*this).width();
        int _h=_mat.height(),_w=_mat.width();
        assert(w==_h);
        vector<vector<T>> ret(h,vector<T>(_w,0));
        for(int y=0;y<h;y++){
            for(int x=0;x<_w;x++){
                for(int k=0;k<w;k++){
                    ret[y][x]+=(*this)[y][k]*_mat[k][x];
                }
            }
        }
        mat=ret;
        return (*this);
    }
    Matrix operator *(const Matrix &_mat) const{
        return Matrix(*this)*=_mat;
    }
    // 冪乗
    Matrix pow(long long k){
        Matrix ret=I((*this).height(),1);
        while(k>0){
            if(k&1) ret*=(*this);
            (*this)*=(*this);
            k>>=1ll;
        }
        (*this)=ret;
        return (*this);
    }
    void debug(){
        int h=height(),w=width();
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                cout<<mat[y][x]<<(x==w-1?"\n":" ");
            }
        }
    }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

