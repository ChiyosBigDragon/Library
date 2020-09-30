---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp
    - https://atcoder.jp/contests/abc120/tasks/abc120_d
    - https://atcoder.jp/contests/atc001/tasks/unionfind_a
  bundledCode: "#line 1 \"tmp/UnionFind.cpp\"\n// root\u53D6\u308B\u3068\u304D\u306F\
    \u3061\u3083\u3093\u3068root()\u3057\u3066\u304F\u3060\u3055\u3044\uFF0E\r\n//\
    \ par[]\u3067\u53D6\u5F97\u3067\u304D\u308B\u306E\u306F\u5727\u7E2E\u6E08\u306E\
    \u3068\u304D\u306E\u307F\u3067\u3059\r\n\r\n#include <bits/stdc++.h>\r\n#define\
    \ rep(i,n) for(int i=0;i<n;i++)\r\n#define all(x) (x).begin(),(x).end()\r\nusing\
    \ namespace std;\r\nconst int INF=1145141919,MOD=1e9+7;\r\nconst long long LINF=8931145141919364364,LMOD=998244353;\r\
    \ninline long long mod(long long n,long long m){return(n%m+m)%m;}\r\n// const\
    \ int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};\r\n\r\nstruct UnionFind{\r\
    \n    // \u9802\u70B9\u6570(1-indexed)\r\n    const int V;\r\n    // par[x]:=x\u306E\
    root\r\n    vector<int> par;\r\n    // sz[x]:=x\u3092\u542B\u3080\u96C6\u5408\u306E\
    \u30B5\u30A4\u30BA\r\n    vector<int> sz;\r\n    UnionFind(const int V):V(V){\r\
    \n        par.resize(V+1);\r\n        for(int i=0;i<=V;i++) par[i]=i;\r\n    \
    \    sz.resize(V+1,1);\r\n    }\r\n    bool unite(int x,int y){\r\n        x=root(x),y=root(y);\r\
    \n        if(same(x,y)) return false;\r\n        if(y<x) swap(x,y);\r\n      \
    \  par[y]=x;\r\n        sz[x]+=sz[y];\r\n        return true;\r\n    }\r\n   \
    \ int root(int x){\r\n    \tif(par[x]==x) return x; // x\u306Froot\r\n    \treturn\
    \ (par[x]=root(par[x])); // x\u306E\u89AA\u306Eroot\r\n    }\r\n    bool same(int\
    \ x,int y){\r\n    \treturn (root(x)==root(y));\r\n    }\r\n    int size(int x){\r\
    \n        return sz[root(x)];\r\n    }\r\n};\r\n\r\n// verify\r\n// https://atcoder.jp/contests/atc001/tasks/unionfind_a\r\
    \n// int main(){\r\n//     int n,q; cin>>n>>q;\r\n//     UnionFind uf(n);\r\n\
    //     while(q--){\r\n//         int p,a,b; cin>>p>>a>>b;\r\n//         if(p==0)\
    \ uf.unite(a,b);\r\n//         else cout<<(uf.same(a,b)?\"Yes\":\"No\")<<endl;\r\
    \n//     }\r\n//     return 0;\r\n// }\r\n// https://atcoder.jp/contests/abc120/tasks/abc120_d\r\
    \n// int main(){\r\n//     long long n,m; cin>>n>>m;\r\n//     UnionFind uf(n);\r\
    \n//     long long a[m],b[m],ans[m];\r\n//     rep(i,m) cin>>a[i]>>b[i];\r\n//\
    \     ans[m-1]=n*(n-1)/2;\r\n//     for(int q=m-2;q>=0;q--){\r\n//         ans[q]=ans[q+1];\r\
    \n//         if(!uf.same(a[q+1],b[q+1])) ans[q]-=(long long)uf.size(a[q+1])*(long\
    \ long)uf.size(b[q+1]);\r\n//         uf.unite(a[q+1],b[q+1]);\r\n//     }\r\n\
    //     rep(q,m) cout<<ans[q]<<endl;\r\n//     return 0;\r\n// }\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp\r\
    \n// int main(){\r\n//     int n,q; cin>>n>>q;\r\n//     UnionFind uf(n);\r\n\
    //     while(q--){\r\n//         int com,x,y; cin>>com>>x>>y;\r\n//         if(com==0)\
    \ uf.unite(x,y);\r\n//         else cout<<(uf.same(x,y)?1:0)<<endl;\r\n//    \
    \ }\r\n//     return 0;\r\n// }\r\n"
  code: "// root\u53D6\u308B\u3068\u304D\u306F\u3061\u3083\u3093\u3068root()\u3057\
    \u3066\u304F\u3060\u3055\u3044\uFF0E\r\n// par[]\u3067\u53D6\u5F97\u3067\u304D\
    \u308B\u306E\u306F\u5727\u7E2E\u6E08\u306E\u3068\u304D\u306E\u307F\u3067\u3059\
    \r\n\r\n#include <bits/stdc++.h>\r\n#define rep(i,n) for(int i=0;i<n;i++)\r\n\
    #define all(x) (x).begin(),(x).end()\r\nusing namespace std;\r\nconst int INF=1145141919,MOD=1e9+7;\r\
    \nconst long long LINF=8931145141919364364,LMOD=998244353;\r\ninline long long\
    \ mod(long long n,long long m){return(n%m+m)%m;}\r\n// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};\r\
    \n\r\nstruct UnionFind{\r\n    // \u9802\u70B9\u6570(1-indexed)\r\n    const int\
    \ V;\r\n    // par[x]:=x\u306Eroot\r\n    vector<int> par;\r\n    // sz[x]:=x\u3092\
    \u542B\u3080\u96C6\u5408\u306E\u30B5\u30A4\u30BA\r\n    vector<int> sz;\r\n  \
    \  UnionFind(const int V):V(V){\r\n        par.resize(V+1);\r\n        for(int\
    \ i=0;i<=V;i++) par[i]=i;\r\n        sz.resize(V+1,1);\r\n    }\r\n    bool unite(int\
    \ x,int y){\r\n        x=root(x),y=root(y);\r\n        if(same(x,y)) return false;\r\
    \n        if(y<x) swap(x,y);\r\n        par[y]=x;\r\n        sz[x]+=sz[y];\r\n\
    \        return true;\r\n    }\r\n    int root(int x){\r\n    \tif(par[x]==x)\
    \ return x; // x\u306Froot\r\n    \treturn (par[x]=root(par[x])); // x\u306E\u89AA\
    \u306Eroot\r\n    }\r\n    bool same(int x,int y){\r\n    \treturn (root(x)==root(y));\r\
    \n    }\r\n    int size(int x){\r\n        return sz[root(x)];\r\n    }\r\n};\r\
    \n\r\n// verify\r\n// https://atcoder.jp/contests/atc001/tasks/unionfind_a\r\n\
    // int main(){\r\n//     int n,q; cin>>n>>q;\r\n//     UnionFind uf(n);\r\n//\
    \     while(q--){\r\n//         int p,a,b; cin>>p>>a>>b;\r\n//         if(p==0)\
    \ uf.unite(a,b);\r\n//         else cout<<(uf.same(a,b)?\"Yes\":\"No\")<<endl;\r\
    \n//     }\r\n//     return 0;\r\n// }\r\n// https://atcoder.jp/contests/abc120/tasks/abc120_d\r\
    \n// int main(){\r\n//     long long n,m; cin>>n>>m;\r\n//     UnionFind uf(n);\r\
    \n//     long long a[m],b[m],ans[m];\r\n//     rep(i,m) cin>>a[i]>>b[i];\r\n//\
    \     ans[m-1]=n*(n-1)/2;\r\n//     for(int q=m-2;q>=0;q--){\r\n//         ans[q]=ans[q+1];\r\
    \n//         if(!uf.same(a[q+1],b[q+1])) ans[q]-=(long long)uf.size(a[q+1])*(long\
    \ long)uf.size(b[q+1]);\r\n//         uf.unite(a[q+1],b[q+1]);\r\n//     }\r\n\
    //     rep(q,m) cout<<ans[q]<<endl;\r\n//     return 0;\r\n// }\r\n// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp\r\
    \n// int main(){\r\n//     int n,q; cin>>n>>q;\r\n//     UnionFind uf(n);\r\n\
    //     while(q--){\r\n//         int com,x,y; cin>>com>>x>>y;\r\n//         if(com==0)\
    \ uf.unite(x,y);\r\n//         else cout<<(uf.same(x,y)?1:0)<<endl;\r\n//    \
    \ }\r\n//     return 0;\r\n// }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: tmp/UnionFind.cpp
  requiredBy: []
  timestamp: '2020-03-09 19:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tmp/UnionFind.cpp
layout: document
redirect_from:
- /library/tmp/UnionFind.cpp
- /library/tmp/UnionFind.cpp.html
title: tmp/UnionFind.cpp
---
