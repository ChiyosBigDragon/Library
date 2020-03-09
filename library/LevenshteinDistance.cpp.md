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


# :warning: LevenshteinDistance.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/LevenshteinDistance.cpp">View this file on GitHub</a>
    - Last commit date: 2019-05-11 14:06:18+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

struct LevenshteinDistance{
    const int INF=1145141919;
    const int costInsert,costErase,costReplace;
    LevenshteinDistance(int i,int e,int r):
        costInsert(i),costErase(e),costReplace(r)
        {}
    int distance(string& s1,string& s2){
        int n1=s1.size(),n2=s2.size();
        // dp[i][j]:=s1のi文字目までとs2のj文字目までの距離
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,INF));
        for(int i=0;i<=max(n1,n2);i++){
            if(i<=n1) dp[i][0]=i;
            if(i<=n2) dp[0][i]=i;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                dp[i][j]=min(dp[i][j],dp[i-1][j]+costInsert);
                dp[i][j]=min(dp[i][j],dp[i][j-1]+costErase);
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s1[i-1]==s2[j-1]?0:costReplace));
            }
        }
        return dp[n1][n2];
    }
};
// verify
// https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_E
int main(){
    LevenshteinDistance ld(1,1,1);
    string s1,s2; cin>>s1>>s2;
    cout<<ld.distance(s1,s2)<<endl;
    return 0;
}
// https://yukicoder.me/problems/no/225
// int main(){
//     LevenshteinDistance ld(1,1,1);
//     int n,m; cin>>n>>m;
//     string s1,s2; cin>>s1>>s2;
//     cout<<ld.distance(s1,s2)<<endl;
//     return 0;
// }

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "LevenshteinDistance.cpp"
#include <bits/stdc++.h>
using namespace std;

struct LevenshteinDistance{
    const int INF=1145141919;
    const int costInsert,costErase,costReplace;
    LevenshteinDistance(int i,int e,int r):
        costInsert(i),costErase(e),costReplace(r)
        {}
    int distance(string& s1,string& s2){
        int n1=s1.size(),n2=s2.size();
        // dp[i][j]:=s1のi文字目までとs2のj文字目までの距離
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,INF));
        for(int i=0;i<=max(n1,n2);i++){
            if(i<=n1) dp[i][0]=i;
            if(i<=n2) dp[0][i]=i;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                dp[i][j]=min(dp[i][j],dp[i-1][j]+costInsert);
                dp[i][j]=min(dp[i][j],dp[i][j-1]+costErase);
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s1[i-1]==s2[j-1]?0:costReplace));
            }
        }
        return dp[n1][n2];
    }
};
// verify
// https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_E
int main(){
    LevenshteinDistance ld(1,1,1);
    string s1,s2; cin>>s1>>s2;
    cout<<ld.distance(s1,s2)<<endl;
    return 0;
}
// https://yukicoder.me/problems/no/225
// int main(){
//     LevenshteinDistance ld(1,1,1);
//     int n,m; cin>>n>>m;
//     string s1,s2; cin>>s1>>s2;
//     cout<<ld.distance(s1,s2)<<endl;
//     return 0;
// }

```
{% endraw %}

<a href="../index.html">Back to top page</a>

