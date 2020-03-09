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
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :warning: output_option.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/output_option.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-11 14:06:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "output_option.cpp"
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

```
{% endraw %}

<a href="../index.html">Back to top page</a>

